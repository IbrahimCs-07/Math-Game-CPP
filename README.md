# Math-Game-CPP
A console-based Math Game built using C++

# 🧮 Advanced Math Game (C++)

A comprehensive, console-based Math Game built using **C++** as part of advanced programming practice and modular software design. The project features dynamic difficulty scaling, multiple arithmetic operations, interactive console coloring, and a **custom utility header library (`MyLib.h`)** for reusable helper functions.

---

## 🚀 Key Features

* **Customizable Round Length:** Choose how many questions to solve per session (1 to 20 questions).
* **Multiple Difficulty Levels:**
  * **Easy:** Range from 1 to 10
  * **Medium:** Range from 25 to 45
  * **Hard:** Range from 50 to 89
  * **Mix:** Dynamically randomized difficulty levels per question
* **Diverse Arithmetic Operations:** Addition (`+`), Subtraction (`-`), Multiplication (`*`), Division (`/`), or a complete **Mix** of operations.
* **Modular Architecture:** Utilizes a custom-built header library (`MyLib.h`) containing reusable functions for input validation, random number generation, and UI formatting.
* **Dynamic Interactive UI:** Real-time console color changes reflecting correct answers and overall pass/fail status, alongside custom headers and spacing.
* **Replayability:** Fully integrated game-loop allowing players to restart multiple rounds without restarting the application.

---

## 📁 Project Structure

The project is structured cleanly following modular programming principles:

```text
Math-Game-CPP/
│
├── main.cpp         # Core game logic, state management, and execution loop
├── MyLib.h          # Custom utility library (Input handling, Random ranges, UI formatting)
└── README.md        # Comprehensive project documentation
