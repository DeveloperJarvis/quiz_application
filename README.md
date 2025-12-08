# Quiz Application

**Multi-choice Quiz Application in C**
This command-line quiz program loads multiple-choice questions from a file, supports difficulty tagging, and allows users to take a scored quiz.

---

## **Table of Contents**

- [Overview](#overview)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Question File Format](#question-file-format)
- [Modules](#modules)
- [License](#license)

---

## **Overview**

The application reads structured quiz questions from `questions.txt`, each containing a difficulty level. Users answer the questions interactively, and the program evaluates and displays their score. The difficulty tag helps sort, filter, or report questions based on toughness.

---

## **Features**

✔ Read multi-choice questions from file
✔ Support for **difficulty levels** (Easy, Medium, Hard)
✔ Validate user inputs
✔ Score summary at the end
✔ Optional result saving
✔ Modular C design

### **New Feature: Difficulty Tag**

Each question now includes a difficulty rating so the system knows how tough the question is.

Supported difficulty levels:

- **E** → Easy
- **M** → Medium
- **H** → Hard

This can later be used for:

- scoring weights
- filtering questions
- adaptive difficulty
- categorized statistics

---

## **Installation**

```bash
gcc -o quiz_app main.c quiz_engine.c file_io.c utils.c
```

---

## **Usage**

Run:

```bash
./quiz_app
```

---

## **Question File Format**

Each line in `questions.txt` should follow this 8-field format:

```
QID | QUESTION | OPT_A | OPT_B | OPT_C | OPT_D | CORRECT_OPTION | DIFFICULTY
```

Fields are separated by `|`.

### **Example:**

```
Q1|What is the capital of France?|A) Berlin|B) London|C) Paris|D) Rome|C|E
Q2|Which language is used for system programming?|A) Python|B) C|C) HTML|D) Java|B|M
Q3|Solve: 55 * 89?|A) 4895|B) 3005|C) 5040|D) 4890|A|H
```

### Meaning:

- `Q1` → Question ID
- Real question text
- Four options
- `C` → Correct answer
- `E` → Difficulty = Easy
- `M` → Difficulty = Medium
- `H` → Difficulty = Hard

---

## **Modules**

### 1. **File I/O Module**

- Load questions
- Parse difficulty
- Save results

### 2. **Quiz Engine**

- Ask questions
- Validate inputs
- Score answers
- Track difficulty-based stats (optional)

### 3. **Utils Module**

- String splitting
- Trimming
- Input handling

### 4. **Results Module**

- Show summary
- Save stats to file

---

## **License**

Licensed under **GPL-3.0-or-later**.

---

**Author:** Developer Jarvis (Pen Name)
**GitHub:** [https://github.com/DeveloperJarvis](https://github.com/DeveloperJarvis)
