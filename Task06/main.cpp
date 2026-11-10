#include <iostream>
#include <cstring>
#include <chrono>

class Text {
private:
    char* data;
    size_t length;

public:
    static int copyCount;

    // Parameterized Constructor
    Text(const char* s = "") {
        if (s == nullptr) s = "";
        length = std::strlen(s);
        data = new char[length + 1];
        std::strcpy(data, s);
    }

    // Deep Copy Constructor
    Text(const Text& other) {
        ++copyCount;
        length = other.length;
        data = new char[length + 1];
        std::strcpy(data, other.data);
    }

    // Deep Copy Assignment Operator with self-assignment guard
    Text& operator=(const Text& other) {
        if (this == &other) return *this; // Self-assignment prevention
        char* newData = new char[other.length + 1];
        std::strcpy(newData, other.data);
        delete[] data;
        data = newData;
        length = other.length;
        return *this;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    // Overload + for concatenation
    Text operator+(const Text& other) const {
        Text result;
        delete[] result.data;
        result.length = this->length + other.length;
        result.data = new char[result.length + 1];
        std::strcpy(result.data, this->data);
        std::strcat(result.data, other.data);
        return result;
    }

    // Equality comparison
    bool operator==(const Text& other) const {
        return std::strcmp(this->data, other.data) == 0;
    }

    // Inequality comparison
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    // Stream insertion
    friend std::ostream& operator<<(std::ostream& os, const Text& t) {
        os << t.data;
        return os;
    }

    size_t getLength() const { return length; }
    const char* c_str() const { return data; }
};

int Text::copyCount = 0;

int main() {
    std::cout << "=== Assignment 3 - Q6: Rules of Operator Overloading (SMS Gateway) ===\n\n";

    // 1. Basic concatenation and printing
    Text msg1("Hello ");
    Text msg2("World!");
    Text msg3 = msg1 + msg2;
    std::cout << "1. Concatenation: \"" << msg3 << "\"\n";

    // 2. Equality and Inequality testing
    Text check("Hello World!");
    std::cout << "2. Comparison check:\n";
    std::cout << "   (msg3 == check): " << std::boolalpha << (msg3 == check) << '\n';
    std::cout << "   (msg3 != msg1):  " << std::boolalpha << (msg3 != msg1) << '\n';

    // 3. Testing empty and long messages
    Text emptyMsg("");
    std::cout << "3. Empty Message: \"" << emptyMsg << "\" (len=" << emptyMsg.getLength() << ")\n";

    std::string longStr(160, 'S'); // 160-character standard SMS
    Text longMsg(longStr.c_str());
    std::cout << "   Long SMS Message length: " << longMsg.getLength() << " characters\n";

    // 4. Self-assignment verification
    msg1 = msg1;
    std::cout << "4. Self-assignment (msg1 = msg1): \"" << msg1 << "\" (Safely intact)\n";

    // 5. Copy count during chained concatenation a + b + c
    Text::copyCount = 0;
    Text a("Alpha-");
    Text b("Beta-");
    Text c("Gamma");
    Text d = a + b + c;
    std::cout << "5. Chained Concatenation: \"" << d << "\"\n";
    std::cout << "   Deep copies triggered during (a + b + c): " << Text::copyCount << '\n';

    return 0;
}
