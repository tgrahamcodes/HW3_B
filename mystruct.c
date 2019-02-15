/** mystruct.c
 * This file is main skeleton file to hold the main function.
 * The production and testing suite will be called from here.
 *
 * Date: February 15, 2019
 * Student: Tom Graham
 * Teacher/Previous Author: Mike Ciaraldi
 */

#include <string.h>
#include <stdlib.h>
#include "mystruct.h"

/**
 * Allocates an Employee struct and fills in its fields.
 * @param birth The year the employee was born.
 * @param start The year the employee started with the company.
 * @param name A string containing employee's name
 * @return A Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* makeEmployee(int birth, int start, const char *name) {
	struct Employee *temp = malloc(sizeof(struct Employee));
	strncpy(temp->name, name, sizeof(temp->name));
	temp->birth_year = birth; // Year the employee was born
	temp->start_year = start; // When employee started with the company.
	return temp;
}


/**
 * Generate numbers function. This functions takes a parameter that
 * will effectively act as a boolean, 0 is birth so generates a birth
 * year then if called and not 0 generates start age of work.
 * @param birth The birth parameter. If 1, baby so generate birth year, else generate work age.
 * @return An integer representing the birthYear or startYear depending on the context.
 */
int generateNumbers(int birth){
	int temp;
	if (birth)
		temp = (1950 + (rand() % 50));
	else
		temp = (1950 + (rand() % 50)) + (16 + (rand() % 20));
	return temp;
}

/**
 * Generates an employee by calling three helper functions.
 * This is the compiler of the employee generation.
 * @return A Pointer to Employee struct, newly allocated from the heap.
 */
struct Employee* generateEmployee(){
	return makeEmployee(generateNumbers(1), generateNumbers(0), generateName(4));
}

/**
 * Generates an employees name by using my generateChar function and appending
 * the chars together to a string. This is the compiler of the employee struct pseudo class.
 * @param n The number of letters for a name, as requested from the write-up.
 * @return A Pointer to Employee struct, newly allocated from the heap.
 */
const char* generateName(size_t n){
	char *test = (char*) malloc(n * sizeof(char));
	int i = 0;
	while (i < n && n > 0){
		test[i] += generateChar();
		i++;
	}
	//test[n+i] = '\0';
	return test;
}

/**
 * Generates a character based on the ASCII table. I've set case 91-96 to roll again.
 * These cases were special characters that would not normally be in a name.
 * @return The char that has been generated.
 */
char generateChar() {
	char c = 65 + (rand() % 57);
	switch (c){
		case 91:
		case 92:
		case 93:
		case 94:
		case 95:
		case 96:
			c = 65 + (rand() % 57);
	}
	return c;
}

/**
 * A function used to generate the workforce of employees!
 * @param count A count for the number of employees to generate.
 * @return A pointer to array of pointers for generated Employeee's.
 */
struct Employee** generateWorkforce(size_t count){
	struct Employee **ptrArray = ((struct Employee **)malloc(sizeof(struct Employee*) * count));
	struct Employee** beginningOfArray = ptrArray;
	while (count-- && count >= 0){
		*ptrArray++ = generateEmployee();
	}
	return beginningOfArray;
}

/**
 * A function used to shallow copy,  similar to my previous function but not generating.
 * @param temp A pointer to a struct of Employee pointers.
 * @param count A count for the length of array.
 * @return A pointer to array of pointer for generated Employeees.
 */
struct Employee** shallowCopyArray(struct Employee** temp, size_t count){
	struct Employee **ptrArray = ((struct Employee **)malloc(sizeof(struct Employee*) * count));
	struct Employee** beginningOfArray = ptrArray;
	while (count-- && count >= 0){
		*ptrArray++ = *temp++;
	}
	return beginningOfArray;
}

/**
 *This function is used to make the deep copy easier.
 *@param temp The struct pointer of employee.
 *@return A struct ptr to the newly made employee.
 */
struct Employee* duplicateStructs(struct Employee* temp) {
	return makeEmployee(temp->birth_year, temp->start_year, temp->name);
}

/**
 * A function used to shallow copy,  similar to my previous function but not generating.
 * @param count A count for the length of array.
 * @param temp A pointer to a struct of Employee pointers.
 * @return A pointer to array of pointer for generated Employeee's.
 */
struct Employee** deepCopyArray(struct Employee** temp, size_t count){
	struct Employee **ptrArray = ((struct Employee **)malloc(sizeof(struct Employee*) * count));
	struct Employee** beginningOfArray = ptrArray;
	while (count-- && count >= 0){
		*ptrArray++ = duplicateStructs(*temp++);
	}
	return beginningOfArray;
}

/**
 * A function used to display all the fields of the struct.
 * The will be printed to console.
 * @param count The number of structs to print.
 * @param ptrArray The pointer to employee struct for the to be printed.
 */
void printStructs(struct Employee **ptrArray, size_t count) {
	for(int i = 0; i < count; i++){
		printEmployee(ptrArray[i]);
		printf("\n");
	}
}

/**
 * A function used to print out a single employee.
 * The will be printed to console.
 * @param e The pointer to employee struct for the to be printed.
 */
void printEmployee(struct Employee *e) {
	printf("Employee name: %s. \n", &e->name);
	printf("Employee birth: %d. \n", e->birth_year);
	printf("Employee start: %d. \n", e->start_year);
}

/**
 * A function used to free the employees!
 * @param temp The pointer to employee struct for the to be printed.
 * @param count The count of employees to free.
 */
void freeWorkers(struct Employee **temp, size_t count) {
	int i = 0;
	while(i < count){
		//free the workers
		free(temp[i]);
		i++;
	}

	//free array holding the workers
	free(temp);
}
