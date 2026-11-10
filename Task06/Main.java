// Assignment 3 - Q6: Text Class for SMS Gateway
package Task06;

public class Main {
    public static class Text {
        private final String content;
        public Text(String s) { this.content = (s == null) ? "" : s; }
        public Text concat(Text o) { return new Text(this.content + o.content); }
        public int length() { return content.length(); }
        @Override
        public boolean equals(Object o) {
            if (o instanceof Text) return this.content.equals(((Text) o).content);
            return false;
        }
        @Override
        public String toString() { return content; }
    }

    public static void main(String[] args) {
        System.out.println("=== Assignment 3 - Q6: SMS Gateway Text (Java Equivalent) ===");
        Text msg1 = new Text("Hello ");
        Text msg2 = new Text("World!");
        Text msg3 = msg1.concat(msg2);
        System.out.println("Combined: " + msg3);
        System.out.println("Equals check: " + msg3.equals(new Text("Hello World!")));
    }
}
