#include <iostream>
#include <string>
#include <vector>

class Auditorium {
private:
    std::string eventName;
    int rows;
    int cols;
    char** seatMap; // 2D dynamic array

public:
    // Dynamic Constructor
    Auditorium(const std::string& name, int r, int c)
        : eventName(name), rows(r), cols(c), seatMap(nullptr) {
        if (rows > 0 && cols > 0) {
            seatMap = new char*[rows];
            for (int i = 0; i < rows; ++i) {
                seatMap[i] = new char[cols];
                for (int j = 0; j < cols; ++j) {
                    seatMap[i][j] = '.'; // '.' = Available, 'X' = Booked
                }
            }
        }
        std::cout << "[CONSTRUCT] Event \"" << eventName << "\" created with "
                  << rows << "x" << cols << " seat grid.\n";
    }

    // Book a seat
    bool bookSeat(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
        if (seatMap[r][c] == 'X') return false; // already booked
        seatMap[r][c] = 'X';
        return true;
    }

    // Cancel a seat
    bool cancelSeat(int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return false;
        if (seatMap[r][c] == '.') return false; // not booked
        seatMap[r][c] = '.';
        return true;
    }

    // Destructor releasing dynamic allocations
    ~Auditorium() {
        int bookedCount = 0;
        int totalSeats = rows * cols;
        if (seatMap != nullptr) {
            for (int i = 0; i < rows; ++i) {
                for (int j = 0; j < cols; ++j) {
                    if (seatMap[i][j] == 'X') ++bookedCount;
                }
                delete[] seatMap[i]; // release each row
            }
            delete[] seatMap; // release row pointers
            seatMap = nullptr;
        }
        std::cout << "[DESTRUCT] Closing summary for \"" << eventName << "\": "
                  << bookedCount << "/" << totalSeats << " seats booked. All memory safely released.\n";
    }
};

// Logger struct for Predict the Output section
struct Logger {
    std::string n;
    Logger(const std::string& s) : n(s) { std::cout << '+' << n << ' '; }
    Logger(const Logger& o) : n(o.n + "c") { std::cout << "copy" << n << ' '; }
    ~Logger() { std::cout << '-' << n << ' '; }
};

void use(Logger) { std::cout << "use "; }

int main() {
    std::cout << "=== Assignment 3 - Q3: Dynamic Constructors & Destructors ===\n\n";

    // 1. Stack-allocated event
    std::cout << "--- 1. Stack Object Lifetime ---\n";
    {
        Auditorium stackEvent("Symphony Concert", 5, 10);
        stackEvent.bookSeat(0, 0);
        stackEvent.bookSeat(0, 1);
        stackEvent.cancelSeat(0, 1);
        stackEvent.bookSeat(2, 4);
    } // stackEvent destroyed here

    // 2. Heap-allocated event
    std::cout << "\n--- 2. Heap Object Lifetime (new / delete) ---\n";
    Auditorium* heapEvent = new Auditorium("Tech Keynote", 8, 12);
    heapEvent->bookSeat(1, 1);
    heapEvent->bookSeat(1, 2);
    delete heapEvent; // Explicit destruction

    // 3. Zero-rows edge case
    std::cout << "\n--- 3. Edge Case: Zero Rows Event ---\n";
    {
        Auditorium emptyEvent("Cancelled Event", 0, 0);
    }

    // 4. Verification of Predict The Output program
    std::cout << "\n--- 4. Predict The Output (Logger Struct) ---\n";
    std::cout << "Actual execution:   ";
    {
        Logger a("A");
        {
            Logger b("B");
        }
        use(a);
        Logger* p = new Logger("P");
        delete p;
        std::cout << "end ";
    }
    std::cout << "\nExpected output:   +A +B -B copyAc use -Ac +P -P end -A \n";

    return 0;
}
