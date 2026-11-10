// Assignment 3 - Q2: Hospital Prescription Records
package Task02;

import java.util.Arrays;

public class Main {
    public static class Prescription implements Cloneable {
        private int n;
        private String[] medicines;

        public Prescription(int count) {
            this.n = count;
            this.medicines = new String[count];
        }

        // Deep copy constructor
        public Prescription(Prescription other) {
            this.n = other.n;
            this.medicines = Arrays.copyOf(other.medicines, other.n);
        }

        public void set(int i, String m) { medicines[i] = m; }
        public String get(int i) { return medicines[i]; }

        @Override
        public Prescription clone() {
            return new Prescription(this);
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q2: Prescription Deep Copy (Java Equivalent) ===");
        Prescription p = new Prescription(2);
        p.set(0, "Paracetamol");
        p.set(1, "ORS");

        Prescription q = new Prescription(p); // deep copy constructor
        q.set(1, "Cetirizine");

        Prescription r = new Prescription(p);
        p.set(0, "Ibuprofen");

        System.out.println(p.get(0) + " " + p.get(1) + " | " +
                           q.get(0) + " " + q.get(1) + " | " +
                           r.get(0) + " " + r.get(1));
    }
}
