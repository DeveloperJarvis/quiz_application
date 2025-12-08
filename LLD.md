# **Low-Level Design (LLD)** for a **C-based multiple-choice quiz application**

## **1. Overview**

The application allows a user to:

- Load multiple-choice questions from a file.
- Take a quiz.
- Record and display the score.
- Optionally save results.

---

## **2. Core Modules**

### **2.1. Data Structures**

Define clear structures to hold quiz data:

1. **Question**

```text
- id: int
- question_text: string
- options: array of strings (A, B, C, D)
- correct_option: char ('A'/'B'/'C'/'D')
```

2. **Quiz**

```text
- questions: array of Question
- total_questions: int
```

3. **Result**

```text
- user_name: string
- score: int
- attempted_questions: int
- correct_answers: int
```

---

## 2.2 **Question File Format**

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

#### **Explanation:**

- `|` is used as a delimiter.
- Second last field is the correct answer.

#### **Meaning:**

- `Q1` → Question ID
- Real question text
- Four options
- `C` → Correct answer
- `E` → Difficulty = Easy
- `M` → Difficulty = Medium
- `H` → Difficulty = Hard

---

### **2.3. Modules**

#### **2.3.1. File I/O Module**

**Responsibilities:**

- Read questions from file.
- Parse each line and populate `Question` structure.
- Handle file errors (missing file, format issues).

**Functions:**

- `int load_questions(const char* filename, Quiz* quiz)`
- `void save_results(const char* filename, Result* result)` (optional)

---

#### **2.3.2. Quiz Engine Module**

**Responsibilities:**

- Display questions and options to the user.
- Take user input for answers.
- Validate inputs.
- Calculate score.

**Functions:**

- `void display_question(Question* q)`
- `char get_user_answer()`
- `void evaluate_answer(Question* q, char answer, Result* result)`
- `void start_quiz(Quiz* quiz, Result* result)`

---

#### **2.3.3. Result Module**

**Responsibilities:**

- Track correct answers, score, and attempted questions.
- Display final results.

**Functions:**

- `void initialize_result(Result* r, const char* user_name)`
- `void display_result(Result* r)`

---

#### **2.3.4. Utility Module**

**Responsibilities:**

- Common helper functions.
- String trimming, validation, parsing.

**Functions:**

- `void trim_newline(char* str)`
- `int is_valid_option(char c)`

---

### **3. Flow Diagram / Execution Flow**

1. **Start Application**

   - Prompt for user name.

2. **Load Questions**

   - Open `questions.txt`
   - Parse questions into `Quiz` structure

3. **Take Quiz**

   - Loop over each question
   - Display question and options
   - Get user answer
   - Evaluate and update score

4. **Display Results**

   - Show correct answers and final score
   - Optionally save to `results.txt`

5. **Exit**

---

### **4. Error Handling**

- File not found → show error and exit.
- Invalid input → prompt again.
- Empty quiz → exit gracefully.

---

### **5. Optional Enhancements**

- Timer for each question.
- Randomize question order.
- Track high scores.
- Multiple quizzes from different files.
- Categorize questions by topic.
