#pragma once
#include <string>
#include <stack>
#include "Book.h"
using namespace std;

struct BorrowedBookNode{
    Book* book;
    BorrowedBookNode* next;
    BorrowedBookNode(Book* b) : book(b), next(nullptr){}
};

class User{
public:
    string name;
    string userID;
    BorrowedBookNode* borrowedBooks; 
    stack<string> history;           

    User(string n, string id);
    void borrowBook(Book* b);
    void returnBook(Book* b);
    void printBorrowedBooks();
    void printHistory();
};
