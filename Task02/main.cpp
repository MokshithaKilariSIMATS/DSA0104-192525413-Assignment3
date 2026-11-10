#include <iostream>
#include <string>
#include <chrono>

class Prescription {
private:
    int n;
    std::string* medicines; // dynamically allocated array

public:
    // Parameterized constructor
    explicit Prescription(int count) : n(count), medicines(new std::string[count]) {}

    // TODO 1: Copy constructor: allocate a NEW array of the same size and copy every medicine (deep copy)
    Prescription(const Prescription& other) : n(other.n), medicines(new std::string[other.n]) {
        for (int i = 0; i < n; ++i) {
            medicines[i] = other.medicines[i];
        }
    }

    // TODO 2: Copy assignment: guard against self-assignment, build a new array, copy, release the old array and return *this
    Prescription& operator=(const Prescription& other) {
        if (this == &other) return *this; // Guard against self-assignment
        std::string* new_meds = new std::string[other.n];
        for (int i = 0; i < other.n; ++i) {
            new_meds[i] = other.medicines[i];
        }
        delete[] medicines; // Release existing buffer
        medicines = new_meds;
        n = other.n;
        return *this;
    }

    // TODO 3: Release the dynamically allocated array
    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const std::string& m) { medicines[i] = m; }
    std::string get(int i) const { return medicines[i]; }
    int size() const { return n; }
};

int main() {
    std::cout << "=== Assignment 3 - Q2: Hospital Prescription Records (Rule of Three) ===\n\n";

    // Assignment Code Verification
    Prescription p(2);
    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p; // copy constructor
    q.set(1, "Cetirizine");

    Prescription r(1);
    r = p; // copy assignment
    p.set(0, "Ibuprofen");

    std::cout << "Official Task Output:\n";
    std::cout << p.get(0) << ' ' << p.get(1) << " | "
              << q.get(0) << ' ' << q.get(1) << " | "
              << r.get(0) << ' ' << r.get(1) << '\n';

    // Self-Assignment Test
    p = p;
    std::cout << "\nSelf-assignment test (p = p): " << p.get(0) << ' ' << p.get(1) << " (PASSED safely)\n";

    // Timing investigation for 10, 1000, 100000 elements
    std::cout << "\nDeep Copy Timing Investigation:\n";
    for (int size : {10, 1000, 100000}) {
        Prescription testP(size);
        for (int i = 0; i < size; ++i) testP.set(i, "Med_" + std::to_string(i));
        
        auto start = std::chrono::high_resolution_clock::now();
        Prescription copyP = testP;
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << "  - Copying " << size << " medicines took: " << duration << " us\n";
    }

    return 0;
}
