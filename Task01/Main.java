// Assignment 3 - Q1: Library Book Records
package Task01;

public class Main {
    public static class Book {
        private String title;
        private String author;
        private String isbn;
        private int copies;

        public Book(String title, String author, String isbn, int copies) {
            if (copies < 0) {
                throw new IllegalArgumentException("Error: Number of copies cannot be negative (" + copies + ")");
            }
            this.title = title;
            this.author = author;
            this.isbn = isbn;
            this.copies = copies;
        }

        // Delegated constructor 1: Donated book
        public Book(String title) {
            this(title, "Community Donor", "DONATED-001", 1);
        }

        // Delegated constructor 2: Default constructor
        public Book() {
            this("Untitled Record", "Unknown Author", "ISBN-PENDING", 0);
        }

        public void display() {
            System.out.printf("[BOOK] "%s" | Author: %s | ISBN: %s | Copies: %d%n",
                    title, author, isbn, copies);
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q1: Library Book Records (Java Equivalent) ===");
        Book b1 = new Book("C++ Primer", "Stanley Lippman", "978-0321714114", 5);
        b1.display();

        Book b2 = new Book("Clean Code");
        b2.display();

        Book b3 = new Book();
        b3.display();

        try {
            System.out.println("Attempting to create Book with -3 copies...");
            new Book("Corrupted Data", "Anon", "ERR-999", -3);
        } catch (IllegalArgumentException e) {
            System.out.println("Caught expected exception: " + e.getMessage());
        }
    }
}
