#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Make the password unreadable: add 3 to every character
string encrypt(string password) {
    for (int i = 0; i < password.length(); i++) {
        password[i] = password[i] + 3;
    }
    return password;
}

// Registration
void registerUser() {
    string username, password, fileUser, filePass;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if the username already exists
    ifstream readFile("users.txt");
    while (readFile >> fileUser >> filePass) {
        if (fileUser == username) {
            cout << "Error: Username already taken.\n";
            return;
        }
    }
    readFile.close();

    // Check password length
    if (password.length() < 6) {
        cout << "Error: Password must be at least 6 characters.\n";
        return;
    }

    // Save to file
    ofstream writeFile("users.txt", ios::app);
    writeFile << username << " " << encrypt(password) << endl;
    cout << "Success: Registration complete!\n";
}

// Login
void loginUser() {
    string username, password, fileUser, filePass;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream readFile("users.txt");
    while (readFile >> fileUser >> filePass) {
        if (fileUser == username && filePass == encrypt(password)) {
            cout << "Success: Login successful!\n";
            return;
        }
    }
    cout << "Error: Wrong username or password.\n";
}

int main() {
    int choice;

    do {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) registerUser();
        else if (choice == 2) loginUser();
    } while (choice != 3);

    return 0;
}