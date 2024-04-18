#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> names = {"Bob Jones", "Sarah Davis", "Amy Friendly", "Johnny Smith", "Carol Spears"};
vector<int> service = {1, 2, 1, 1, 2};

bool CheckUserPermissionAccess() {
  while (1) {
    string username;
    string password;
    cout << "Enter username: " << endl;
    cin >> username;
    cout << "Enter password: " << endl;
    cin >> password;
    if (password == "123") {
      return true;
    }
    else {
      cout << "Invalid password. Please try again." << endl;
    }
  }
  return false;
}

void DisplayInfo() {
  cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
  for (int i = 0; i < names.size(); i++) {
    cout << i+1 << ". " << names[i] << " selected option " << service[i] << endl;
  }
}

void ChangeCustomerChoice() {
  int clientChoice;
  int serviceChoice;
  cout << "Enter the number of the client that you wish to change" << endl;
  cin >> clientChoice;
  cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
  cin >> serviceChoice;
  if (clientChoice > 0 && clientChoice < 6) {
    service[clientChoice - 1] = serviceChoice;
  }
}

int main() {
  int userChoice;
  bool access;
  cout << "This program was adapted from binary to C++ by Cody Faircloth on April 6, 2024" << endl;
  cout << "Hello! Welcome to our investment company" << endl;
  access = CheckUserPermissionAccess();
  if (access) {
    while(1) {
      cout << "What would you like to do?" << endl;
      cout << "DISPLAY the client list (enter 1)" << endl;
      cout << "CHANGE a client's choice (enter 2)" << endl;
      cout << "Exit the program.. (enter 3)" << endl;
      cin >> userChoice;
      cout << "You chose " << userChoice << endl;
      if (userChoice == 1) {
        DisplayInfo();
      }
      else if (userChoice == 2) {

      }
      else if (userChoice == 3) {
        break;
      }
    }
  }
  else {
    cout << "Permission Denied." << endl;
  }
  return 0;
}

