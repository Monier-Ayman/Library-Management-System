#include "Library.h"
#include <iostream>
using namespace std;

void Library::addBook(){
    cin.ignore();
    string title, author, ISBN;
    cout<< "Enter book title: "; getline(cin, title);
    cout<< "Enter author: "; getline(cin, author);
    cout<< "Enter ISBN: "; getline(cin, ISBN);

    if(books.find(title) != books.end()){
        cout<< "Book already exists!\n";
        return;
    }

    books[title]= new Book(title, author, ISBN);
    cout<< "Book added successfully!\n";
}

void Library::addUser() {
    cin.ignore();
    string name, id;
    cout<< "Enter user name: "; getline(cin, name);
    cout<< "Enter user ID: "; getline(cin, id);

    for(auto u : users){
        if(u->userID == id){
            cout<< "User ID already exists!\n";
            return;
        }
    }

    users.push_back(new User(name, id));
    cout << "User added successfully!\n";
}

User* Library::findUser(const string& id) {
    for(auto u : users){
        if(u->userID == id){ 
            return u;
        }    
    }   

    return nullptr;
}

void Library::borrowBook() {
    cin.ignore();
    string userID, title;
    cout<< "Enter user ID: "; getline(cin, userID);
    cout<< "Enter book title: "; getline(cin, title);

    User* user= findUser(userID);
    if(!user){ 
        cout<<"User not found!\n"; 
        return; 
    }

    auto it= books.find(title);
    if(it == books.end()){ 
        cout << "Book not found!\n";
        return;
    }

    Book* book= it->second;
    if(!book->available){
        cout<< "Book is currently unavailable!\n";
        return; 
    }

    user->borrowBook(book);
}

void Library::returnBook() {
    cin.ignore();
    string userID, title;
    cout<< "Enter user ID: "; getline(cin, userID);
    cout<< "Enter book title: "; getline(cin, title);

    User* user= findUser(userID);
    if(!user){ 
        cout<< "User not found!\n"; 
        return; 
    }

    auto it= books.find(title);
    if(it == books.end()){ 
        cout<< "Book not found!\n"; 
        return; 
    }

    user->returnBook(it->second);
}

void Library::searchBook() {
    cin.ignore();
    string title;
    cout<< "Enter book title to search: "; getline(cin, title);

    auto it= books.find(title);
    if(it != books.end()) {
        Book* b= it->second;
        cout << "Found: " << b->title << " by " << b->author
             << ", ISBN: " << b->ISBN
             << ", Available: " << (b->available ? "Yes" : "No") << "\n";
    }
    else{ 
        cout<< "Book not found.\n";
    }    
}

void Library::listBooks(){
    cout<< "=== Library Books ===\n";
    for(auto& pair : books){
        Book* b= pair.second;
        cout << "- " << b->title << " by " << b->author
             << " (ISBN: " << b->ISBN << ") - Available: "
             << (b->available ? "Yes" : "No") << "\n";
    }
}

void Library::listUsers() {
    cout << "=== Library Users ===\n";
    for(auto u : users){ 
        cout << "- " << u->name << " (ID: " << u->userID << ")\n";
    }
        
}
