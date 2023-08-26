#include <iostream>
#include <fstream>
using namespace std;

class temp
{
    string username, email, password;
    string searchUser, searchPass, searchEmail;
    fstream file;

public:
    void login();
    void signup();
    void forgot();
} obj;

int main()
{
    int choice;
    cout << "\n1. Login \t2. Signup \t3. Forgot Password \t4. Exit\n";
    cout << "\nEnter your choice : ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from input buffer

    while (choice != 4) // Changed the condition here
    {
        switch (choice)
        {
        case 1:
            obj.login();
            break;

        case 2:
            obj.signup();
            break;

        case 3: // Changed from '3' to 3
            obj.forgot();
            break;

        case 4:
            return 0;
            break;

        default:
            cout << "Invalid choice";
            break; // Added break here
        }

        cout << "\n1. Login \t2. Signup \t3. Forgot Password \t4. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from input buffer
    }
    return 0;
}

void temp::signup()
{
    cout << "\nEnter username : ";
    getline(cin, username);
    cout << "\nEnter email : ";
    getline(cin, email);
    cout << "\nEnter password : ";
    getline(cin, password);

    file.open("userdata.txt", ios::out | ios::app);
    file << username << "*" << email << "*" << password << endl;
    file.close();
}

void temp::login()
{
    cout << "\nLogin:" << endl;
    cout << "\n\nEnter username: ";
    getline(cin, searchUser);
    cout << "Enter password: ";
    getline(cin, searchPass);

    file.open("userdata.txt", ios::in);

    bool loggedIn = false;

    while (getline(file, username, '*') && getline(file, email, '*') && getline(file, password, '\n'))
    {
        if (username == searchUser && password == searchPass)
        {
            loggedIn = true;
            break;
        }
    }

    file.close();

    if (loggedIn)
    {
        cout << "\nLogin Successful..." << endl;
        cout << "\nWelcome, " << searchUser << endl;
    }
    else
    {
        cout << "\nInvalid username/password!" << endl;
    }
}

void temp::forgot()
{
    cout << "\nEnter username : ";
    getline(cin, searchUser);
    cout << "\nEnter email : ";
    getline(cin, searchEmail);

    file.open("userdata.txt", ios::in); // Changed the filename to "userdata.txt"
    bool found = false;

    while (getline(file, username, '*') && getline(file, email, '*') && getline(file, password, '\n'))
    {
        if (username == searchUser && email == searchEmail)
        {
            found = true;
            cout << "\nYour password is : " << password << endl;
            break; // No need to continue searching
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nInvalid username/email!" << endl;
    }
}
