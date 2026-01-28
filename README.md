# YKS Study Tracker (C Project)

It's my first project on Github.
A command-line based study tracking system designed for students preparing for university entrance exams (YKS).
This program allows users to log their daily question counts and study hours, and provides detailed statistical analysis.
Since this project targets the Turkish education system (YKS), the command-line interface and code comments are in Turkish.

## Features

* **Data Persistence:** Reads and writes study data to a local `data.txt` file.
* **Detailed Statistics:** Calculates total solved questions (TYT/AYT) and average study hours.
* **Efficiency Analysis:** Calculates "Questions per Hour" to determine study efficiency.
* **Threshold Analysis:** Filters days where the user exceeded a specific number of questions.
* **Min/Max Analysis:** Identifies the most and least productive days.

## Installation & Usage

1.  Clone the repository:
    ```bash
    git clone https://github.com/ietkose/yks-tracker.git
    ```
2.  Compile the C file (using GCC):
    ```bash
    gcc main.c -o tracker
    ```
3.  Run the application:
    * **Windows:** `tracker.exe`
    * **Linux/Mac:** `./tracker`

## File Structure

* `main.c`: The source code containing all logic and menu functions.
* `data.txt`: Stores the daily logs.
  * **Format:** `tyt_soru ayt_soru calisma_saati`
  * **Description:** Columns represent TYT Question Count, AYT Question Count, and Study Hours respectively.

## Tech Stack

* **Language:** C
* **Concepts:** File I/O, Structs (Logic), Arrays, Loops, Modular Programming.
