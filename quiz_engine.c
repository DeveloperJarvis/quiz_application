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

// --------------------------------------------------
// Quiz Engine Module
// --------------------------------------------------
/*
 * Responsibilties:
 * - Take user input for answers.
 * - Validate inputs
 * - Calculate score
 *
 * Functions
 * - char get_user_answer()
 * - void evaluate_answer(Question *q, char answer, Result *result)
 * - void start_quiz(Quiz *quiz, Result *result)
 */

// --------------------------------------------------
// header files
// --------------------------------------------------
#include <stdio.h> // for printf()
// #include <string.h> // for strcmp()
#include <ctype.h>  // for toupper()
#include <time.h>   // for time()
#include <stdlib.h> // for srand(), rand()

#include "quiz_application.h"

// --------------------------------------------------
// quiz engine functions
// --------------------------------------------------
char get_user_answer()
{
    char ch;
    while (1)
    {
        printf("Enter your answer (A/B/C/D): ");
        ch = getchar();

        clean_input_buffer(); // remove trailing newline

        if (is_valid_option(ch) == 0)
            return toupper((unsigned char)ch);

        printf("Invalid option! Please enter A, B, C or D.\n");
    }
}

void evaluate_answer(Question *q, char answer, Result *result)
{
    if (q == NULL || result == NULL)
        return; // safety check
    result->attempted_questions++;
    if (q->correct_option == answer)
    {
        result->correct_answers++;
        result->score++;
    }
    return;
}

void start_quiz(Quiz *quiz, Result *result)
{
    if (quiz == NULL || result == NULL)
        return;

    printf("\nStarting Quiz for %s...\n", result->user_name);
    printf("Total Questions: %d\n", quiz->total_questions);
    printf("----------------------------------\n");

    for (int i = 0; i < quiz->total_questions; i++)
    {
        Question *q = &quiz->questions[i];
        display_question(q, i + 1);
        char answer = get_user_answer();
        evaluate_answer(q, answer, result);
    }
    printf("\nQuiz Finished\n");
    return;
}

void shuffle_questions(Question *arr, int count)
{
    if (arr == NULL || count <= 1)
    {
        printf("shuffle questions: invalid arr or count=%d\n", count);
        return;
    }
    for (int i = (count - 1); i > 0; i--)
    {
        int j = rand() % (i + 1);
        Question temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    // printf("shuffled\n");
}

void initialize_quiz(Quiz *quiz, const char *filename)
{
    if (quiz == NULL || filename == NULL)
        return;

    // Reset total questions
    quiz->total_questions = 0;

    int total_loaded = load_questions(filename, quiz);
    if (total_loaded == 0)
    {
        printf("ERROR: No questions loaded.\n");
        quiz->total_questions = 0;
        return;
    }

    int final_count = (total_loaded < MAX_QUES_COUNT)
                          ? total_loaded
                          : MAX_QUES_COUNT;
    // printf("loaded questins %d final count %d\n", total_loaded, final_count);
    shuffle_questions(quiz->questions, final_count);

    quiz->total_questions = final_count;
}
