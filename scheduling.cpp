#include "scheduling.h"
#include <iostream>
#include <limits>
#include <algorithm> // For sorting

void fcfsScheduling(std::vector<Process>& processes) {
    int currentTime = 0;

    std::sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.getArrivalTime() < b.getArrivalTime();
    });

    for (auto& p : processes) {
        if (currentTime < p.getArrivalTime()) {
            currentTime = p.getArrivalTime();
        }
        int completionTime = currentTime + p.getBurstTime();
        int turnaroundTime = completionTime - p.getArrivalTime();
        int waitingTime = turnaroundTime - p.getBurstTime();

        p.setWaitingTime(waitingTime);  // Use an existing function
        currentTime = completionTime;
    }

    calculateMetrics(processes);
}

void sjfNonPreemptiveScheduling(std::vector<Process>& processes) {
    int currentTime = 0;
    std::vector<Process*> remainingProcesses;

    for (auto& p : processes) {
        remainingProcesses.push_back(&p);
    }

    while (!remainingProcesses.empty()) {
        Process* shortest = nullptr;

        for (auto* p : remainingProcesses) {
            if (p->getArrivalTime() <= currentTime) {
                if (!shortest || p->getBurstTime() < shortest->getBurstTime()) {
                    shortest = p;
                }
            }
        }

        if (!shortest) {
            currentTime++;
            continue;
        }

        int completionTime = currentTime + shortest->getBurstTime();
        int turnaroundTime = completionTime - shortest->getArrivalTime();
        int waitingTime = turnaroundTime - shortest->getBurstTime();

        shortest->setWaitingTime(waitingTime);
        currentTime = completionTime;

        remainingProcesses.erase(std::remove(remainingProcesses.begin(), remainingProcesses.end(), shortest), remainingProcesses.end());
    }

    calculateMetrics(processes);
}

void sjfPreemptiveScheduling(std::vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0, completed = 0;
    int minRemainingTime = std::numeric_limits<int>::max();
    int shortest = -1;
    bool found = false;

    std::vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].getBurstTime();
    }

    while (completed < n) {
        found = false;
        for (int i = 0; i < n; i++) {
            if (processes[i].getArrivalTime() <= currentTime && remainingTime[i] > 0) {
                if (remainingTime[i] < minRemainingTime) {
                    minRemainingTime = remainingTime[i];
                    shortest = i;
                    found = true;
                }
            }
        }

        if (!found) {
            currentTime++;
            continue;
        }

        remainingTime[shortest]--;
        minRemainingTime = remainingTime[shortest];

        if (remainingTime[shortest] == 0) {
            completed++;
            minRemainingTime = std::numeric_limits<int>::max();
            int completionTime = currentTime + 1;
            int turnaroundTime = completionTime - processes[shortest].getArrivalTime();
            int waitingTime = turnaroundTime - processes[shortest].getBurstTime();

            processes[shortest].setWaitingTime(waitingTime);
        }

        currentTime++;
    }

    calculateMetrics(processes);
}

void calculateMetrics(std::vector<Process>& processes) {
    double totalTurnaroundTime = 0, totalWaitingTime = 0;

    for (auto& p : processes) {
        int turnaroundTime = p.getWaitingTime() + p.getBurstTime();
        int waitingTime = p.getWaitingTime();

        totalTurnaroundTime += turnaroundTime;
        totalWaitingTime += waitingTime;
    }

    std::cout << "Average Turnaround Time: " << totalTurnaroundTime / processes.size() << std::endl;
    std::cout << "Average Waiting Time: " << totalWaitingTime / processes.size() << std::endl;
}
//g++ main.cpp auth.cpp Process.cpp scheduling.cpp -o os_simulator.exe
//.\os_simulator.exe
