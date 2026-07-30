#include <iostream>
#include <string>
#include <memory>
#include <stdexcept>

using namespace std;


// Custom Exception Classes


class LibraryException : public runtime_error {
public:
    LibraryException(string message) : runtime_error(message) {}
};

class CheckoutException : public LibraryException {
public:
    CheckoutException(string message)
        : LibraryException("Checkout Error: " + message) {}
};

class ReturnException : public LibraryException {
public:
    ReturnException(string message)
        : LibraryException("Return Error: " + message) {}
};


// Base Class


class LibraryItem {
private:
    string id;
    string title;
    bool available;

protected:
    double dailyFine;
    int maxLoanDays;

public:
    LibraryItem(string itemId, string itemTitle) {
        id = itemId;
        title = itemTitle;
        available = true;
        dailyFine = 0;
        maxLoanDays = 0;
    }

    virtual ~LibraryItem() {}

    // Getters
    string getId() {
        return id;
    }

    string getTitle() {
        return title;
    }

    bool isAvailable() {
        return available;
    }

    // Pure Virtual Functions
    virtual string getItemType() = 0;
    virtual double calculateFine(int daysOverdue) = 0;
    virtual string getDetails() = 0;

    // Checkout Function
    void checkOut() {
        if (!available) {
            throw CheckoutException("Item is already checked out.");
        }

        available = false;
    }

    // Return Function
    void returnItem() {
        if (available) {
            throw ReturnException("Item is already available.");
        }

        available = true;
    }
};


// Derived Class : Book


class Book : public LibraryItem {
private:
    string author;
    string isbn;
    string genre;
    int pageCount;
    int publishYear;

public:
    Book(string id,
         string title,
         string authorName,
         string bookISBN,
         string bookGenre,
         int pages,
         int year)
        : LibraryItem(id, title) {

        author = authorName;
        isbn = bookISBN;
        genre = bookGenre;
        pageCount = pages;
        publishYear = year;

        dailyFine = 0.5;
        maxLoanDays = 14;
    }

    string getItemType() override {
        return "Book";
    }

    double calculateFine(int daysOverdue) override {
        return daysOverdue * dailyFine;
    }

    string getDetails() override {
        return "Author: " + author +
               ", ISBN: " + isbn +
               ", Genre: " + genre +
               ", Pages: " + to_string(pageCount) +
               ", Year: " + to_string(publishYear);
    }
};


// Main Function


int main() {

    try {

        // Create a Book object using smart pointer
        unique_ptr<LibraryItem> book =
            make_unique<Book>(
                "B001",
                "The Great Gatsby",
                "F. Scott Fitzgerald",
                "9780743273565",
                "Fiction",
                180,
                1925
            );

        // Display Book Information
        cout << "Item Type : " << book->getItemType() << endl;
        cout << "Book Title: " << book->getTitle() << endl;
        cout << "Book Info : " << book->getDetails() << endl;

        // Checkout
        book->checkOut();
        cout << "\nBook checked out successfully!" << endl;

        // Checkout Again (Throws Exception)
        book->checkOut();

    }
    catch (LibraryException &e) {
        cout << e.what() << endl;
    }

    return 0;
}
