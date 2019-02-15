/**
 * This file is main skeleton file to hold the main function.
 * The production and testing suite will be called from here.
 *
 * Date: February 15, 2019
 * Author: Tom Graham
 */

#include <stdio.h>
#include <stdlib.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

/**
 * The main function of the program. This is used to call production and
 * also call the testing suite.
 * @param argc The number of arguments being passed.
 * @param argv[] The array of those arguments.
 * @return 0 on success and 1 otherwise
 */
int main(int argc, char *argv[]) {
	puts("!!!Hello class, we are working HW3B!!!");
	if(tests())
	{
		puts("Tests succeeded.");
		if(production(argc, argv))
		{
			puts("Production successful.");
		}
		else
		{
			puts("Tests succeeded, but production didn't");
		}
	}
	else
	{
		puts("Tests did not succeed.");
	}

	return EXIT_SUCCESS;
}
