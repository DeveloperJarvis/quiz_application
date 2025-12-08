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
// header files
// --------------------------------------------------
#include <stdio.h>	// for printf(), scanf()
#include <string.h> // for strcmp()

#include "quiz_application.h"

// --------------------------------------------------
// main function
// --------------------------------------------------
int main(int argc, const char *argv[])
{
	if (argc == 1)
		quiz_main();
	if (argc == 2)
	{
		if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--version") == 0)
			display_help(argv[0]);
		else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)
			display_version(argv[0]);
		else
			quiz_main();
	}
	else
	{
		printf("Invalid Input.\n");
		display_help(argv[0]);
	}
	return 0;
}

// --------------------------------------------------
// main quiz function
// --------------------------------------------------

// intialize, load questions start quiz and display result and store
void quiz_main()
{
	Result *result;
	Quiz *quiz;
	initialize_quiz(quiz);
	char user_name[MAX_USER_NAME_LEN];
	get_user_name(user_name);
	initialize_result(result, user_name);
	start_quiz(quiz, result);
	display_result(result);
}

// gets user's name
void get_user_name(char *user_name)
{
	printf("Please enter your name: ");
	if (scanf("%s", user_name) != 1)
	{
		printf("Invalid input\n");
		clean_input_buffer();
	}
	user_name[MAX_USER_NAME_LEN - 1] = '\0';
	return;
}