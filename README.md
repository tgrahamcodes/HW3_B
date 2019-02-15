
**Section B**
**Part 1**
Download the file **HW3Bstarter.zip** , import it into Eclipse, and rename the project **HW3B\_**** yourusername**. Compile and run it.
## **Part 2**
The skeleton and prototype for a function which prints a struct of type Employee. Fill in the code and header comment. It should output something like this:
**Birth year = 1952**
**Starting year = 1999**
**Name = Testing This**
**Part 3**

The skeleton, header comment, and prototype already exist for a function that allocates a struct of type Employee and fills its fields with data passed in as parameters. Its prototype looks like this:

 struct Employee\* makeEmployee(char\* name, int birth\_year, int start\_year);

Fill in the body of the function. Be sure that this function copies (the contents of) the parameter string into the array in the struct. Do not try copying the pointer to the string, since that string might go away. Be sure you do not go off the end of the string, and be sure the string is properly terminated.

## **Part 4**

Write a function which creates a struct of that type and fills it with random data. That is, it will generate a random string (filled with printable characters) and two random integers, and then call the makeEmployee() function from Part 2. Then it will return the newly-created struct.

You will have to create several &quot;helper&quot; functions, such as one which returns a random integer from 0 to some specified maximum, inclusive. How can you do that? Well, there is a function call rand() in the standard C library. You can find out about it using this command:

**man –s3 rand**

This will tell you how to use this function, including which header file or files you need to #include. Why do you need the &quot;-s3&quot;? It turns out that there is also a command with that name, and if you just ask the man program for rand, it will give you the man page for the command instead of the function. For more about this, look at the man page for the man program itself!

When you call rand(), it returns a pseudo-random number from 0 to RAND\_MAX, which is one of the standard symbolic constants. RAND\_MAX is a very large number, so you can use the modulo operator to generate a smaller number. For example, if you have a random integer r, and you calculate **r%n** , that will give you a random integer from 0 to n-1.

You will also need a helper function which generates a random string (of specified length) of printable characters (in other words, not including ones like Tab or Newline). If you want to restrict the set of printable characters (e.g., only capital letters, letters and numbers, etc.) feel free. Remember, any time you have to do the same thing in more than one place, that is a candidate for a function.

Tip: Consider first creating a function which generates a single random character. Then you can call it from inside the function which creates the random string.

Another tip: In your code, avoid using the literal numeric codes for the characters. For example, use &#39;A&#39; instead of 65. The compiler does not care, but your code will be much more readable.

Yet another tip:  Use the &quot;man ascii&quot; command to see the numeric codes for the various characters. Observe the patterns. Note that, for example, the code for &#39;B&#39; is the same as the code for &#39;A&#39;, plus one. The code for &#39;C&#39; is the code for &#39;A&#39;, plus two. And so on.

Once you have this working, if you run your program several times you will notice that you always get the same sequence of random characters. This is a deliberate choice in the design of the C library. It is intended to make testing easier by always generating the same sequence, so the program always run the same. Once you have your program totally working, if you want, at the beginning of the program add a call to the function srand(), like this:

 **srand(time(0));**

That changes what is called the _seed_ of the pseudo-random sequence. In this case the seed is based on the time, so every time you run the program you will get a different seed. Warning: Whenever you use this technique, remember to call srand() only once, probably at the beginning of the program. Do not call it repeatedly, such as inside a loop, because that will keep resetting the seed, which you do not want to do.

Note: For each of your functions, write an appropriate test function. Of course, in the case where you are using random data, there is no way to prove it is random. But try creating some structs and printing them to show that this seems to work.

**Part 5**

Then write a function which takes one parameter, a count. It should allocate an array which can hold that many pointers to the Employee struct, then fill each element of the array with a pointer to a newly-created struct filled with random data.

Finally, write a function that takes an array of pointers and a count, and prints out all the structs. Modify your main program so it demonstrates all these functions.

Remember: Nothing in C works by magic. If you need an array to hold a character string or an array, you need to allocate it before you can put data into it. If you allocate it with malloc() or calloc(), be sure to free() it when you no longer need it. And if you are allocating space for a character string, be sure to include space for the null terminator at the end.

## **Part 6**

Write a function that duplicates an array of pointers to structsof this type. Be sure you have a way to tell the function the number of elements in the array. This is known as a &quot;shallow copy&quot;; it duplicates the pointers but not the things pointed to.

Write a test function to demonstrate how it works.

## **Part 7**

Create a function which takes an array of pointers to the struct, and frees (de-allocates) all the structs pointed to. Do you have to make any assumptions about the pointers? Add code to demonstrate it. Note: Once you have freed a block of memory, there is no way to prove that it has actually been freed. So, for this step, being able to run this function without error is a sufficient demonstration.

## **Part 8 (Extra Credit)**

Create another version of the function which duplicates an array of pointers to the structs (i.e. the function from Part 5). In this one, duplicate the structs, then fill the array with pointers to these new structs. This is called a &quot;deep copy.&quot; Demonstrate.

**Part 9**

As in Section A, use Doxygen to generate the documentation Web pages. Then look at them.

**Part 10**

As you did for Section A, export and submit the project to Canvas.
