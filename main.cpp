#include <iostream>
#include "auth.h"
#include "Process.h"

using namespace std;

int main() {
  //Message displayed when program first runs
  cout << "LAPTOP is booting up...\n";
  
  //Statement calls the function
  if (authenticateUser()){
    cout << "Successful. Welcome";
    
    //Code below is our test cases to create process and the different state changes
    //Creating two sample processes
    Process p1(1, 0, 10, 1, 100, false);
    Process p2(2, 2, 15, 2, 200, true);

    //Demonstrate state changes of process p1
    cout << "\nProcess p1 initial state: " << p1.getStateString() <<endl;
    p1.setState(READY);
    cout << "p1 state changed to: "<< p1.getStateString() << endl;

    //Simulate execution: p1 runs for 3 time units
    p1.decrementExecutionTime(3);
    cout << "p1 remaining time after 3 time units: " << p1.getRemainingTime() << endl;

    //Simulate further execution: p1 runs for 7 more time units.
    p1.decrementExecutionTime(7);
    cout << "p1 state after finishing execution: " << p1.getStateString() << endl;

    // Demonstrate basic details and state change for process p2.
        cout << "\nProcess p2 details:" << endl;
        cout << "PID: " << p2.getPid() << ", Arrival Time: " << p2.getArrivalTime() 
             << ", Burst Time: " << p2.getBurstTime() 
             << ", Memory Required: " << p2.getMemoryRequired() << endl;
        p2.setState(READY);
        cout << "p2 state changed to: " << p2.getStateString() << endl;
        p2.decrementExecutionTime(5);
        cout << "p2 remaining time after 5 time units: " << p2.getRemainingTime() << endl;
    
    } 
  else {
    cout << "Failed. Try Again";
  }

  return 0;
  }
