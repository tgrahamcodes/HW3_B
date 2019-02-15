/** tests.h
 * This file is used as a header for my test.c file. This file will list all the
 * function prototypes.
 *
 * Date: February 15, 2019
 * Student: Tom Graham
 * Teacher/Previous Author: Mike Ciaraldi
 */

#ifndef TESTS_H_
#define TESTS_H_

#include <stdbool.h>
#include "production.h"

// Function prototypes:
bool tests(void);
bool testPrintEmployee(void);
bool testMakeEmployee(void);
bool testGenerateEmployee(void);
bool testGenerateWorkforce(void);
bool testPrintStructs(void);
bool testShallow(void);
bool testDeep(void);
bool testFree(void);
#endif /* TESTS_H_ */
