#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
#include <string>

enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int memory_required;
    bool io_operations;
    ProcessState state;


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
    int getMemoryRequired() const;
    std::string hasIOOperations() const;

    //setters
    void setState(ProcessState newState);
    void setWaitingTime(int time);
    void setTurnaroundTime(int time);

    //methods
    void decrementExecutionTime(int timeSlice);
    void runProcess(int timeSlice); //simulate running the process
    std::string getStateString() const;
    void displayProcessInfo() const; //improved display
};

#endif // PROCESS_H
