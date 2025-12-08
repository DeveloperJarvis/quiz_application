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
// Result Module
// --------------------------------------------------
/*
 * Responsibilities
 * - Track correct answers, score and attempted questions
 *
 * Functions
 * - void initialize_result(Result *r, const char *user_name)
 */

// --------------------------------------------------
// header files
// --------------------------------------------------
#include <stdio.h>  // for printf(), scanf()
#include <string.h> // for strcmp()

#include "quiz_application.h"

// --------------------------------------------------
// result function
// --------------------------------------------------
void initialize_result(Result *r, const char *user_name)
{
    if (r == NULL)
        return; // Safety check
    // snprintf() automatically terminates safely and null - terminates
    snprintf(r->user_name, MAX_USER_NAME_LEN, "%s", user_name ? user_name : "");
    r->score = 0;
    r->attempted_questions = 0;
    r->correct_answers = 0;
    return;
}