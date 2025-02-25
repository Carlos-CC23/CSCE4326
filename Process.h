#define PROCESS_H
#ifndef PROCESS_H
#include <iostream>
#include <string>

enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

class Process {
private:
  int pid;
  ProcessState state:
  int Remaining_times;
  int waiting_time;
  int burst_time;
  int priority;
  int memory_required;
  int turnaround_time;
  bool io_operations;

public:
Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations);

//Getters for the process attributes
int getPid() const;
int getArrivalTime() const;
int getBurstTime() const;
int getPriority() const;
ProcessState getState() const;
int getRemainingTime() const;
int getWaitingTime() const;
int getTurnaroundTime() const;
int getMemoryRequired() const;
bool hasIOOperations() const;

//settters
void setState(ProcessState newState);
void setWaitingTime(int time);
void setTurnaround(int time);

void decrementExecutionTime(int timeSlice);

// Helper method to return the state as a string (for display purposes).
std::string getStateString() const;

};
#endif //PROCESS_H
