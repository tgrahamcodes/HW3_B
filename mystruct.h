/** mystruct.h
 * This file is main skeleton file to hold the main function.
 * The production and testing suite will be called from here.
 *
 * Date: February 15, 2019
 * Student: Tom Graham
 * Author: Mike Ciaraldi
 */

// Struct definition:

// Maximum number of characters in an employee name
#define MAX_NAME (99)

#include <stdlib.h>

/**
 * The struct for the employee. My pseudo object.
 */
struct Employee {
	int birth_year; // Year the employee was born
	int start_year; // When the employee started with the company.
	char name[MAX_NAME + 1];
};

// Function prototype(s):
struct Employee* makeEmployee(int birth, int start, const char* name);
struct Employee* generateEmployee();
int generateNumbers(int birth); //helper
char generateChar(); //helper
const char* generateName(size_t n);
void printEmployee(struct Employee *e);
struct Employee** generateWorkforce(size_t count);
void printStructs(struct Employee **ptrArray, size_t count);
/**
 * @param temp is the pointer of employee pointers.
 */
struct Employee** shallowCopyArray(struct Employee **temp, size_t count);
struct Employee** deepCopyArray(struct Employee **temp, size_t count);
/**
 * @param temp is the pointer of employee pointers again
 * @param count the count of workers to free
 */
void freeWorkers(struct Employee **temp, size_t count);
struct Employee* duplicateStructs(struct Employee* temp);
