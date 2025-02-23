#define PROCESS_H
#ifndef PROCESS_H

#include <iostream>
#include <string>

class Process {
private:
  int pid;
  ProcessState state:
  int Remaining_times;
  int waiting_time;

public:
  Process(int pid)
  : pid(pid){}
