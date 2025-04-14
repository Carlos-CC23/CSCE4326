#ifndef PROCESS_H
#define PROCESS_H

#define PAGE_SIZE 4096 // 4KB
#define VIRTUAL_MEMORY_SIZE (64 * 1024) // 64KB per process
#define PHYSICAL_MEMORY_SIZE (32 * 1024) // 32KB total
#define NUM_VIRTUAL_PAGES (VIRTUAL_MEMORY_SIZE / PAGE_SIZE)
#define NUM_PHYSICAL_FRAMES (PHYSICAL_MEMORY_SIZE / PAGE_SIZE)
#define TLB_SIZE 4 // NEW: TLB size

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

// NEW: Page protection types
enum PageProtection {
    READ_ONLY,
    READ_WRITE
};

struct PageTableEntry {
    bool valid;
    int frameNumber;
    bool dirty;
};

struct TLBEntry {
    int virtualPage;
    int frameNumber;
    bool valid;
};

enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

class Process {
private:
    int pid, arrival_time, burst_time, priority, remaining_time;
    int waiting_time, turnaround_time, completion_time;
    int memory_required;
    bool io_operations;
    ProcessState state;
    std::vector<PageTableEntry> pageTable;

    // NEW
    std::vector<TLBEntry> tlb;
    std::vector<PageProtection> pageProtectionTable;

public:
    Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations);

    // Getters
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

    // Setters
    void setState(ProcessState newState);
    void setWaitingTime(int time);
    void setTurnaroundTime(int time);
    void setCompletionTime(int time);

    // Execution
    void decrementExecutionTime(int timeSlice);
    void runProcess(int timeSlice);
    std::string getStateString() const;
    void displayProcessInfo() const;

    // Virtual Memory
    void initializePageTable();
    void initializeTLB(); 
    int translateVirtualAddress(int virtualAddress, bool write = false);
    int translateWithTLB(int virtualAddress) const;
    void mapPage(int virtualPage, int frameNumber, bool readOnly = false); 


    void setPageProtection(int virtualPage, PageProtection protection);
    bool simulateAccess(int virtualAddress, bool write); 
};

#endif // PROCESS_H
