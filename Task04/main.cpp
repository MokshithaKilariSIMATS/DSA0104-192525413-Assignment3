#include <iomanip>
#include <iostream>
#include <vector>

class Money {
private:
    long long paise;

public:
    // Constructor handles rupees and paise, converting all internally to integer paise
    Money(long long rupees = 0, int p = 0) : paise(rupees * 100 + p) {}

    // TODO 1: Overload + as a member function that returns a new Money object
    Money operator+(const Money& other) const {
        Money res;
        res.paise = this->paise + other.paise;
        return res;
    }

    // TODO 2: Overload == as a member, and << as a friend that prints "Rs 200.00"
    bool operator==(const Money& other) const {
        return this->paise == other.paise;
    }

    friend std::ostream& operator<<(std::ostream& os, const Money& m) {
        long long r = m.paise / 100;
        long long p = m.paise % 100;
        if (p < 0) p = -p;
        os << "Rs " << r << '.' << std::setw(2) << std::setfill('0') << p;
        return os;
    }

    // Additional overloaded operators for comprehensive billing counter support
    Money operator-(const Money& other) const {
        Money res;
        res.paise = this->paise - other.paise;
        return res;
    }

    Money& operator+=(const Money& other) {
        this->paise += other.paise;
        return *this;
    }

    bool operator<(const Money& other) const {
        return this->paise < other.paise;
    }

    long long getPaise() const { return paise; }
};

int main() {
    std::cout << "=== Assignment 3 - Q4: Money Arithmetic & Operator Overloading ===\n\n";

    // Official Assignment Task Execution
    Money a(120, 75), b(79, 25);
    Money c = a + b;
    std::cout << "Official Task Output:\n";
    std::cout << c << '\n' << std::boolalpha << (c == Money(200)) << '\n';

    // Experimental Investigation 1: Carry paise into rupees (Rs 0.75 + Rs 0.50)
    std::cout << "\nExperimental Tests:\n";
    Money p1(0, 75), p2(0, 50);
    Money pSum = p1 + p2;
    std::cout << "1. Carry paise into rupees (Rs 0.75 + Rs 0.50): " << pSum << '\n';

    // Experimental Investigation 2: Subtraction producing negative amount
    Money subRes = b - a;
    std::cout << "2. Subtraction producing negative amount (79.25 - 120.75): " << subRes << '\n';

    // Experimental Investigation 3: Floating point precision comparison (1,000,000 additions of 0.10)
    std::cout << "\n3. Precision Comparison: Money (integer paise) vs double (1,000,000 additions of Rs 0.10):\n";
    Money moneyAccum(0, 0);
    Money tenPaise(0, 10);
    double doubleAccum = 0.0;
    for (int i = 0; i < 1000000; ++i) {
        moneyAccum += tenPaise;
        doubleAccum += 0.10;
    }
    std::cout << "   - Money (integer paise) exact total: " << moneyAccum << '\n';
    std::cout << "   - Double accumulation total:        Rs " << std::fixed << std::setprecision(6) << doubleAccum << '\n';
    std::cout << "   - Discrepancy observed in double due to binary float representation: " 
              << (doubleAccum - 100000.0) << " error!\n";

    return 0;
}
