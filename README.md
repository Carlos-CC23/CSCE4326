# CSCE4326
Project for OS Spring 2025

-Building a Basic Operating System

-Team Members: Carlos Chacon & Dante Trevino

-Description: Semester Project to design and implement a simplified operating system simulator using C++.

-Instructions: First step to do is compile the program. 
The second part is that the system boot it up then enter the correct username which is ADMIN and password which is OSisthebest23. 
Then you will be succesfully logged in.

Once you logged in, the program will sample through a process. Each process has an ID, arrival time, burst time, priority, and memory requirements, among other attributes. The program then simulates process execution, updating states and tracking completion time, turnaround time, and waiting time. Next, it runs three scheduling algorithms: First-Come-First-Serve (FCFS), Shortest Job First Non-Preemptive (SJF NP), and Shortest Job First Preemptive (SJF P). Each algorithm determines when processes should execute, calculates key metrics, and prints the results. Finally, the program displays detailed process statistics before computing average turnaround time and waiting time for each scheduling strategy.

--------------------------------------------------------------------------------------
-When using g++ , follows these steps to compile & run program:
-
type -> g++ main.cpp auth.cpp Process.cpp scheduling.cpp -o os_simulator.exe
  
  then type -> .\os_simulator.exe



