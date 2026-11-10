// Assignment 3 - Q7: Complex AC Circuit Impedance Calculator
package Task07;

public class Main {
    public static class Complex {
        private final double real, imag;
        public Complex(double r, double i) { this.real = r; this.imag = i; }
        public Complex(double r) { this(r, 0); }
        public Complex() { this(0, 0); }

        public Complex add(Complex o) { return new Complex(real + o.real, imag + o.imag); }
        public Complex subtract(Complex o) { return new Complex(real - o.real, imag - o.imag); }
        public Complex multiply(Complex o) {
            return new Complex(real * o.real - imag * o.imag, real * o.imag + imag * o.real);
        }
        public Complex divide(Complex o) {
            double d = o.real * o.real + o.imag * o.imag;
            if (d == 0) throw new ArithmeticException("Division by zero complex impedance");
            return new Complex((real * o.real + imag * o.imag) / d, (imag * o.real - real * o.imag) / d);
        }
        public double magnitude() { return Math.sqrt(real * real + imag * imag); }
        @Override
        public String toString() {
            return String.format("%.2f %s %.2fj", real, (imag >= 0 ? "+" : "-"), Math.abs(imag));
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q7: Complex AC Impedance (Java Equivalent) ===");
        double R = 100.0, L = 0.1, C = 1e-5, omega = 1000.0;
        Complex ZR = new Complex(R, 0);
        Complex ZL = new Complex(0, omega * L);
        Complex ZC = new Complex(0, -1.0 / (omega * C));

        Complex Zseries = ZR.add(ZL).add(ZC);
        System.out.printf("Series RLC: %s | Magnitude: %.2f Ohms%n", Zseries, Zseries.magnitude());
    }
}
