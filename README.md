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

🛠️ Concepts & Technologies Applied
Language: C++

Modular Programming: Separating core utility functions into a custom header file (#include "MyLib.h").

Data Structures & Enums: Using struct for game statistics management and enQuestionLevel / enOperationType for clean type safety.

Control Flow: Robust do-while loops for input validation and switch-case statements for game logic execution.

Randomization: Utilizing <cstdlib> and <ctime> for dynamic question and operation generation.

⚙️ How to Compile and Run
Clone the repository:

Bash
git clone [https://github.com/zahyehdassan77-eng/Math-Game-CPP.git](https://github.com/zahyehdassan77-eng/Math-Game-CPP.git)
Navigate to the project directory:

Bash
cd Math-Game-CPP
Compile the source code (Ensure both main.cpp and MyLib.h are in the same directory):

Bash
g++ main.cpp -o math_game
Run the executable:

On Windows:

Bash
math_game.exe
On Linux / macOS:

Bash
./math_game

👤 Author
Ibrahim Al-Tarifi

Passionate software development student focused on algorithms, problem-solving, and C++.
