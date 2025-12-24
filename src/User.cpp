#include "User.h"
#include <iostream>
using namespace std;

User::User(string n, string id) {
    name= n;
    userID= id;
    borrowedBooks= nullptr;
}

void User::borrowBook(Book* b){
    BorrowedBookNode* node= new BorrowedBookNode(b);
    node->next= borrowedBooks;
    borrowedBooks= node;

    b->available= false;
    history.push("Borrowed: " + b->title);

    cout<< name<<" borrowed \""<< b->title<<"\" successfully.\n";
}

void User::returnBook(Book* b){
    BorrowedBookNode* prev= nullptr;
    BorrowedBookNode* curr= borrowedBooks;

    while(curr){
        if(curr->book == b){
            if(prev){ 
                prev->next= curr->next;
            }
            else{ 
                borrowedBooks= curr->next;
            }    

            delete curr;
            b->available= true;

            history.push("Returned: " + b->title);
            cout<< name<<" returned \""<< b->title<<"\" successfully.\n";
            return;
        }

        prev= curr;
        curr= curr->next;
    }

    cout<< "Book not found in user's borrowed list!\n";
}

void User::printBorrowedBooks() {
    BorrowedBookNode* curr= borrowedBooks;
    if(!curr){
        cout<<name <<" has no borrowed books.\n";
        return;
    }

    cout<< "Borrowed books by "<< name<<":\n";
    while(curr){
        cout<< "- "<< curr->book->title<< "\n";
        curr= curr->next;
    }
}

void User::printHistory() {
    stack<string> temp= history;
    cout<< "Activity log for "<< name<<":\n";

    while(!temp.empty()){
        cout<< "- "<<temp.top()<<"\n";
        temp.pop();
    }
}
