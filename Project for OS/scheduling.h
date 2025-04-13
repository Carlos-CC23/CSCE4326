#ifndef SCHEDULING_H
#define SCHEDULING_H

#include <vector>
#include "Process.h"

// Function declarations
void fcfsScheduling(std::vector<Process>& processes);
void sjfNonPreemptiveScheduling(std::vector<Process>& processes);
void sjfPreemptiveScheduling(std::vector<Process>& processes);
void calculateMetrics(std::vector<Process>& processes);

#endif // SCHEDULING_H