#include "Process.h"
#include <iostream>
#include <vector>
#include <algorithm>


// Constructor initializes all attributes
Process::Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations)
    : pid(pid), arrival_time(arrival_time), burst_time(burst_time), priority(priority),
      state(NEW), remaining_time(burst_time), waiting_time(0), turnaround_time(0),completion_time(0),
      memory_required(memory_required), io_operations(io_operations)

{
  initializePageTable(); // ✅ Add this line inside the constructor
}

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
int Process::getCompletionTime() const { 
  return completion_time; 
}
int Process::getMemoryRequired() const { 
  return memory_required; 
}
std::string Process::hasIOOperations() const { 
    return io_operations ? "Yes" : "No"; 
}

//This simulates converting a virtual address into a physical address
int Process::translateVirtualAddress(int virtualAddress) const {
  int pageNumber = virtualAddress / PAGE_SIZE;
  int offset = virtualAddress % PAGE_SIZE;

  if (pageNumber >= NUM_VIRTUAL_PAGES) {
      std::cerr << "[ERROR] Invalid virtual address (out of range): " << virtualAddress << "\n";
      return -1;
  }

  const PageTableEntry& entry = pageTable[pageNumber];
  if (!entry.valid) {
      std::cerr << "[PAGE FAULT] Virtual page " << pageNumber << " is not in memory.\n";
      return -1;
  }

  return entry.frameNumber * PAGE_SIZE + offset;
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

void Process::setCompletionTime(int time) { 
  completion_time = time; 
}

// This method simulates the process running by decrementing the remaining time.
// It ensures remaining_time does not go below zero; if it reaches zero, the process is TERMINATED.
void Process::decrementExecutionTime(int timeSlice) {
    remaining_time = std::max(remaining_time - timeSlice, 0);
    if (remaining_time == 0) {
        state = TERMINATED;
    }
}

void Process::runProcess(int timeSlice) {
    if (state == READY) {
        state = RUNNING;
    }
    decrementExecutionTime(timeSlice);
}



void Process::initializePageTable() {
  pageTable.resize(NUM_VIRTUAL_PAGES);
  for (auto& entry : pageTable) {
      entry.valid = false;
      entry.frameNumber = -1;
      entry.dirty = false;
  }
}

//simulate manually mapping a virtual page to a physical frame
void Process::mapPage(int virtualPage, int frameNumber) {
  if (virtualPage >= 0 && virtualPage < NUM_VIRTUAL_PAGES) {
      pageTable[virtualPage].valid = true;
      pageTable[virtualPage].frameNumber = frameNumber;
      pageTable[virtualPage].dirty = false;
  }
}


// Returns a string representation of the current process state.
std::string Process::getStateString() const {
    switch(state) {
        case NEW: 
            return "NEW";
        case READY: 
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

// displays process details
void Process::displayProcessInfo() const {
    std::cout << "Process ID: " << pid
              << " | State: " << getStateString()
              << " | Arrival Time: " << arrival_time
              << " | Burst Time: " << burst_time
              << " | Completion Time: " << completion_time
              << " | Remaining Time: " << remaining_time
              << " | Priority: " << priority
              << " | Memory: " << memory_required
              << " | I/O Required: " << hasIOOperations()
              << " | Waiting Time: " << waiting_time
              << " | Turnaround Time: " << turnaround_time << "\n";
              std::cout << "Mapped Pages: ";
for (int i = 0; i < pageTable.size(); ++i) {
    if (pageTable[i].valid)
        std::cout << "[VPage " << i << " -> Frame " << pageTable[i].frameNumber << "] ";
}
std::cout << "\n";

              
}
