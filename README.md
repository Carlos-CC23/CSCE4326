# CSCE4326
Project for OS Spring 2025

-Building a Basic Operating System

-Team Members: Carlos Chacon & Dante Trevino

## Description
This project simulates an operating system's CPU scheduling (FCFS, SJF Non-Preemptive, SJF Preemptive) and virtual memory management using per-process page tables and virtual-to-physical address translation.

## Link to GitHub Repository
https://github.com/Carlos-CC23/CSCE4326

## Features
- User Authentication
- Process State Transitions
- Scheduling Algorithms:
  - First-Come-First-Serve (FCFS)
  - Shortest Job First (Non-Preemptive & Preemptive)
- Virtual Memory:
  - Page table per process
  - Address translation with page mapping
  - Page fault simulation (basic)

## How to Compile

-When using g++ , follows these steps to compile & run program:
-
type -> g++ main.cpp auth.cpp Process.cpp scheduling.cpp -o os_simulator.exe
  
  then type -> .\os_simulator.exe

  
## Log in:
-Username: ADMIN
-Password; OSisthebest23

## Sample configuration files
PS C:\Users\USER\OS\CSCE4326> g++ -std=c++17 main.cpp auth.cpp Process.cpp scheduling.cpp -o os_simulator.exe
PS C:\Users\USER\OS\CSCE4326> .\os_simulator.exe           
LAPTOP is booting up...
Enter username: ADMIN
Enter password: OSisthebest23

This authetication is correct. Hello, ADMIN!

Successful. Welcome!

Process p1 initial state: NEW
p1 state changed to: READY
p1 remaining time after 3 time units: 7
p1 state after finishing execution: TERMINATED

Process p2 details:
Process ID: 2 | State: NEW | Arrival Time: 2 | Burst Time: 15 | Completion Time: 0 | Remaining Time: 15 | Priority: 2 | Memory: 200 | I/O Required: Yes | Waiting Time: 0 | Turnaround Time: 0
Mapped Pages: [VPage 0 -> Frame 2] [VPage 1 -> Frame 3] 
p2 state changed to: READY
p2 remaining time after 5 time units: 10

=== VIRTUAL TO PHYSICAL ADDRESS TRANSLATION ===
p1: Virtual address 5000 -> Physical address 5000
p2: Virtual address 1000 -> Physical address 9192

=== PAGE TABLE INFO ===
Process p1:
Process ID: 1 | State: TERMINATED | Arrival Time: 0 | Burst Time: 10 | Completion Time: 0 | Remaining Time: 0 | Priority: 1 | Memory: 100 | I/O Required: No | Waiting Time: 0 | Turnaround Time: 0
Mapped Pages: [VPage 0 -> Frame 0] [VPage 1 -> Frame 1]    

Process p2:
Process ID: 2 | State: RUNNING | Arrival Time: 2 | Burst Time: 15 | Completion Time: 0 | Remaining Time: 10 | Priority: 2 | Memory: 200 | I/O Required: Yes | Waiting Time: 0 | Turnaround Time: 0
Mapped Pages: [VPage 0 -> Frame 2] [VPage 1 -> Frame 3]    

=== PROCESS SCHEDULING ===

Executing FCFS Scheduling...

FCFS Scheduling Results:
Process ID: 1 | State: NEW | Arrival Time: 0 | Burst Time: 8 | Completion Time: 8 | Remaining Time: 8 | Priority: 1 | Memory: 100 | I/O Required: No | Waiting Time: 0 | Turnaround Time: 8
Mapped Pages:
Process ID: 2 | State: NEW | Arrival Time: 1 | Burst Time: 4 | Completion Time: 12 | Remaining Time: 4 | Priority: 2 | Memory: 200 | I/O Required: Yes | Waiting Time: 7 | Turnaround Time: 11
Mapped Pages:
Process ID: 3 | State: NEW | Arrival Time: 2 | Burst Time: 9 | Completion Time: 21 | Remaining Time: 9 | Priority: 3 | Memory: 300 | I/O Required: No | Waiting Time: 10 | Turnaround Time: 19
Mapped Pages:
Process ID: 4 | State: NEW | Arrival Time: 3 | Burst Time: 5 | Completion Time: 26 | Remaining Time: 5 | Priority: 1 | Memory: 150 | I/O Required: Yes | Waiting Time: 18 | Turnaround Time: 23
Mapped Pages:
Average Turnaround Time: 15.25
Average Waiting Time: 8.75

