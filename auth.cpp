#include <iostream>
#include <string>
#include "auth.h"
using namespace std;

bool authenticateUser(){
  string userName; 
  string PWord;
  
  //The "hardcoded" authentication
  const string correctuserName = "ADMIN";
  const string correctPWord = "OSisthebest23";
  
  //Prompts user for logins
  cout << "Enter username: ";
  cin >> userName;
  cout << "Enter password: ";
  cin >> PWord;
  cout << "\n";

  //Checks if the logins is correct or not
  if(userName == correctuserName && PWord == correctPWord){
    cout << "This authetication is correct. Hello, " << userName << "!\n" << endl;
    return true;
  }
  else{
    cout << "This authetication is incorrect. Incorrect user OR password.\n" << endl;
      return false;
  }
  
}
