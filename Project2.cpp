#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <limits>

using namespace std;

vector<string> names = { "Bob Jones", "Sarah Davis", "Amy Friendly", "Johnny Smith", "Carol Spears" };
vector<int> service = { 1, 2, 1, 1, 2 };

bool CheckUserPermissionAccess() {
    while (1) {
        string username;
        string password;
        cout << "Enter username: " << endl;
        cin >> username;
        cout << "Enter password: " << endl;
        cin >> password;
        /* Check if username AND password are correct*/
        if (username == "admin" && password == "@SecurePassword123") {
            return true;
        }
        /* If username is wrong output prompt*/
        else if (username != "admin" && password == "@SecurePassword123") {
            cout << "The username was not found. Please try again." << endl;
        }
        /* If password is incorrect output prompt*/
        else if (username == "admin" && password != "@SecurePassword123") {
            cout << "Incorrect password. Please try again." << endl;
        }
        /* If both are incorrect output prompt*/
        else {
            cout << "Invalid username and password. Please try again." << endl;
        }
    }
    return false;
}

void DisplayInfo() {
    cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
    for (int i = 0; i < names.size(); i++) {
        cout << i + 1 << ". " << names[i] << " selected option " << service[i] << endl;
    }
}

void ChangeCustomerChoice() {
    /* Add while(1) loop and create 2 string variables and 2 integer variables to hold choices*/
    string clientChoice;
    string serviceChoice;
    int clientInt;
    int serviceInt;
    while (1) {
        cout << "Enter the number of the client that you wish to change" << endl;
        cin >> clientChoice;
        cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)" << endl;
        cin >> serviceChoice;
        /* Try block to prevent unexpected input.*/
        try {
            /* Convert string variables to integers*/
            clientInt = stoi(clientChoice);
            serviceInt = stoi(serviceChoice);
            /* Only Update client service if client is real and service number is acceptable*/
            if ((clientInt > 0 && clientInt < 6) && (serviceInt == 1 || serviceInt == 2)) {
                service[clientInt - 1] = serviceInt;
                /* Leave function when proper request is made*/
                return;
            }
            /* If clientInt is not in client list output prompt*/
            else if ((clientInt < 0 || clientInt > 6) && (serviceInt == 1 || serviceInt == 2)) {
                cout << "The selected client is not in the client list. Please try again." << endl;
            }
            /* If service int is not 1 or 2 output prompt*/
            else if ((clientInt > 0 && clientInt < 6) && (serviceInt != 1 && serviceInt != 2)) {
                cout << "Selected service is not valid. Please try 1 or 2." << endl;
            }
            /* If both are incorrect output prompt*/
            else {
                cout << "The selected client is not in the client list and the selected service is not valid. Please try again." << endl;
            }
        }
        /* Clear input buffer, catch exception, and output prompt to try agian.*/
        catch (...) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Input must be numeric." << endl;
        }
    }
}

int main() {
    /* Add string variable to take in user input*/
    string userChoice;
    int userInt;
    bool access;
    cout << "This program was adapted from binary to C++ by Cody Faircloth on April 6, 2024" << endl;
    cout << "Security vulnerabilities were fixed in this program by Cody Faircloth on April 17, 2024" << endl;
    cout << "Hello! Welcome to our investment company" << endl;
    access = CheckUserPermissionAccess();
    if (access) {
        while (1) {
            cout << "What would you like to do?" << endl;
            cout << "DISPLAY the client list (enter 1)" << endl;
            cout << "CHANGE a client's choice (enter 2)" << endl;
            cout << "Exit the program.. (enter 3)" << endl;
            cin >> userChoice;
            cout << "You chose " << userChoice << endl;
            /* Create try loop to convert string variable to integer for comparison*/
            try {
                userInt = stoi(userChoice);
                if (userInt == 1) {
                    DisplayInfo();
                }
                else if (userInt == 2) {
                    ChangeCustomerChoice();
                }
                else if (userInt == 3) {
                    break;
                }
                else {
                    cout << "Invalid choice. Try 1, 2, or 3." << endl;
                }
            }
            /* Clear input buffer, catch exceptions, and output prompt to try again.*/
            catch (...) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Input must be numeric." << endl;
            }
        }
    }
    else {
        cout << "Permission Denied." << endl;
    }
    return 0;
}

