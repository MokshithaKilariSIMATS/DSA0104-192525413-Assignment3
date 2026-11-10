// Assignment 3 - Q5: Time and Playlist
package Task05;

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static class Time implements Comparable<Time> {
        private int h, m, s;
        public Time(int h, int m, int s) {
            this.h = h; this.m = m; this.s = s;
            normalize();
        }
        private void normalize() {
            if (s >= 60) { m += s / 60; s %= 60; }
            if (m >= 60) { h += m / 60; m %= 60; }
        }
        public Time increment() {
            s++;
            normalize();
            return this;
        }
        @Override
        public int compareTo(Time o) {
            if (h != o.h) return Integer.compare(h, o.h);
            if (m != o.m) return Integer.compare(m, o.m);
            return Integer.compare(s, o.s);
        }
        @Override
        public String toString() {
            return String.format("%02d:%02d:%02d", h, m, s);
        }
    }

    public static class Playlist {
        private List<String> tracks = new ArrayList<>();
        public void addTrack(String t) { tracks.add(t); }
        public String get(int i) {
            if (i < 0 || i >= tracks.size()) throw new IndexOutOfBoundsException("Index " + i + " out of bounds");
            return tracks.get(i);
        }
        public int size() { return tracks.size(); }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q5: Time & Playlist (Java Equivalent) ===");
        Time t = new Time(0, 59, 59);
        System.out.println("Before: " + t);
        t.increment();
        System.out.println("After rollover: " + t);

        Playlist p = new Playlist();
        p.addTrack("Beethoven - Symphony No. 5");
        p.addTrack("Mozart - Requiem");
        System.out.println("Track 0: " + p.get(0));
    }
}
