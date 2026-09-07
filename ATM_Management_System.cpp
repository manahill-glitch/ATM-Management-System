ATM_Management_System.c
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 10;
const int MAX_TRANSACTIONS = 20;
const double DAILY_LIMIT = 20000;

// ================= STRUCT =================
struct Account
{
    int accountNumber;
    int pin;
    string name;
    double balance;
    double transactions[MAX_TRANSACTIONS];
    int transCount;
    bool isLocked;
    double todayWithdrawn;
};

// ================= CLEAR SCREEN =================
void clearScreen()
{
    system("cls");
}

// ================= MENU =================
void showMenu()
{
    cout << "===== ATM MENU =====\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Change PIN\n";
    cout << "5. Mini Statement\n";
    cout << "6. Transfer Money\n";
    cout << "7. View Account Details\n";
    cout << "8. Apply Interest\n";
    cout << "9. Clear Mini Statement\n";
    cout << "10. Logout\n";
}

// ================= LOGIN =================
int login(Account accounts[MAX_ACCOUNTS], int totalAccounts)
{
    clearScreen();

    int accNo, pin;
    int attempts = 0;

    cout << "========================================================" << endl;
    cout << "              ATM MANAGEMENT SYSTEM                    " << endl;
    cout << "========================================================" << endl;

    cout << "\n===== ATM LOGIN =====\n";
    cout << "Enter Account Number: ";
    cin >> accNo;

    int index = -1;

    for (int i = 0; i < totalAccounts; i++)
    {
        if (accounts[i].accountNumber == accNo)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        cout << "Account not found. Please verify your account number.\n";
        return -1;
    }

    if (accounts[index].isLocked)
    {
        cout << "Your account is locked. Please contact the bank for assistance.\n";
        return -1;
    }

    while (attempts < 3)
    {
        cout << "Enter PIN: ";
        cin >> pin;

        if (accounts[index].pin == pin)
        {
            clearScreen();

            cout << "Login successful. Welcome!\n";
            cout << "Welcome, " << accounts[index].name << "!\n";

            return index;
        }
        else
        {
            attempts++;

            cout << "Incorrect PIN. Please try again.\n";
            cout << "Remaining attempts: " << 3 - attempts << "\n";
        }
    }

    accounts[index].isLocked = true;

    cout << "Account locked after three unsuccessful PIN attempts.\n";

    return -1;
}

// ================= BALANCE =================
void checkBalance(Account &acc)
{
    cout << "\nCurrent Balance: Rs. " << acc.balance << endl;
}

// ================= DEPOSIT =================
void depositMoney(Account &acc)
{
    double amount;

    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0)
    {
        acc.balance += amount;

        if (acc.transCount < MAX_TRANSACTIONS)
        {
            acc.transactions[acc.transCount++] = amount;
        }

        cout << "Deposit completed successfully.\n";
    }
    else
    {
        cout << "Invalid amount. Please enter a positive value.\n";
    }
}

// ================= WITHDRAW =================
void withdrawMoney(Account &acc)
{
    double amount;

    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount <= 0)
    {
        cout << "Invalid amount. Please enter a positive value.\n";
        return;
    }

    if (acc.todayWithdrawn + amount > DAILY_LIMIT)
    {
        cout << "Daily withdrawal limit exceeded. Please enter a smaller amount.\n";
        return;
    }

    if (amount <= acc.balance)
    {
        acc.balance -= amount;
        acc.todayWithdrawn += amount;

        if (acc.transCount < MAX_TRANSACTIONS)
        {
            acc.transactions[acc.transCount++] = -amount;
        }

        cout << "Withdrawal completed successfully.\n";
    }
    else
    {
        cout << "Insufficient balance. Please enter a smaller amount.\n";
    }
}

// ================= CHANGE PIN =================
void changePIN(Account &acc)
{
    int oldPin, newPin;

    cout << "Enter old PIN: ";
    cin >> oldPin;

    if (oldPin == acc.pin)
    {
        cout << "Enter new PIN: ";
        cin >> newPin;

        acc.pin = newPin;

        cout << "PIN updated successfully.\n";
    }
    else
    {
        cout << "Incorrect current PIN. PIN update cancelled.\n";
    }
}

