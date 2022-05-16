/**
 * file: lab2-answersToQuestions.h
 * author: Xavier Lopez
 * course: CSI 1440 02
 * assignment: Lab 2 - Pointers 2
 * Due Date: 1/28/2022
 *
 * Date Modified: 1/24/2022
 *     - Answered Questions 1-6
 * Date Modified: 1/26/2022
 *     - Answered Question 7
 *
 * Answers to the Lab 2 questions
 *
 *
 *
 * 1. What would be printed if we incremented the pointer (myPtr++)?
 *
 * If we incremented the pointer (myPtr++), then the screen would print:
 * "ello World!" (without the quotation marks)
 *
 *
 * 2. How does "myArray += 6" differ from what we talked about in class -
 * "*(myArray + 6)" - which we said was OK?
 *
 * "myArray += 6" differs from "*(myArray + 6)" because the first refers to the
 * actual character array, which cannot occur because you cannot add to a
 * character array. The second references a pointer to myArray that reference
 * the 7th element ('W') in the array.
 *
 *
 * 3. Replace the array notation statements with pointer notation statements
 * for the assignment of 'o', 'w', 'd', and 'y'.
 *
 *  *(myArray + 1) = 'o';
 *  *(myArray + 2) = 'w';
 *  *(myArray + 3) = 'd';
 *  *(myArray + 4) = 'y';
 *
 *
 * 4. Could this code be fixed by using pointer notation instead of array
 * notation? Why/Why not?
 *
 * No because the pointer is holding the address of a string literal "Hello
 * World!" and not of an array of characters. Also, the character pointer is
 * constant and cannot be manipulated.
 *
 *
 * 5. Why did we not give the memory back to the computer, using the delete
 * operator, within the function?
 *
 * We didn't give the memory back to the computer within the function because
 * we were not finished with using the memory until after we changed "Hello
 * World!" to "Howdy World!"
 *
 *
 * 6. Why do we not need to use the indirection operator when printing the
 * contents of myArray and myPtr? Could we print the contents of a differently
 * typed (int, double, etc..) array?
 *
 * The new operator allocates memory for the pointer to point what is assigned
 * to. This then causes no problems for changing the pointer because what is
 * assigned to the pointer can be accessed. We could print the contents of a
 * differently typed array using this idea.
 *
 *
 * 7. Write two additional lines of code to print out the contents of str as a
 * c-string representation using c_str() with both the indirection operator and
 * the structure pointer operator
 *
 * cout << (*str).c_str() << endl;
 * cout << str->c_str() << endl;
 *
 *
 */