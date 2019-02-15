/** tests.c
 * This file is the testing.c file. This file contains all the tests for
 * my code for HW3B. It is split up per function to provide better testing results.
 *
 * Date: February 15, 2019
 * Student: Tom Graham
 * Teacher/Previous Author: Mike Ciaraldi
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "tests.h"
#include "production.h"
#include "mystruct.h"

/**
 * This is the main boolean switch used to return if tests were all completed.
 * @return true if success and false otherwise
 */
bool tests(void)
{
	srand(time(0));
	bool ok1 = testPrintEmployee();
	if (ok1) {
		puts("printEmployee() passed.");
	}
	bool ok2 = testGenerateEmployee();
	if (ok2) {
		puts("GenerateEmployee() passed.");
	}
	bool ok3 = testMakeEmployee();
	if (ok3) {
		puts("MakeEmployee() passed.\n");
	}
	bool ok4 = testGenerateWorkforce();
	if (ok4){
		puts("GenerateWorkForce() passed. \n");
	}
	bool ok6 = testShallow();
	if (ok6){
		puts("ShallowCopy() passed. \n");
	}
	bool ok7 = testDeep();
	if (ok7){
		puts("DeepCopy() passed. \n");
	}
	return (ok1 && ok2 && ok3 && ok4 && ok6 && ok7);
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output so I've included it.
 */
bool testGenerateEmployee(void) {
	bool ok = false;
	struct Employee *b = generateEmployee();

	bool helperTest = false;

	if (generateChar() && generateName(1) && generateNumbers(0)){
		helperTest = true;
	}

	//Only run actual test if all the helper functions pass the tests.
	if (helperTest){
		if ((b) && b->birth_year > 1900){
			ok=true;
			printf("\nGenerateEmployee():  \n");
			printEmployee(b);
			ok = true;
		}
	}
	return ok;
}

/**
 * Test the printEmployee() function by creating a known struct and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testPrintEmployee(void) {
	struct Employee *b = generateEmployee();
	printf("\nPrintEmployee():  \n");
	printEmployee(b);
	return true;
}


/** Test the make Employee() function by making an employee with known data and printing it.
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testMakeEmployee(void) {
	char expected[] = "Mike Ciaraldi";
	struct Employee *e = makeEmployee(1952, 1999, "Mike Ciaraldi");
	bool ok = false;
	if ((e->birth_year == 1952)
			&& (e->start_year == 1999)
			&& (strcmp(expected, e->name) == 0))
		{
		ok = true;
		printf("\nMakeEmployee():  ");
		printf("\nEmployee Name: \t (%s, %s)\n", expected, e->name);
		printf("Birth Year:\t (%d, %d)\n", e->birth_year, 1952);
		printf("Start Year:\t (%d, %d)\n", e->start_year, 1999);
		}
	return ok;
}

/**
 * Test the function used to generate the work force!
 * @return true. The only way to tell if it succeeds is to look at the output.
 */
bool testGenerateWorkforce(void) {
	size_t count = 4; //employee structs to generate
	struct Employee **work = generateWorkforce(count);
	printf("\nPrintStructs():  \n");
	printStructs(work, count);
	return true;
}

/**
 * This function is used to test out the deep copy method.
 * @return true if pass false otherwise
 */
bool testDeep(void) {
	bool ok = true;
	size_t count = 4; //employee structs to generate
	struct Employee **work = generateWorkforce(count);
	struct Employee **test = deepCopyArray(work, count);
	while (*work++ ==  *test++)
		ok = false;
	return ok;
}

/**
 * This function is used to test out the shallow copy method.
 * @return true if pass false otherwise
 */
bool testShallow(void) {
	bool ok = false;
	size_t count = 4; //employee structs to generate
	struct Employee **work = generateWorkforce(count);
	struct Employee **test = shallowCopyArray(work, count);
	while (*test++ == *work++)
		ok = true;
	return ok;
}
