# Library Management System

C++ Library Management System project using **OOP**, **Map**, **Stack**, and **Linked List**.  
This project simulates a small library where users can borrow and return books, and administrators can manage books and users.

---

## **Features**
- Add and manage books  
- Add and manage users  
- Borrow and return books  
- Search books by **title** or **ISBN**  
- Track borrowed books per user  
- Track recent activity using **stack**  
- List all books and users  

---

## **Data Structures Used**
| Data Structure | Purpose |
|----------------|---------|
| **Map** | Fast search of books by title or ISBN |
| **Linked List** | Track borrowed books per user |
| **Stack** | Track recent activity / history logs |
| **Vector / Array** | Temporary lists or reports |

---

## **How to Run**

### Compile:
```bash
g++ src/main.cpp src/Library.cpp src/User.cpp -o LibrarySystem.exe
```

### On Linux / Mac:
./LibrarySystem.exe

### On Windows:
.\LibrarySystem.exe 
