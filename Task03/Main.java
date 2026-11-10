// Assignment 3 - Q3: Auditorium Seat Booking
package Task03;

public class Main {
    public static class Auditorium implements AutoCloseable {
        private String eventName;
        private int rows, cols;
        private char[][] seatMap;

        public Auditorium(String name, int r, int c) {
            this.eventName = name;
            this.rows = r;
            this.cols = c;
            this.seatMap = new char[r][c];
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) seatMap[i][j] = '.';
            }
            System.out.printf("[CONSTRUCT] Event "%s" created with %dx%d grid.%n", name, r, c);
        }

        public void bookSeat(int r, int c) {
            if (r >= 0 && r < rows && c >= 0 && c < cols) seatMap[r][c] = 'X';
        }

        @Override
        public void close() {
            int booked = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) if (seatMap[i][j] == 'X') booked++;
            }
            System.out.printf("[CLOSE / DESTRUCT] Event "%s": %d/%d seats booked. Resources closed.%n",
                    eventName, booked, rows * cols);
        }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q3: Dynamic Auditorium Seats (Java Equivalent) ===");
        try (Auditorium event = new Auditorium("Symphony Concert", 5, 10)) {
            event.bookSeat(0, 0);
            event.bookSeat(2, 4);
        } // AutoCloseable simulates C++ deterministic RAII destructor
    }
}
