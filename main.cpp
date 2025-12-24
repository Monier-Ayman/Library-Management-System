#include <iostream>
#include "Library.h"
using namespace std;

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n=== Library Management System ===\n";
        cout << "1. Add Book\n2. Add User\n3. Borrow Book\n4. Return Book\n";
        cout << "5. Search Book\n6. List Books\n7. List Users\n8. Exit\n";
        cout << "Enter choice: "; 
        
        cin >> choice;

        switch (choice){
            case 1: lib.addBook(); break;
            case 2: lib.addUser(); break;
            case 3: lib.borrowBook(); break;
            case 4: lib.returnBook(); break;
            case 5: lib.searchBook(); break;
            case 6: lib.listBooks(); break;
            case 7: lib.listUsers(); break;
            case 8: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 8);

    
    return 0;
}