Executing SJF Non-Preemptive Scheduling...

SJF Non-Preemptive Scheduling Results:
Process ID: 1 | State: NEW | Arrival Time: 0 | Burst Time: 8 | Completion Time: 8 | Remaining Time: 8 | Priority: 1 | Memory: 100 | I/O Required: No | Waiting Time: 0 | Turnaround Time: 8
Mapped Pages:
Process ID: 2 | State: NEW | Arrival Time: 1 | Burst Time: 4 | Completion Time: 12 | Remaining Time: 4 | Priority: 2 | Memory: 200 | I/O Required: Yes | Waiting Time: 7 | Turnaround Time: 11
Mapped Pages:
Process ID: 3 | State: NEW | Arrival Time: 2 | Burst Time: 9 | Completion Time: 26 | Remaining Time: 9 | Priority: 3 | Memory: 300 | I/O Required: No | Waiting Time: 15 | Turnaround Time: 24
Mapped Pages:
Process ID: 4 | State: NEW | Arrival Time: 3 | Burst Time: 5 | Completion Time: 17 | Remaining Time: 5 | Priority: 1 | Memory: 150 | I/O Required: Yes | Waiting Time: 9 | Turnaround Time: 14
Mapped Pages:
Average Turnaround Time: 14.25
Average Waiting Time: 7.75

Executing SJF Preemptive Scheduling...

SJF Preemptive Scheduling Results:
Process ID: 1 | State: NEW | Arrival Time: 0 | Burst Time: 8 | Completion Time: 17 | Remaining Time: 8 | Priority: 1 | Memory: 100 | I/O Required: No | Waiting Time: 9 | Turnaround Time: 17
Mapped Pages:
Process ID: 2 | State: NEW | Arrival Time: 1 | Burst Time: 4 | Completion Time: 5 | Remaining Time: 4 | Priority: 2 | Memory: 200 | I/O Required: Yes | Waiting Time: 0 | Turnaround Time: 4
Mapped Pages:
Process ID: 3 | State: NEW | Arrival Time: 2 | Burst Time: 9 | Completion Time: 26 | Remaining Time: 9 | Priority: 3 | Memory: 300 | I/O Required: No | Waiting Time: 15 | Turnaround Time: 24
Mapped Pages:
Process ID: 4 | State: NEW | Arrival Time: 3 | Burst Time: 5 | Completion Time: 10 | Remaining Time: 5 | Priority: 1 |9 | Completion Time: 26 | Remaining Time: 9 | Priority: 3 | Memory: 300 | I/O Required: No | Waiting Time: 15 | Turnaround Time: 24
Mapped Pages:
Process ID: 4 | State: NEW | Arrival Time: 3 | Burst Time: 5 | Completion Time: 10 | Remaining Time: 5 | Priority: 1 |ound Time: 24
Mapped Pages:
Process ID: 4 | State: NEW | Arrival Time: 3 | Burst Time: 5 | Completion Time: 10 | Remaining Time: 5 | Priority: 1 |Process ID: 4 | State: NEW | Arrival Time: 3 | Burst Time: 5 | Completion Time: 10 | Remaining Time: 5 | Priority: 1 |5 | Completion Time: 10 | Remaining Time: 5 | Priority: 1 | Memory: 150 | I/O Required: Yes | Waiting Time: 2 | Turnaround Time: 7
Mapped Pages:
Average Turnaround Time: 13
Average Waiting Time: 6.5
PS C:\Users\USER\OS\CSCE4326>

Mapped Pages:
Average Turnaround Time: 13
Average Waiting Time: 6.5
Mapped Pages:
Mapped Pages:
Mapped Pages:
Average Turnaround Time: 13
Average Waiting Time: 6.5



