#include "Process.h"
#include <iostream>
#include <algorithm>

// Constructor
Process::Process(int pid, int arrival_time, int burst_time, int priority, int memory_required, bool io_operations)
    : pid(pid), arrival_time(arrival_time), burst_time(burst_time), priority(priority),
      state(NEW), remaining_time(burst_time), waiting_time(0), turnaround_time(0), completion_time(0),
      memory_required(memory_required), io_operations(io_operations)
{
    initializePageTable();
    initializeTLB(); // TLB
    pageProtectionTable.resize(NUM_VIRTUAL_PAGES, READ_WRITE); 
}

// Getters
int Process::getPid() const { return pid; }
int Process::getArrivalTime() const { return arrival_time; }
int Process::getBurstTime() const { return burst_time; }
int Process::getPriority() const { return priority; }
ProcessState Process::getState() const { return state; }
int Process::getRemainingTime() const { return remaining_time; }
int Process::getWaitingTime() const { return waiting_time; }
int Process::getTurnaroundTime() const { return turnaround_time; }
int Process::getCompletionTime() const { return completion_time; }
int Process::getMemoryRequired() const { return memory_required; }
std::string Process::hasIOOperations() const { return io_operations ? "Yes" : "No"; }

// TLB Initialization
void Process::initializeTLB() {
    tlb.resize(TLB_SIZE);
    for (auto& entry : tlb) {
        entry.valid = false;
        entry.virtualPage = -1;
        entry.frameNumber = -1;
    }
}

// TLB Lookup
int Process::translateWithTLB(int virtualAddress) const {
    int pageNumber = virtualAddress / PAGE_SIZE;
    for (const auto& entry : tlb) {
        if (entry.valid && entry.virtualPage == pageNumber) {
            return entry.frameNumber * PAGE_SIZE + (virtualAddress % PAGE_SIZE);
        }
    }
    return -1; // TLB miss
}

// Virtual Address Translation (TLB + page protection + faults)
int Process::translateVirtualAddress(int virtualAddress, bool write) {
    int pageNumber = virtualAddress / PAGE_SIZE;
    int offset = virtualAddress % PAGE_SIZE;

    // TLB check
    int tlbResult = translateWithTLB(virtualAddress);
    if (tlbResult != -1) {
        std::cout << "[TLB HIT] Virtual address " << virtualAddress
                  << " → Physical address " << tlbResult << " via TLB.\n";
        return tlbResult;
    } else {
        std::cout << "[TLB MISS] Virtual address " << virtualAddress
                  << " not found in TLB. Checking page table...\n";
    }

    // Range check
    if (pageNumber >= NUM_VIRTUAL_PAGES) {
        std::cerr << "[ERROR] Invalid virtual address (out of range): " << virtualAddress << "\n";
        return -1;
    }

    const PageTableEntry& entry = pageTable[pageNumber];

    if (!entry.valid) {
        std::cerr << "[PAGE FAULT] Virtual page " << pageNumber << " is not in memory.\n";
        return -1;
    }

    if (write && pageProtectionTable[pageNumber] == READ_ONLY) {
        std::cerr << "[PROTECTION FAULT] Write to read-only page " << pageNumber << " is illegal.\n";
        return -1;
    }

    // TLB update
    int newTLBIndex = pageNumber % TLB_SIZE;
    tlb[newTLBIndex] = { pageNumber, entry.frameNumber, true };
    std::cout << "[TLB UPDATE] Inserted page into frame "
              << entry.frameNumber << " into TLB at index " << newTLBIndex << ".\n";

    return entry.frameNumber * PAGE_SIZE + offset;
}

// Setters
void Process::setState(ProcessState newState) { state = newState; }
void Process::setWaitingTime(int time) { waiting_time = time; }
void Process::setTurnaroundTime(int time) { turnaround_time = time; }
void Process::setCompletionTime(int time) { completion_time = time; }

// Run logic
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

// Page Table Init
void Process::initializePageTable() {
    pageTable.resize(NUM_VIRTUAL_PAGES);
    for (auto& entry : pageTable) {
        entry.valid = false;
        entry.frameNumber = -1;
        entry.dirty = false;
    }
}

// Map page with optional protection
void Process::mapPage(int virtualPage, int frameNumber, bool readOnly) {
    if (virtualPage >= 0 && virtualPage < NUM_VIRTUAL_PAGES) {
        pageTable[virtualPage].valid = true;
        pageTable[virtualPage].frameNumber = frameNumber;
        pageTable[virtualPage].dirty = false;
        pageProtectionTable[virtualPage] = readOnly ? READ_ONLY : READ_WRITE;
    }
}

void Process::setPageProtection(int virtualPage, PageProtection protection) {
    if (virtualPage >= 0 && virtualPage < NUM_VIRTUAL_PAGES) {
        pageProtectionTable[virtualPage] = protection;
    } else {
        std::cerr << "Error: Invalid virtual page " << virtualPage << "\n";
    }
}

std::string Process::getStateString() const {
    switch (state) {
        case NEW: return "NEW";
        case READY: return "READY";
        case RUNNING: return "RUNNING";
        case WAITING: return "WAITING";
        case TERMINATED: return "TERMINATED";
        default: return "UNKNOWN";
    }
}

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
