#define PROCESS_H
#ifndef PROCESS_H
#include <iostream>
#include <string>

enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

//Convert the enum state into strings
string stateToString{
    switch(case){
        case NEW:
            return "NEW";
        case READY;
            return "READY";
        case RUNNNING:
            return "RUNNING";
        case WAITING:
            return "WAITING";
        case TERMINATED:
            return "TERMINATED";
        default:
            return "UNKNOWN";
    }
}

class Process {
private:
  int pid;
  ProcessState state:
  int Remaining_times;
  int waiting_time;

public:
  Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations)
  : pid(pid), arrival_time(arrival_time), burst_time(burst_time), 
    priority(priority), state(NEW), remaining_time(burst_time), 
    waiting_time(0), turnaround_time(0), memory_required(memory_required),
    io_operations(io_operations)
{}

//Getters for the process attributes
int getPid() const{
    return pid;
}
int getArrivalTime() const {
    return ArrivalTime;
}
int getBurstTime() const {
    return burst_time;
}
int getPriority() const {
    return priority;
}
ProcessState getState() const {
    return state;
}
int getRemainingTime() const {
    return remaining_time;
}
int getWaitingTime() const {
    return waiting_time;
}
int getTurnaroundTime() const {
    return turnaround_time;
}
int getMemoryRequired() const {
    return memory_required;
}
bool hasIOOperations() const {
    return io_operations;
}



};

