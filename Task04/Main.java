// Assignment 3 - Q4: Money Arithmetic
package Task04;

public class Main {
    public static class Money implements Comparable<Money> {
        private final long paise;

        public Money(long rupees, int p) {
            this.paise = rupees * 100 + p;
        }

        public Money(long totalPaise) {
            this.paise = totalPaise;
        }

        public Money add(Money o) { return new Money(this.paise + o.paise); }
        public Money subtract(Money o) { return new Money(this.paise - o.paise); }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) return true;
            if (obj instanceof Money) return this.paise == ((Money) obj).paise;
            return false;
        }

        @Override
        public int compareTo(Money o) {
            return Long.compare(this.paise, o.paise);
        }

        @Override
        public String toString() {
            long r = paise / 100;
            long p = Math.abs(paise % 100);
            return String.format("Rs %d.%02d", r, p);
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q4: Money Arithmetic (Java Equivalent) ===");
        Money a = new Money(120, 75);
        Money b = new Money(79, 25);
        Money c = a.add(b);

        System.out.println(c);
        System.out.println(c.equals(new Money(200, 0)));
    }
}
