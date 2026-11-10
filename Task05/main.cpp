#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <iomanip>
#include <chrono>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

    void normalize() {
        if (seconds >= 60) {
            minutes += seconds / 60;
            seconds %= 60;
        }
        if (minutes >= 60) {
            hours += minutes / 60;
            minutes %= 60;
        }
    }

public:
    Time(int h = 0, int m = 0, int s = 0) : hours(h), minutes(m), seconds(s) {
        normalize();
    }

    // Prefix increment: ++t (advances by 1 second, returns reference to *this)
    Time& operator++() {
        ++seconds;
        normalize();
        return *this;
    }

    // Postfix increment: t++ (advances by 1 second, returns old copy)
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }

    // Equality comparison
    bool operator==(const Time& o) const {
        return hours == o.hours && minutes == o.minutes && seconds == o.seconds;
    }

    // Less-than comparison
    bool operator<(const Time& o) const {
        if (hours != o.hours) return hours < o.hours;
        if (minutes != o.minutes) return minutes < o.minutes;
        return seconds < o.seconds;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << std::setfill('0') << std::setw(2) << t.hours << ':'
           << std::setfill('0') << std::setw(2) << t.minutes << ':'
           << std::setfill('0') << std::setw(2) << t.seconds;
        return os;
    }
};

class Playlist {
private:
    std::vector<std::string> tracks;

public:
    void addTrack(const std::string& track) { tracks.push_back(track); }
    size_t size() const { return tracks.size(); }

    // Non-const subscript operator with bounds check
    std::string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size())) {
            throw std::out_of_range("Playlist index " + std::to_string(index) + " is out of range [0, " + std::to_string(tracks.size()-1) + "]");
        }
        return tracks[index];
    }

    // Const subscript operator with bounds check
    const std::string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size())) {
            throw std::out_of_range("Playlist index " + std::to_string(index) + " is out of range [0, " + std::to_string(tracks.size()-1) + "]");
        }
        return tracks[index];
    }
};

// Counter struct for Predict the Output
struct Counter {
    int v;
    Counter& operator++() { ++v; return *this; } // prefix
    Counter operator++(int) { Counter old = *this; ++v; return old; } // postfix
};

int main() {
    std::cout << "=== Assignment 3 - Q5: Increment, Comparison & Subscript Operators ===\n\n";

    // 1. Time rollover verification (59:59 -> 1:00:00)
    Time tRoll(0, 59, 59);
    std::cout << "1. Rollover Test:\n   Before: " << tRoll << '\n';
    ++tRoll;
    std::cout << "   After ++t: " << tRoll << " (Verified 59:59 -> 1:00:00)\n\n";

    // 2. Prefix vs Postfix behavior verification
    Time t1(0, 1, 30);
    Time a = t1++; // a gets 00:01:30, t1 becomes 00:01:31
    Time b = ++t1; // t1 becomes 00:01:32, b gets 00:01:32
    std::cout << "2. Prefix/Postfix values:\n   a (from t++): " << a << "\n   b (from ++t): " << b << "\n   final t1:     " << t1 << "\n\n";

    // 3. Playlist subscripting and range check
    Playlist list;
    list.addTrack("Beethoven - Symphony No. 5");
    list.addTrack("Mozart - Requiem");
    list.addTrack("Bach - Air on the G String");

    std::cout << "3. Playlist Access via operator[]:\n";
    for (size_t i = 0; i < list.size(); ++i) {
        std::cout << "   [" << i << "] " << list[i] << '\n';
    }

    std::cout << "\n4. Range Check Boundary Tests:\n";
    try {
        std::cout << "   Attempting playlist[-1]...\n";
        std::cout << list[-1] << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "   Caught: " << e.what() << '\n';
    }

    try {
        std::cout << "   Attempting playlist[size] (index 3)...\n";
        std::cout << list[3] << '\n';
    } catch (const std::out_of_range& e) {
        std::cout << "   Caught: " << e.what() << '\n';
    }

    // 5. Predict the Output Verification
    std::cout << "\n5. Predict the Output Verification:\n   Actual:   ";
    {
        Counter c{5};
        Counter a = c++;
        Counter b = ++c;
        std::cout << a.v << ' ' << b.v << ' ' << c.v << '\n';
    }
    std::cout << "   Expected: 5 7 7\n";

    return 0;
}