// ================= MINI STATEMENT =================
void miniStatement(Account &acc)
{
    cout << "\n===== MINI STATEMENT =====\n";

    if (acc.transCount == 0)
    {
        cout << "No transactions available.\n";
        return;
    }

    for (int i = 0; i < acc.transCount; i++)
    {
        if (acc.transactions[i] > 0)
        {
            cout << "Deposit: Rs. "
                 << acc.transactions[i] << endl;
        }
        else
        {
            cout << "Withdrawal: Rs. "
                 << -acc.transactions[i] << endl;
        }
    }
}

// ================= TRANSFER =================
void transferMoney(Account accounts[], int total, int sender)
{
    int receiverAcc;
    double amount;

    cout << "Enter recipient account number: ";
    cin >> receiverAcc;

    int receiver = -1;

    for (int i = 0; i < total; i++)
    {
        if (accounts[i].accountNumber == receiverAcc)
        {
            receiver = i;
            break;
        }
    }

    if (receiver == -1)
    {
        cout << "Recipient account not found. Please verify the account number.\n";
        return;
    }

    cout << "Enter transfer amount: ";
    cin >> amount;

    if (amount > 0 && amount <= accounts[sender].balance)
    {
        accounts[sender].balance -= amount;
        accounts[receiver].balance += amount;

        cout << "Transfer completed successfully.\n";
    }
    else
    {
        cout << "Invalid transfer amount or insufficient balance.\n";
    }
}

// ================= DETAILS =================
void viewDetails(Account &acc)
{
    cout << "\n===== ACCOUNT DETAILS =====\n";

    cout << "Account Holder: " << acc.name;
    cout << "\nAccount Number: " << acc.accountNumber;
    cout << "\nBalance: Rs. " << acc.balance << endl;
}

// ================= INTEREST =================
void applyInterest(Account &acc)
{
    double rate = 5;

    double interest = acc.balance * rate / 100;

    acc.balance += interest;

    cout << "Interest credited successfully: Rs. "
         << interest << endl;
}

// ================= CLEAR STATEMENT =================
void clearStatement(Account &acc)
{
    acc.transCount = 0;

    cout << "Mini statement cleared successfully.\n";
}

// ================= MAIN =================
int main()
{
    Account accounts[MAX_ACCOUNTS] =
    {
        {1001, 1111, "Ali",      50000, {}, 0, false, 0},
        {1002, 2222, "Hamna",    35000, {}, 0, false, 0},
        {1003, 3333, "Chaggan",  20000, {}, 0, false, 0},
        {1004, 4444, "Ayesha",   15000, {}, 0, false, 0},
        {1005, 5555, "Bisma",    60000, {}, 0, false, 0},
        {1006, 6666, "Ahmad",    59000, {}, 0, false, 0},
        {1007, 7777, "Muzayyab", 10000, {}, 0, false, 0},
        {1008, 8888, "Uswa",     60000, {}, 0, false, 0},
        {1009, 9999, "Nomii",    90000, {}, 0, false, 0},
        {1010, 1234, "Talha",    67000, {}, 0, false, 0}
    };

    char again;

    do
    {
        clearScreen();

        int index = login(accounts, MAX_ACCOUNTS);

        if (index == -1)
        {
            return 0;
        }

        int choice;

        do
        {
            showMenu();

            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    checkBalance(accounts[index]);
                    break;
                }

                case 2:
                {
                    depositMoney(accounts[index]);
                    break;
                }

                case 3:
                {
                    withdrawMoney(accounts[index]);
                    break;
                }

                case 4:
                {
                    changePIN(accounts[index]);
                    break;
                }

                case 5:
                {
                    miniStatement(accounts[index]);
                    break;
                }

                case 6:
                {
                    transferMoney(accounts, MAX_ACCOUNTS, index);
                    break;
                }

                case 7:
                {
                    viewDetails(accounts[index]);
                    break;
                }

                case 8:
                {
                    applyInterest(accounts[index]);
                    break;
                }

                case 9:
                {
                    clearStatement(accounts[index]);
                    break;
                }

                case 10:
                {
                    clearScreen();

                    cout << "You have been successfully logged out.\n";

                    break;
                }

                default:
                {
                    cout << "Invalid choice. Please select a valid option.\n";
                }
            }

        } while (choice != 10);

        cout << "Login again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "\nThank you for using our ATM Management System.\n";
    cout << "Have a great day!\n";

    return 0;
}