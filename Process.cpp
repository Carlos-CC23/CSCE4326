#include "Process.h"

// Constructor initializes all attributes
Process::Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations)
    : pid(pid), arrival_time(arrival_time), burst_time(burst_time), priority(priority),
      state(NEW), remaining_time(burst_time), waiting_time(0), turnaround_time(0),
      memory_required(memory_required), io_operations(io_operations)
{}

// Getters
int Process::getPid() const { 
  return pid; 
}
int Process::getArrivalTime() const { 
  return arrival_time; 
}
int Process::getBurstTime() const { 
  return burst_time; 
}
int Process::getPriority() const { 
  return priority; 
}
ProcessState Process::getState() const { 
  return state; 
}
int Process::getRemainingTime() const { 
  return remaining_time; 
}
int Process::getWaitingTime() const { 
  return waiting_time; 
}
int Process::getTurnaroundTime() const { 
  return turnaround_time; 
}
int Process::getMemoryRequired() const { 
  return memory_required; 
}
bool Process::hasIOOperations() const { 
  return io_operations; 
}

// Setters
void Process::setState(ProcessState newState) {
    state = newState;
}

void Process::setWaitingTime(int time) {
    waiting_time = time;
}

void Process::setTurnaroundTime(int time) {
    turnaround_time = time;
}

// This method simulates the process running by decrementing the remaining time.
// It ensures remaining_time does not go below zero; if it reaches zero, the process is TERMINATED.
void Process::decrementExecutionTime(int timeSlice) {
    remaining_time = std::max(remaining_time - timeSlice, 0);
    if (remaining_time == 0) {
        state = TERMINATED;
    }
}

// Returns a string representation of the current process state.
std::string Process::getStateString() const {
    switch(state) {
        case NEW: return "NEW";
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case WAITING: return "WAITING";
        case TERMINATED: return "TERMINATED";
        default: return "UNKNOWN";
    }
}
