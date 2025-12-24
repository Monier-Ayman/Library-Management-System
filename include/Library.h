#pragma once
#include <map>
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;

class Library {
private:
    map<string, Book*> books;
    vector<User*> users;

public:
    void addBook();
    void addUser();
    User* findUser(const string& id);
    void borrowBook();
    void returnBook();
    void searchBook();
    void listBooks();
    void listUsers();
};
