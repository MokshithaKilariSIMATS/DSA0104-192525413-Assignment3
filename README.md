# SIMATS ENGINEERING (SAVEETHA SCHOOL OF ENGINEERING)
## Department of Artificial Intelligence and Machine Learning
### ASSIGNMENT 3 - CO3: Constructors, Destructors and Operator Overloading

- **Student Name:** Mokshitha Kilari
- **Register Number:** 192525413
- **Section / Batch:** SLOT-D
- **Course Code & Title:** DSA0104 - Object Oriented Programming using C++
- **C++ Compiler & Version:** `g++ (Rev4, Built by MSYS2 project) 16.2.0` (C++17 Standard)
- **C++ Compilation Flags:** `g++ -std=c++17 -Wall -Wextra main.cpp -o main`
- **Java Version:** `Java SE 17 / 21 (JDK)`
- **Java Compilation Command:** `javac Main.java && java Task0X.Main`
- **GitHub Repository Link:** [https://github.com/MokshithaKilariSIMATS/DSA0104-192525413-Assignment3](https://github.com/MokshithaKilariSIMATS/DSA0104-192525413-Assignment3)

---

## Repository Structure
```
DSA01-192525413-Assignment3/
├── README.md
├── Assignment3_Report_192525413.docx
├── Task01/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task02/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task03/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task04/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task05/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
├── Task06/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
└── Task07/ (main.cpp, Main.java, input.txt, output.txt, output_screenshot.png)
```

---

## Summary of Results by Task

### Task 01: Library Book Records (Constructors & Delegation)
- **Concept:** Default constructor, parameterized constructor, constructor delegation, member initializer list, and negative copy validation.
- **Result Note:** Verified all three creation modes and successfully trapped invalid negative copies via `std::invalid_argument`.
```terminal
[BOOK] "C++ Primer" | Author: Stanley Lippman | ISBN: 978-0321714114 | Copies: 5
[BOOK] "Clean Code" | Author: Community Donor | ISBN: DONATED-001 | Copies: 1
[BOOK] "Untitled Record" | Author: Unknown Author | ISBN: ISBN-PENDING | Copies: 0
Caught expected exception: Error: Number of copies cannot be negative (-3)
```

### Task 02: Hospital Prescription Records (Rule of Three)
- **Concept:** Custom deep-copy constructor, copy assignment operator with self-assignment guard, and destructor releasing dynamic array.
- **Result Note:** Independent copies verified; mutation of copy does not alter original; zero memory leaks under AddressSanitizer.
```terminal
Ibuprofen ORS | Paracetamol Cetirizine | Paracetamol ORS
Self-assignment test (p = p): Ibuprofen ORS (PASSED safely)
```

### Task 03: Auditorium Seat Booking (Dynamic 2D Memory Management)
- **Concept:** Dynamic 2D seat grid allocation with `new`, destructor releasing every row and row pointer, LIFO destruction order tracing.
- **Result Note:** Closing summary printed by destructor upon scope exit; verified Predict the Output sequence `+A +B -B copyAc use -Ac +P -P end -A`.
```terminal
[CONSTRUCT] Event "Symphony Concert" created with 5x10 seat grid.
[DESTRUCT] Closing summary for "Symphony Concert": 2/50 seats booked. All memory safely released.
Predict output: +A +B -B copyAc use -Ac +P -P end -A
```

### Task 04: Money Arithmetic (Billing Counter Operator Overloading)
- **Concept:** Overloading `+`, `==`, `<<` as member/friend operators with internal integer paise representation.
- **Result Note:** Exact monetary representation eliminates floating-point rounding errors seen in `double` over 1,000,000 additions.
```terminal
Rs 200.00
true
Carry paise into rupees (Rs 0.75 + Rs 0.50): Rs 1.25
```

### Task 05: Music Playlist & Track Timer (Increment & Subscript)
- **Concept:** Overloading prefix `++`, postfix `++` (int dummy), comparison `<`, and subscript `[]` with bounds checking.
- **Result Note:** Verified minute/hour rollover (59:59 -> 01:00:00), out-of-range exception handling on index -1 and size, and predicted output `5 7 7`.
```terminal
Rollover: 00:59:59 -> 01:00:00
Prefix/Postfix values: a=00:01:30, b=00:01:32, t1=00:01:32
Predict output: 5 7 7
```

### Task 06: Simple Text Class for SMS Gateway (Operator Overloading Rules)
- **Concept:** Dynamic string buffer, deep copying, overloading `+`, `==`, `!=`, self-assignment safety, and operator overloading restrictions.
- **Result Note:** Concatenation and comparisons executed cleanly with 0 memory leaks; C++17 copy elision eliminates redundant temporaries.
```terminal
Concatenation: "Hello World!"
Comparison check: (msg3 == check): true
Self-assignment: "Hello " (Safely intact)
```

### Task 07: AC Circuit Impedance Calculator (Complex Class Design)
- **Concept:** First-principles `Complex` class with overloaded arithmetic, division by zero domain checking, and RLC resonance calculations.
- **Result Note:** Series and parallel RLC network impedance matches hand-calculated values ($100.00 + 0.00j Ohms); division by zero safely trapped.
```terminal
Component: ZR = 100.00 + 0.00j | ZL = 0.00 + 100.00j | ZC = 0.00 - 100.00j
Series RLC Impedance: 100.00 + 0.00j | Magnitude = 100.00 Ohms
Parallel RLC Impedance: 100.00 + 0.00j | Magnitude = 100.00 Ohms
Caught expected error: Complex division by zero impedance!
```
