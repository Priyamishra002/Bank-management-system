#include <iostream>
using namespace std;

// class
class Bank {
private:
    int acno;
    char name[30];
    long balance;

public:
    void OpenAccount() {
        cout << "Enter Account Number: ";
        cin >> acno;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Balance: ";
        cin >> balance;
    }

    void ShowAccount() {
        cout << "Account Number: " << acno << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }

    void Deposit() {
        long amt;
        cout << "Enter Amount You Want to Deposit? ";
        cin >> amt;
        balance = balance + amt;
    }

    void Withdrawal() {
        long amt;
        cout << "Enter Amount You Want to Withdraw? ";
        cin >> amt;
        if (amt <= balance)
            balance = balance - amt;
        else
            cout << "Insufficient Balance..." << endl;
    }

    void EditAccount() {
        cout << "Edit Account Name: ";
        cin >> name;
        cout << "Edit Balance: ";
        cin >> balance;
        cout << "Account Updated Successfully." << endl;
    }

    int Search(int);
    int GetAccountNumber() {
        return acno;
    }
};

int Bank::Search(int a) {
    if (acno == a) {
        ShowAccount();
        return (1);
    }
    return (0);
}

// main code
int main() {
    Bank C[3];
    int found = 0, a, ch, i;
    for (i = 0; i < 3; i++) {
        C[i].OpenAccount();
    }

    do {
        // display options
        cout << "\n\n1: Display All\n2: Search by Account No\n3: Deposit\n4: Withdraw\n5: Edit Account\n6: Delete Account\n7: Exit" << endl;
        
        // user input
        cout << "Please input your choice: ";
        cin >> ch;

        switch (ch) {
            case 1: // Displaying all account info
                for (i = 0; i < 3; i++) {
                    C[i].ShowAccount();
                }
                break;
            case 2: // Searching the record by account number
                cout << "Account Number? ";
                cin >> a;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    if (found)
                        break;
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 3: // Deposit operation
                cout << "Account Number To Deposit Amount? ";
                cin >> a;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    if (found) {
                        C[i].Deposit();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 4: // Withdraw operation
                cout << "Account Number To Withdraw Amount? ";
                cin >> a;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    if (found) {
                        C[i].Withdrawal();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 5: // Edit Account operation
                cout << "Account Number To Edit? ";
                cin >> a;
                for (i = 0; i < 3; i++) {
                    found = C[i].Search(a);
                    
                    if (found) {
                        C[i].EditAccount();
                        break;
                    }
                }
                if (!found)
                    cout << "Record Not Found" << endl;
                break;
            case 6: // Delete Account operation
                cout << "Enter Account Number to Delete: ";
                cin >> a;
                found = 0;
                for (i = 0; i < 3; i++) {
                    if (C[i].GetAccountNumber() == a) {
                        // Shift elements to remove the account
                        for (int j = i; j < 2; j++) {
                            C[j] = C[j + 1]; // Shift the accounts left
                        }
                        found = 1;
                        cout << "Account Deleted Successfully.\n";
                        break;
                    }
                }
                if (!found) {
                    cout << "Account Not Found!" << endl;
                }
                break;
            case 7: // Exit
                cout << "Have a nice day!" << endl;
                break;
            default:
                cout << "Wrong Option!" << endl;
        }
    } while (ch != 7);
    return 0;
}
