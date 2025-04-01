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
        p.setCompletionTime(completionTime);
        int turnaroundTime = completionTime - p.getArrivalTime();
        int waitingTime = turnaroundTime - p.getBurstTime();

        p.setWaitingTime(waitingTime);
        p.setTurnaroundTime(turnaroundTime);
        currentTime = completionTime;
    }

    std::cout << "\nFCFS Scheduling Results:\n";
    for (const auto& p : processes) {
        p.displayProcessInfo();
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
        shortest->setCompletionTime(completionTime); 
        int turnaroundTime = completionTime - shortest->getArrivalTime();
        int waitingTime = turnaroundTime - shortest->getBurstTime();

        shortest->setWaitingTime(waitingTime);
        shortest->setTurnaroundTime(turnaroundTime);
        currentTime = completionTime;

        remainingProcesses.erase(std::remove(remainingProcesses.begin(), remainingProcesses.end(), shortest), remainingProcesses.end());
    }

    std::cout << "\nSJF Non-Preemptive Scheduling Results:\n";
    for (const auto& p : processes) {
        p.displayProcessInfo();
    }

    calculateMetrics(processes);
}

void sjfPreemptiveScheduling(std::vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0, completed = 0;

    std::vector<int> remainingTime(n);
    for (int i = 0; i < n; i++) {
        remainingTime[i] = processes[i].getBurstTime();
    }

    while (completed < n) {
        int shortest = -1;
        int minRemainingTime = std::numeric_limits<int>::max();

        for (int i = 0; i < n; i++) {
            if (processes[i].getArrivalTime() <= currentTime && remainingTime[i] > 0) {
                if (remainingTime[i] < minRemainingTime) {
                    minRemainingTime = remainingTime[i];
                    shortest = i;
                }
            }
        }

        if (shortest == -1) {
            currentTime++;
            continue;
        }

        remainingTime[shortest]--;

        if (remainingTime[shortest] == 0) {
            completed++;
            int completionTime = currentTime + 1;
            processes[shortest].setCompletionTime(completionTime);
            int turnaroundTime = completionTime - processes[shortest].getArrivalTime();
            int waitingTime = turnaroundTime - processes[shortest].getBurstTime();

            processes[shortest].setWaitingTime(waitingTime);
            processes[shortest].setTurnaroundTime(turnaroundTime);
        }

        currentTime++;
    }

    std::cout << "\nSJF Preemptive Scheduling Results:\n";
    for (const auto& p : processes) {
        p.displayProcessInfo();
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