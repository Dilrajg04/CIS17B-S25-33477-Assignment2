//main.cpp

//Dilraj Grewal

//CIS17B - John O' Connor

//Assignment 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//constants
const int MAX_BOOKS = 100;
const int MAX_USERS = 100;


//book class
class Book {
public:
    
    string title;
    string author;
    string ISBN;
    bool isAvailable;

    // Constructor to initialize a Book object
    Book(string t, string a, string i) {
        title = t;
        author = a;
        ISBN = i;
        isAvailable = true;
    }
    
};

//user class
class User {
   // the protected access specifier keeps the code accessible but hidden.
protected:
    string name;
    int userID;
    vector<Book*> borrowedBooks;

public:
    //constructor to create a new user
    User(string n, int id) : name(n), userID(id) {}

    //function displays user information
    void displayUserInfo() {
        cout << "-- Name: " << name << "\n";
        cout << "-- User ID: " << userID << "\n";
        cout << "-- Books Checked Out:\n";
        cout << endl;
        if (borrowedBooks.empty()) {
            cout << " None\n";
        } else {
            
            //loop goes through each borrowed book and prints its title  and author
            for (Book* book : borrowedBooks) {
                cout << "   - " << book->title << " by " << book->author << "\n";
            }
    }
}

    //function to borrow a book
    //
    void borrowBook(Book* book) {
        
        if (book->isAvailable) {
            
            borrowedBooks.push_back(book);
            book->isAvailable = false;
            cout << "Book borrowed successfully!\n";
        }
        
        else {
            cout << "!! Error: Book is not available!\n";
        }
    }

    //function to return a book
    void returnBook(Book* book) {
        //loops iterates through all users, displaying each user's number and calling a function.
        for (int i = 0; i < borrowedBooks.size(); i++) {
            if (borrowedBooks[i] == book) {
                
                borrowedBooks.erase(borrowedBooks.begin() + i);
                book->isAvailable = true;
                cout << "Book returned successfully!\n";
                return;
                
            }
        }
        
        
        cout << "!! Error: You never borrowed this book!\n";
    }
};

//library class
class Library {
    
private:
    int UserID2 = 0;
    vector<Book> books;
    vector<User*> users;


public:
    //function to add a new book to the library
    void addBook() {
        if (books.size() >= MAX_BOOKS) {
            cout << "!! Error: Library is full, cannot add more books.\n";
            return;
        }

        string title, author, ISBN;
        
        cout << ">> Enter Book Title (or 0 to cancel): ";
        getline(cin, title);
        if (title == "0") return;

        cout << ">> Enter Book Author (or 0 to cancel): ";
        getline(cin, author);
        if (author == "0") return;

        cout << ">> Enter Book ISBN (or 0 to cancel): ";
        getline(cin, ISBN);
        if (ISBN == "0") return;

        books.push_back(Book(title, author, ISBN));
        cout << "> Book Added Successfully!\n";
    }

    // Function to list all books in the library
    void listAllBooks() {
        if (books.empty()) {
            cout << ">> No books available.\n";
            return;
        }

        cout << ">> List of Books:\n";
        for (int i = 0; i < books.size(); i++) {
            
            cout << ">> Book " << i + 1 << ":\n";
            cout << "-- Title: " << books[i].title << "\n";
            cout << "-- Author: " << books[i].author << "\n";
            cout << "-- ISBN: " << books[i].ISBN << "\n";
            cout << "-- Available: " << (books[i].isAvailable ? "Yes" : "No") << "\n";
            
            cout << endl;
        }
    }
    //function to list all users
    void listAllUsers() {
        if (users.empty()) {
            cout << ">> List empty.\n";
            return;
        }
    
        cout << ">> User List.\n";
        //loops through all users while displaying each user's info, and labels them by index + 1.
        for (int i = 0; i < users.size(); i++) {
            cout << ">> User " << i + 1 << ":\n";
            users[i]->displayUserInfo();
        }
    }
    

    //function to register a new user
    void addUser() {
        string name;
        cout << ">> Enter User Name (or 0 to cancel): ";
        getline(cin, name);
        
        if (name == "0"){
            return;
        }
        //creates a new user and adds it to the list, and prints the assigned ID.
        User* newUser = new User(name, UserID2 ++);
        users.push_back(newUser);
        cout << "> User Added Successfully with ID: " << UserID2 - 1 << "\n";
    }


};




int main() {
    
    Library library;
    int option;

    do {
        
        
        cout << " Welcome to the Library: \n";
        cout << "1. Manage Books\n";
        cout << "2. Manage Users\n";
        cout << "3. List books\n";
        cout << "4. List users\n";
        cout << "5. Quit\n";
        cout << ">> Enter your choice: ";
        cin >> option;
        
        //ignore leftover newline from input
        cin.ignore();
        switch (option)
        {
            case 1:
                library.addBook();
                break;
            case 2:
                library.addUser();
                break;
            case 3:
                library.listAllBooks();
                break;
            case 4:
                library.listAllUsers();
                break;
            case 5:
                cout << "Thank you for visint the Library!\n";
                break;
            default:
                cout << "Invalid input, try again.\n";
                break;
                
                
                
        }
    } while (option != 5);

    return 0;
}

