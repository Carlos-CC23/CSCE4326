#include <iostream>
#include <vector>
#include "auth.h"
#include "Process.h"
#include "scheduling.h"

using namespace std;

int main() {
    // Boot-up message
    cout << "LAPTOP is booting up...\n";

    // User authentication
    if (authenticateUser()) {
        cout << "Successful. Welcome!\n";

        // Creating sample processes
        Process p1(1, 0, 10, 1, 100, false);
        Process p2(2, 2, 15, 2, 200, true);

        // Display initial process states
        cout << "\nProcess p1 initial state: " << p1.getStateString() << endl;
        p1.setState(ProcessState::READY);
        cout << "p1 state changed to: " << p1.getStateString() << endl;

        // Simulate execution: p1 runs for 3 time units
        p1.runProcess(3);
        cout << "p1 remaining time after 3 time units: " << p1.getRemainingTime() << endl;
        
        // Simulate further execution: p1 runs for 7 more time units.
        p1.runProcess(7);
        cout << "p1 state after finishing execution: " << p1.getStateString() << endl;

        // Display p2 details and simulate execution
        cout << "\nProcess p2 details:\n";
        p2.displayProcessInfo();
        p2.setState(ProcessState::READY);
        cout << "p2 state changed to: " << p2.getStateString() << endl;
        p2.runProcess(5);
        cout << "p2 remaining time after 5 time units: " << p2.getRemainingTime() << endl;

// Scheduling Section
        cout << "\n=== PROCESS SCHEDULING ===\n";

        // Creating a list of processes for scheduling
        vector<Process> processes = {
            Process(1, 0, 8, 1, 100, false),
            Process(2, 1, 4, 2, 200, true),
            Process(3, 2, 9, 3, 300, false),
            Process(4, 3, 5, 1, 150, true)
        };

        // Run scheduling algorithms
        cout << "\nExecuting FCFS Scheduling...\n";
        fcfsScheduling(processes);

        cout << "\nExecuting SJF Non-Preemptive Scheduling...\n";
        sjfNonPreemptiveScheduling(processes);

        cout << "\nExecuting SJF Preemptive Scheduling...\n";
        sjfPreemptiveScheduling(processes);

    } else {
        cout << "Failed. Try Again";
    }

    return 0;
}
