#define PROCESS_H
#ifndef PROCESS_H
#include <iostream>
#include <string>


enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

//Convert the enum state into strings
std::string stateToString(ProcessState state) {
    switch(state) {
        case NEW:
            return "NEW";
        case READY;
            return "READY";
        case RUNNING:
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

//settters
void setState(ProcessState newState) {
    state = newState; }

void setWaitingTime(int time) {
    waiting_time = time; }

void setTurnaround(int time) {
    turnaround_time = time - arrival_time; }

void execute(int time_quantum) {
    if (remaining_time > 0) {
        remaining_time -= time_quantum;
        if (remaing_time <= 0) {
            remainig_time = 0;
            state = TERMINATED;
        }
    }
}

//display the process info
void displayProcessInfo() const {
    std::court << "Process ID: " << pid << " | State: " << stateToString(state)
        << " | Arrival Time: " << arrival_time << " | Burst Time: " << burst_time
        << " | Remaining Time: " << remaining_time << " | Priority: " << priority
        << " | Memory: " << memory_required << " | Waiting Time: " << waiting_time
        << " | Turnaround Time: " << turnaround_time << "\n";

};
#endif //PROCESS_H
