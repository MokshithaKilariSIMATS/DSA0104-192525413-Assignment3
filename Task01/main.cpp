#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;
    int copies;

public:
    // Full parameterized constructor with member initializer list and invariant validation
    Book(const std::string& t, const std::string& a, const std::string& i, int c)
        : title(t), author(a), isbn(i), copies(c) {
        if (c < 0) {
            throw std::invalid_argument("Error: Number of copies cannot be negative (" + std::to_string(c) + ")");
        }
    }

    // Situation 1: Donated book with only title - delegates to primary constructor
    explicit Book(const std::string& t)
        : Book(t, "Community Donor", "DONATED-001", 1) {}

    // Situation 2: Empty record to be filled later (Default Constructor) - delegates to primary constructor
    Book()
        : Book("Untitled Record", "Unknown Author", "ISBN-PENDING", 0) {}

    // Getter and display helper
    void display() const {
        std::cout << "[BOOK] \"" << title << "\" | Author: " << author
                  << " | ISBN: " << isbn << " | Copies: " << copies << '\n';
    }

    int getCopies() const { return copies; }
};

int main() {
    std::cout << "=== Assignment 3 - Q1: Library Book Records (Constructors) ===\n\n";

    // 1. New book with full details
    Book b1("C++ Primer", "Stanley Lippman", "978-0321714114", 5);
    std::cout << "1. Full Details Constructor:\n   ";
    b1.display();

    // 2. Donated book (only title, delegated constructor)
    Book b2("Clean Code");
    std::cout << "2. Donated Book Constructor (Delegated):\n   ";
    b2.display();

    // 3. Empty record (default constructor, delegated)
    Book b3;
    std::cout << "3. Default Constructor (Delegated):\n   ";
    b3.display();

    // 4. Testing invalid number of copies (Negative copies invariant check)
    std::cout << "\n4. Invariant Validation (Negative copies):\n";
    try {
        std::cout << "   Attempting to create Book with -3 copies...\n";
        Book invalidBook("Corrupted Data", "Anon", "ERR-999", -3);
        invalidBook.display();
    } catch (const std::invalid_argument& ex) {
        std::cout << "   Caught expected exception: " << ex.what() << '\n';
    }

    return 0;
}
