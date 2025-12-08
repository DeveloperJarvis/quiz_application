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
 * - Display questions and options to the user.
 * - Display final results
 * -
 *
 * Functions
 * - void display_question(Question *q)
 * - void display_result(Result *r)
 * -
 */

// --------------------------------------------------
// header files
// --------------------------------------------------
#include <stdio.h>  // for printf(), scanf()
#include <string.h> // for strcmp()

#include "quiz_application.h"

// --------------------------------------------------
// display functions
// --------------------------------------------------

// Display program help
void display_help(const char *s)
{
    printf("Usage: %s [options]\n", s);
    printf(" -h --help\tDisplay program help\n");
    printf(" -v --version\tDisplay program version\n");
    printf("Good luck with quiz\n");
    return;
}

// Display program version
void display_version(const char *s)
{
    printf("%s version: 1.0.0\n", s);
    return;
}

// Display the question in nice format
void display_question(Question *q, int qid)
{
    printf("Q%d %s\nA) %s\nB) %s\nC) %s\nD)%s\n",
           qid,
           q->question_text,
           q->options.A,
           q->options.B,
           q->options.C,
           q->options.D);
    return;
}

// Display final result in good format
void display_result(Result *r)
{
    printf("===============================\n"
           "Result for %s\n"
           "Score: %d\n"
           "Questions Attempted: %d\n"
           "Correct Answers: %d\n"
           "===============================\n",
           r->user_name,
           r->score,
           r->attempted_questions,
           r->correct_answers);
    return;
}