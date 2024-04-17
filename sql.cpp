#include <iostream>
#include <sqlite3.h>
#include <string>

using namespace std;


bool login(sqlite3* db, const string& username, const string& password) {
    sqlite3_stmt* stmt;
    string query = "SELECT * FROM users WHERE username = ? AND password = ?";
    
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
        
        if (sqlite3_step(stmt) == SQLITE_ROW) {
            cout << "Login successful!" << endl;
            return true;
        }
    }
    
    cout << "Login failed. Incorrect username or password." << endl;
    return false;
}

// Function to handle sign up
bool signUp(sqlite3* db, const string& username, const string& password) {
    sqlite3_stmt* stmt;
    string query = "INSERT INTO users (username, password) VALUES (?, ?)";
    
    if (sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, password.c_str(), -1, SQLITE_STATIC);
        
        if (sqlite3_step(stmt) == SQLITE_DONE) {
            cout << "Sign up successful!" << endl;
            return true;
        }
    }
    
    cout << "Sign up failed. User already exists or database error." << endl;
    return false;
}

int main() {
    sqlite3* db;
    int rc = sqlite3_open("database.db", &db); 

    if (rc) {
        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return 1;
    }

    
    string createTableQuery = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT)";
    sqlite3_exec(db, createTableQuery.c_str(), nullptr, nullptr, nullptr);

   
    string username, password;
    
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    
    int choice;
    cout << "Enter 1 for login, 2 for sign up: ";
    cin >> choice;
    
    if (choice == 1) {
        login(db, username, password);
    } else if (choice == 2) {
        signUp(db, username, password);
    } else {
        cout << "Invalid choice." << endl;
    }

    
    sqlite3_close(db);
    return 0;
}
