#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdexcept>
#include <complex>

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor: 0 + 0j
    Complex() : real(0.0), imag(0.0) {}

    // Constructor from real part: r + 0j
    Complex(double r) : real(r), imag(0.0) {}

    // Full constructor from real and imaginary parts: r + ij
    Complex(double r, double i) : real(r), imag(i) {}

    // Getters
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Magnitude: sqrt(real^2 + imag^2)
    double magnitude() const {
        return std::sqrt(real * real + imag * imag);
    }

    // Phase angle in radians
    double phase() const {
        return std::atan2(imag, real);
    }

    // Arithmetic operators
    Complex operator+(const Complex& o) const {
        return Complex(real + o.real, imag + o.imag);
    }

    Complex operator-(const Complex& o) const {
        return Complex(real - o.real, imag - o.imag);
    }

    // Multiplication: (ac - bd) + j(ad + bc)
    Complex operator*(const Complex& o) const {
        return Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
    }

    // Division: ((ac + bd) + j(bc - ad)) / (c^2 + d^2)
    Complex operator/(const Complex& o) const {
        double denom = o.real * o.real + o.imag * o.imag;
        if (denom == 0.0) {
            throw std::domain_error("Complex division by zero impedance!");
        }
        return Complex((real * o.real + imag * o.imag) / denom,
                       (imag * o.real - real * o.imag) / denom);
    }

    bool operator==(const Complex& o) const {
        return std::abs(real - o.real) < 1e-9 && std::abs(imag - o.imag) < 1e-9;
    }

    // Stream output: e.g. "100.00 + 50.00j" or "100.00 - 50.00j"
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << std::fixed << std::setprecision(2) << c.real;
        if (c.imag >= 0) {
            os << " + " << c.imag << "j";
        } else {
            os << " - " << -c.imag << "j";
        }
        return os;
    }
};

int main() {
    std::cout << "=== Assignment 3 - Q7: Complex-Number AC Circuit Impedance Calculator ===\n\n";

    // Circuit Parameters:
    // R = 100 Ohms, L = 0.1 H, C = 10 microFarad (1e-5 F), omega = 1000 rad/s
    double R = 100.0;
    double L = 0.1;
    double C = 1e-5;
    double omega = 1000.0;

    Complex ZR(R, 0.0);
    Complex ZL(0.0, omega * L);          // 0 + j(100)
    Complex ZC(0.0, -1.0 / (omega * C)); // 0 - j(100)

    std::cout << "Component Impedances at omega = 1000 rad/s:\n";
    std::cout << "  Resistor  ZR: " << ZR << " | |ZR| = " << ZR.magnitude() << " Ohms\n";
    std::cout << "  Inductor  ZL: " << ZL << " | |ZL| = " << ZL.magnitude() << " Ohms\n";
    std::cout << "  Capacitor ZC: " << ZC << " | |ZC| = " << ZC.magnitude() << " Ohms\n\n";

    // 1. Series RLC Circuit: Z_series = ZR + ZL + ZC
    Complex Z_series = ZR + ZL + ZC;
    std::cout << "1. Series RLC Impedance:\n";
    std::cout << "   Z_series = " << Z_series << '\n';
    std::cout << "   |Z_series| = " << Z_series.magnitude() << " Ohms (Resonance condition: inductive and capacitive cancel)\n\n";

    // 2. Parallel RLC Circuit: 1/Z_parallel = 1/ZR + 1/ZL + 1/ZC
    // For two branch: Z12 = (ZL * ZC) / (ZL + ZC)
    Complex one(1.0, 0.0);
    Complex Y_parallel = (one / ZR) + (one / ZL) + (one / ZC);
    Complex Z_parallel = one / Y_parallel;
    std::cout << "2. Parallel RLC Impedance:\n";
    std::cout << "   Z_parallel = " << Z_parallel << '\n';
    std::cout << "   |Z_parallel| = " << Z_parallel.magnitude() << " Ohms\n\n";

    // 3. Division by Zero Safe Exception Test
    std::cout << "3. Safe Handling of Division by Zero:\n";
    try {
        std::cout << "   Attempting Z1 / (0 + 0j)...\n";
        Complex zero(0.0, 0.0);
        Complex bad = ZR / zero;
        std::cout << "   Result: " << bad << '\n';
    } catch (const std::domain_error& err) {
        std::cout << "   Successfully caught expected error: " << err.what() << '\n';
    }

    return 0;
}
