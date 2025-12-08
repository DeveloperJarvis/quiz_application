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
// Utility Module
// --------------------------------------------------
/*
 * Responsibilities
 * - Common helper functions
 * - String trimming, validation, parsing
 *
 * Functions
 * - void trim_newline(char *str)
 * - int is_valid_option(char c)
 */

// --------------------------------------------------
// header files
// --------------------------------------------------
#include <stdio.h>  // for printf(), scanf()
#include <string.h> // for strcmp()
#include <ctype.h>  // for isalpha(), toupper()

#include "quiz_application.h"

// --------------------------------------------------
// utility functions
// --------------------------------------------------
void trim_newline(char *str)
{
    if (str == NULL)
        return; // safety check
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n')
        str[len - 1] = '\0';
    return;
}

// Check if provided char is among A, B, C or D
int is_valid_option(char c)
{
    if (isalpha((unsigned char)c))
    {
        c = toupper((unsigned char)c);
        if (c == 'A' || c == 'B' || c == 'C' || c == 'D')
            return 1; // 1 -> is valid
    }
    return 0; // 0 -> is not valid
}

void clean_input_buffer()
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ; // Clean input buffer
    return;
}

int parse_question_line(char *line, Question *q)
{
    if (line == NULL || q == NULL)
        return 0;

    // There must be 8 fields
    char *fields[FIELDS_COUNT];
    int fcount = 0;

    char *p = line;
    fields[fcount++] = p;

    // Split using manual parsing for roburstness
    while (*p != '\0' && fcount < FIELDS_COUNT)
    {
        if (*p == '|')
        {
            *p = '\0';
            fields[fcount++] = p + 1;
        }
        p++;
    }

    // Not enough fields -> malformed
    if (fcount != FIELDS_COUNT)
        return 0;

    /*
     * fields map:
     * 0 = QID
     * 1 = QUESTION
     * 2 = A
     * 3 = B
     * 4 = C
     * 5 = D
     * 6 = CORRECT_OPTION
     * 7 = DIFFICULTY (ignored)
     */

    /*
    // Copy question text
    strncpy(q->question_text, fields[1], MAX_QUES_LEN - 1);
    q->question_text[MAX_OPTION_LEN - 1] = '\0';
    */
    // snprintf() slightly cleaner and handles truncation automatically
    // Do not call snprintf without "%s" that is unsafe
    // Copy question text
    snprintf(q->question_text, MAX_QUES_LEN, "%s", fields[1]);

    // Copy options
    snprintf(q->options.A, MAX_OPTION_LEN, "%s", fields[2]);
    snprintf(q->options.B, MAX_OPTION_LEN, "%s", fields[3]);
    snprintf(q->options.C, MAX_OPTION_LEN, "%s", fields[4]);
    snprintf(q->options.D, MAX_OPTION_LEN, "%s", fields[5]);

    // Correct option must be A/B/C/D
    char c = fields[6][0];
    c = toupper((unsigned char)c);

    if (c != 'A' && c != 'B' && c != 'C' && c != 'D')
        return 0;
    q->correct_option = c;

    return 1;
}