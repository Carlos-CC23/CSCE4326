#include <iostream>
#include "auth.h"

int main() {
  std::cout << "LAPTOP is botting up...\n";

  if (authenticateUser()){
    std::cout << "Successful. Welcome";
    } 
  else {
    std::cout << "Failed. Try Again";
  }

  return 0;
  }
