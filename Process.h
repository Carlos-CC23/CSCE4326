#define PROCESS_H
#ifndef PROCESS_H

#include <iostream>
#include <string>

enum ProcessState {NEW, READY, RUNNING, WAITING, TERMINATED};

//Convert the enum state into strings
string StateToString{
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
  Process(int pid)
  : pid(pid){}
