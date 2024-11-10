#include <iostream>
#include <string>
using namespace std;

// Account database
int accnumber = 1; 
int name = 98;     

class Node {
public:
    int accountnumber;
    int username;
    string password;
    int balance;
    Node* next;

    Node(int accnum, int uname, string pass) {
        accountnumber = accnum;
        username = uname;
        password = pass;
        balance = 0;
        next = nullptr;
    }
};

class Linkedlist {
public:
    Node* head;
    Node* tail;
    int size;

    Linkedlist() {
        head = tail = nullptr;
        size = 0;
    }

    void openaccount(int accnumber, int username, string password) {
        Node* t = new Node(accnumber, username, password);
        if (size == 0) {
            head = tail = t;
        } else {
            tail->next = t;
            tail = t;
        }
        size++;
    }

    void display(Node* account) {
        if (account != nullptr) {
            cout << "Account Number: " << account->accountnumber << endl;
            cout << "Username (ID): " << account->username << endl;
            cout << "Password: " << account->password << endl;
            cout << "Balance: " << account->balance << endl;
        } else {
            cout << "No account found." << endl;
        }
    }

    Node* findAccount(int a, int u, string p) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->accountnumber == a && temp->username == u && temp->password == p) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;  
    }

    void checkbalance(int a, int u, string p) {
        Node* account = findAccount(a, u, p);
        if (account != nullptr) {
            cout << "Account Balance: " << account->balance << endl;
        } else {
            cout << "Account not found or incorrect credentials!" << endl;
        }
    }

    void credit(int a, int u, string p, int amount) {
        Node* account = findAccount(a, u, p);
        if (account != nullptr) {
            account->balance += amount;
            cout << "Amount credited successfully. New balance: " << account->balance << endl;
        } else {
            cout << "Account not found or incorrect credentials!" << endl;
        }
    }

    void debit(int a, int u, string p, int amount) {
        Node* account = findAccount(a, u, p);
        if (account != nullptr) {
            if (account->balance < amount) {
                cout << "Transaction is not possible. Insufficient balance!" << endl;
            } else {
                account->balance -= amount;
                cout << "Amount debited successfully. New balance: " << account->balance << endl;
            }
        } else {
            cout << "Account not found or incorrect credentials!" << endl;
        }
    }
};

int main() {
    Linkedlist ll;
    while (true) {
        cout << endl;
        cout << "Enter what you want" << endl;
        cout << "Press 1 to open an account" << endl;
        cout << "Press 2 to check balance" << endl;
        cout << "Press 3 to make transactions (credit or debit)" << endl;

        int val;
        cin >> val;

        if (val == 1) {
            string password;
            cout << "Enter desired password for the account: ";
            cin >> password;
            cout << "Your account opened successfully!" << endl;
            ll.openaccount(accnumber, name, password);
            accnumber++;
            name++;

            Node* newAccount = ll.findAccount(accnumber - 1, name - 1, password);
            ll.display(newAccount);
        } 
        else if (val == 2) {
            int a, u;
            string p;
            cout << "Enter Account Number: ";
            cin >> a;
            cout << "Enter Username: ";
            cin >> u;
            cout << "Enter Password: ";
            cin >> p;

            ll.checkbalance(a, u, p);
        }
        else if (val == 3) {
            int a, u;
            string p;
            cout << "Enter Account Number: ";
            cin >> a;
            cout << "Enter Username: ";
            cin >> u;
            cout << "Enter Password: ";
            cin >> p;

            int transChoice;
            cout << "Press 1 to credit amount" << endl;
            cout << "Press 2 to debit amount" << endl;
            cin >> transChoice;

            int amount;
            cout << "Enter amount: ";
            cin >> amount;

            if (transChoice == 1) {
                ll.credit(a, u, p, amount);
            } else if (transChoice == 2) {
                ll.debit(a, u, p, amount);
            } else {
                cout << "Invalid transaction choice!" << endl;
            }
        } 
        else {
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
