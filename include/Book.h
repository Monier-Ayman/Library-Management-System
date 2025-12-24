#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book{
public:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;

    Book(std::string t, std::string a, std::string i)
       : title(t), author(a), ISBN(i), available(true){}
};

#endif
