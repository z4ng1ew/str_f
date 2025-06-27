## 🔣 s21\_string+ — Custom Implementation of `string.h`

This project implements the C `string.h` library from scratch with extended functionality such as partial `sprintf` / `sscanf` and custom string manipulation functions.

It reinforces key skills in:

* manual memory management
* pointer logic
* format specifier parsing
* unit testing with `Check`
* POSIX-compliant development in C11

> 🧠 Developed as part of the School 21 educational program.

---

### 📁 Project Structure

```bash
Final_vers_str/
├── src/
│   ├── s21_string.h          # Header file with function prototypes
│   ├── s21_string.c          # Main implementation of string.h functions
│   ├── s21_sprintf.c         # sprintf logic (basic + bonus)
│   ├── s21_sscanf.c          # sscanf implementation (bonus)
│   ├── s21_utils.c           # Helper functions (optional)
│   └── Makefile              # Build script
│
├── tests/
│   ├── test_string.c         # Unit tests for string functions
│   ├── test_sprintf.c        # Unit tests for sprintf
│   ├── test_sscanf.c         # Unit tests for sscanf
│   └── test_utils.c          # Helper tests
│
└── README.md
```

---

### ✅ Implemented Features

#### 🧵 Core string.h functions

* `memchr`, `memcmp`, `memcpy`, `memset`
* `strncat`, `strchr`, `strncmp`, `strncpy`
* `strcspn`, `strerror`, `strlen`, `strpbrk`
* `strrchr`, `strstr`, `strtok`

#### 🧮 sprintf (basic)

* Specifiers: `c`, `d`, `f`, `s`, `u`, `%`
* Flags: `-`, `+`, ` ` (space)
* Width: number
* Precision: `.number`
* Length modifiers: `h`, `l`

#### 🎯 sprintf (bonus)

* Specifiers: `g`, `G`, `e`, `E`, `x`, `X`, `o`, `p`
* Flags: `#`, `0`
* Width: `*`
* Precision: `.*`
* Length modifier: `L`

#### 📥 sscanf (bonus)

* Full support for parsing via format strings
* Specifiers: all from C99 standard

#### ✂️ Custom string functions

* `to_upper` — convert to uppercase
* `to_lower` — convert to lowercase
* `insert` — insert substring at position
* `trim` — trim leading/trailing characters

---

### 🧪 Unit Testing

* Written using the **Check** framework
* Behavior compared with standard `string.h`
* > 80% coverage for each function
* Code coverage analysis via `gcov`

---

### 🛠️ Build & Run

```bash
make all           # Build the static library and tests
make test          # Run all unit tests
make gcov_report   # Generate HTML coverage report (in build/)
make clean         # Remove build artifacts
```

---

### 💡 Technologies

* `C11` standard
* `POSIX.1-2017` compatibility
* `GCC`, `Make`, `Check`, `gcov`, `lcov`

---

### 📌 Notes

* Prefix `s21_` used for all functions
* Static library output: `s21_string.a`
* Manual error description for `strerror` (no system sys\_errlist)

---

### 🌐 Author

**👤 z4ng1ew** — [GitHub](https://github.com/z4ng1ew)
Project completed as part of **School 21** curriculum.

---
