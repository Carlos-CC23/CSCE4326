#include <iostream>
#include "auth.h"

int main() {
  //Message displayed when program first runs
  std::cout << "LAPTOP is botting up...\n";

  //Statement calls the function
  if (authenticateUser()){
    std::cout << "Successful. Welcome";
    } 
  else {
    std::cout << "Failed. Try Again";
  }

  return 0;
  }
