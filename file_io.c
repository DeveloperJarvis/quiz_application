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
// File I/O Module
// --------------------------------------------------
/*
 * Responsibility:
 * - Read questions from file.
 * - Parse each line and populate Question structure.
 * - Handle file errors (missing file, format issues).
 *
 * Functions:
 * - int load_questions(const char *filename, Quiz *quiz)
 * - void save_results(const char *filename, Result *result)	(optional)
 */

// --------------------------------------------------
// header files
// --------------------------------------------------
#include <stdio.h>  // for printf(), scanf(), size_t
#include <string.h> // for strcmp()

#include "quiz_application.h"

char file_read_buffer[MAX_FILE_READ_SIZE];

// --------------------------------------------------
// file io functions
// --------------------------------------------------

// load questions from the file questions file
size_t load_questions(const char *filename, Quiz *quiz)
{
    FILE *fptr;
    // Open in read mode
    FOPEN(fptr, filename, "r");
    if (fptr == NULL)
    {
        printf("ERROR: opening file: %s for reading.\n", filename);
        return 0;
    }

    /*
     * 1. Read file contents into global buffer
     */
    // Read file safely
    size_t bytes_read = fread(file_read_buffer, 1, MAX_FILE_READ_SIZE - 1, fptr);

    // Always NULL terminate at bytes_read
    file_read_buffer[bytes_read] = '\0';

    // Closing file
    fclose(fptr);

    if (bytes_read == 0)
        return 0;

    // If file is too large fread will return exactly MAX_FILE_READ_SIZE - 1
    if (bytes_read == MAX_FILE_READ_SIZE - 1)
    {
        printf("WARNING: File truncated - buffer too small. %s",
               "Increase MAX_FILE_READ_SIZE.\n");
    }

    /*
     * 2. Parse file line-by-line
     */
    int qcount = 0;

    char *saveptr;
    char *line = strtok_r(file_read_buffer, "\n", &saveptr);

    quiz->total_questions = 0;

    while (line != NULL && quiz->total_questions < MAX_QUES_COUNT)
    {
        trim_newline(line);

        // Skip empty lines
        if (parse_question_line(line, &quiz->questions[quiz->total_questions]))
            quiz->total_questions++;
        line = strtok_r(NULL, "\n", &saveptr); // next line
    }

    // printf("load questions: %d\n", quiz->total_questions);
    // Now entire file is in file_read_buffer
    // return number of valid bytes
    return bytes_read;
}

// save results to results file
void save_results(const char *filename, Result *result)
{
    FILE *fptr;
    // Open in append mode
    FOPEN(fptr, filename, "a");
    if (fptr == NULL)
    {
        printf("ERROR: opening file: %s for adding results.\n", filename);
        return;
    }

    fprintf(fptr,
            "===============================\n"
            "Result for %s\n"
            "Score: %d\n"
            "Questions Attempted: %d\n"
            "Correct Answers: %d\n"
            "===============================\n",
            result->user_name,
            result->score,
            result->attempted_questions,
            result->correct_answers);

    // Closing file
    fclose(fptr);
    return;
}
