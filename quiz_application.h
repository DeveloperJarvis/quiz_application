// --------------------------------------------------
// -*- C -*- Compatibility Header
//
// Copyright (C) 2023 Developer Jarvis (Pen Name)
//
// This file is part of the quiz_application Library. This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 3, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//
// SPDX-License-Identifier: GPL-3.0-or-later
//
// quiz_application - Multi-choice quiz stored in a file
//
// Author: Developer Jarvis (Pen Name)
// Contact: https://github.com/DeveloperJarvis
//
// --------------------------------------------------
#ifndef QUIZ_APPLICATION_H
#define QUIZ_APPLICATION_H

// --------------------------------------------------
// constants and macros
// --------------------------------------------------
#if defined(_MSC_VER) || defined(_WIN32) || defined(_WIN64)
#define FOPEN(fptr, filename, mode) fopen_s(fptr, filename, mode)
#else
#define FOPEN(fptr, filename, mode) (fptr = fopen(filename, mode))
#endif

#define FIELDS_COUNT 8 // There must be 8 fields in a question line
#define MAX_QUES_LEN 100
#define MAX_OPTION_LEN 20
#define MAX_USER_NAME_LEN 20
#define MAX_FILE_READ_SIZE 204800 // 200KB safe for 1000 questions

// #define MAX_QUES_COUNT 20
// #define QUIZ_FILE "questions.txt"
// #define RESULTS_FILE "results.txt"

#define MAX_QUES_COUNT 20
#define QUIZ_FILE ".files/python.txt"
#define RESULTS_FILE ".files/python_results.txt"

extern char file_read_buffer[MAX_FILE_READ_SIZE]; // declaration only

typedef struct Options
{
	char A[MAX_OPTION_LEN];
	char B[MAX_OPTION_LEN];
	char C[MAX_OPTION_LEN];
	char D[MAX_OPTION_LEN];
} Options;

typedef struct Question
{
	int id;
	char question_text[MAX_QUES_LEN];
	Options options;
	char correct_option; // 'A'/'B'/'C'/'D'
} Question;

typedef struct Quiz
{
	Question questions[MAX_QUES_COUNT];
	int total_questions;
} Quiz;

typedef struct Result
{
	char user_name[MAX_USER_NAME_LEN];
	int score;
	int attempted_questions;
	int correct_answers;
} Result;

// --------------------------------------------------
// forward function declarations/ prototypes
// --------------------------------------------------

// display
void display_help(const char *s);
void display_version(const char *s);
void display_question(Question *q, int qid);
void display_result(Result *r);

// file io
size_t load_questions(const char *filename, Quiz *quiz);
void save_results(const char *filename, Result *result);

// quiz engine
void initialize_quiz(Quiz *quiz, const char *filename);
char get_user_answer();
void evaluate_answer(Question *q, char answer, Result *result);
void start_quiz(Quiz *quiz, Result *result);
void shuffle_questions(Question *arr, int count);

// result
void initialize_result(Result *r, const char *user_name);

// utility
void trim_newline(char *str);
int is_valid_option(char c);
void clean_input_buffer();
int parse_question_line(char *line, Question *q);

// main
void quiz_main();
void get_user_name(char *user_name);
#endif // QUIZ_APPLICATION_H
