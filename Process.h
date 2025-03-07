#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>

enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

class Process {
private:
    int pid; //Process Identifier
    int arrival_time; //The time when process enters the system
    int burst_time; //Required CPU execution time
    int priority; //Priority level of process
    int remaining_time; //CPU time left for completion
    int waiting_time; //The total time spent on waiting in the ready queue
    int turnaround_time; //The total time from arrival to completion
    int completion_time; // When the process finishes execution
    int memory_required; //Memory required by the process
    bool io_operations; // Indicates if the process has I/O Operations
    ProcessState state; //The current process states -> NEW, READY, RUNNING, WAITING, TERMINATED


public:
    //constructor
    Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations);

//getters
    int getPid() const;
    int getArrivalTime() const;
    int getBurstTime() const;
    int getPriority() const;
    ProcessState getState() const;
    int getRemainingTime() const;
    int getWaitingTime() const;
    int getTurnaroundTime() const;
    int getCompletionTime() const;
    int getMemoryRequired() const;
    std::string hasIOOperations() const;

    //setters
    void setState(ProcessState newState);
    void setWaitingTime(int time);
    void setTurnaroundTime(int time);
    void setCompletionTime(int time);

    //methods
    void decrementExecutionTime(int timeSlice);
    void runProcess(int timeSlice); //simulate running the process
    std::string getStateString() const;
    void displayProcessInfo() const; //improved display
};

#endif // PROCESS_H
