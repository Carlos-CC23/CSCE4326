#ifndef PROCESS_H
#define PROCESS_H
#define PAGE_SIZE 4096 // 4KB
#define VIRTUAL_MEMORY_SIZE (64 * 1024) // 64KB per process
#define PHYSICAL_MEMORY_SIZE (32 * 1024) // 32KB total
#define NUM_VIRTUAL_PAGES (VIRTUAL_MEMORY_SIZE / PAGE_SIZE)
#define NUM_PHYSICAL_FRAMES (PHYSICAL_MEMORY_SIZE / PAGE_SIZE)

#include <iostream>
#include <vector>
#include <string>

struct PageTableEntry {
    bool valid;
    int frameNumber;
    bool dirty;
};

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
    std::vector<PageTableEntry> pageTable;


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

    //Virtual address
    void initializePageTable();
    int translateVirtualAddress(int virtualAddress) const;
    void mapPage(int virtualPage, int frameNumber); // optional helper

};
#endif // PROCESS_H