/*
 * stack.c
 */
 
#include "stack.h"

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Create a stack from scratch which initially contains no elements
void init_stack (stack *st) {

	// The top and bottom pointers should initially be NULL
	st->top = NULL;
	st->bottom = NULL;
}

// Adds a new element (integer) to the top of the stack
void add_int_to_top (stack *st, int numer) {

	stack_elt *elt;
	
	// Allocate the memory for a new stack element
	elt = malloc (sizeof(*elt));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (elt == NULL) {
		
		printf ("Couldn't allocate memory for a new stack element\n");
		delete_all_entries (st);
		exit (1);
	}
	
	ratNum *number;
	
	// Allocate the memory for a new rational number
	number = malloc (sizeof(*number));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (elt == NULL) {
	
		printf ("Couldn't allocate memory for a new rational number\n");
		delete_all_entries (st);
		exit (1);
	}
	
	// Allocate the memory for the numerator
	number->numerator = malloc (sizeof(int));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (number->numerator == NULL) {
	
		printf ("Couldn't allocate memory for a new rational number\n");
		delete_all_entries (st);
		exit (1);
	}
	
	// Allocate the memory for the denominator
	number->denominator = malloc (sizeof(int));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (number->denominator == NULL) {
	
		printf ("Couldn't allocate memory for a new rational number\n");
		delete_all_entries (st);
		exit (1);
	}
	
	// Set the rational number's numerator/denominator fields
	*number->numerator = numer;
	*number->denominator = 1;
	
	// Fill in the rational number field of the new stack element
	elt->number = number;
	
	// Check if the stack is empty
	if (st->top) {
		
		// If not, make the new element's next pointer go to the old top
		elt->next = (st->top);
		
	} else {
		
		// If it is, make the new element the new bottom
		st->bottom = elt;
	}
	
	// Make the new element the new top
	st->top = elt;
	
	// We succeeded, so print the top element
	print_top (st);
}

// Adds a new element (rational number) to the top of the stack
void add_num_to_top (stack *st, int numer, int denom) {

	stack_elt *elt;
	
	// Allocate the memory for a new stack element
	elt = malloc (sizeof(*elt));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (elt == NULL) {
		
		printf ("Couldn't allocate memory for a new stack element\n");
		delete_all_entries (st);
		exit (1);
	}
	
	ratNum *number;
	
	// Allocate the memory for a new rational number
	number = malloc (sizeof(*number));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (elt == NULL) {
	
		printf ("Couldn't allocate memory for a new rational number\n");
		delete_all_entries (st);
		exit (1);
	}
	
	// Allocate the memory for the numerator
	number->numerator = malloc (sizeof(int));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (number->numerator == NULL) {
	
		printf ("Couldn't allocate memory for a new rational number\n");
		delete_all_entries (st);
		exit (1);
	}
	
	// Allocate the memory for the denominator
	number->denominator = malloc (sizeof(int));
	
	// If malloc fails (not enough memory left), terminate the program (free all memory first)
	if (number->denominator == NULL) {
	
		printf ("Couldn't allocate memory for a new rational number\n");
		delete_all_entries (st);
		exit (1);
	}
	
	// Set the rational number's numerator/denominator fields
	*number->numerator = numer;
	*number->denominator = denom;
	
	// Fill in the rational number field of the new stack element
	elt->number = number;
	
	// Check if the stack is empty
	if (st->top) {
		
		// If not, make the new element's next pointer go to the old top
		elt->next = (st->top);
		
	} else {
		
		// If it is, make the new element the new bottom
		st->bottom = elt;
	}
	
	// Make the new element the new top
	st->top = elt;
}

// Deletes the element (rational number) on the top of the stack
void remove_num_from_top (stack *st) {

	stack_elt *elt;
	
	// If the stack is not empty...
	if (st->top) {
		
		// Grab the top element
		elt = st->top;
		
		// If the stack has only one element...
		if (st->top == st->bottom) {
			
			// Make both top and bottom values NULL (empty stack)
			st->top = NULL;
			st->bottom = NULL;
			
		} else {
		
			// If it has more elements, make the new top the element after the old top
			st->top = elt->next;
		}
		
		//ratNum *number;
		
		//number = *elt->number;
		
		// Free the now-deleted element
		free((elt->number)->numerator);
		free((elt->number)->denominator);
		free(elt->number);
		free(elt);
	}
}

// Deletes everything in the stack
void delete_all_entries (stack *st) {

	// So long as there's a top element, keep deleting
	while (st-> top) {
	
		remove_num_from_top (st);
	}
}

// Prints (from top to bottom) the elements (rational numbers) of the stack
void print_stack (stack *st) {

	// First grab the top element
	stack_elt *elt = st->top;
	
	printf("\nSTACK CONTENTS\n");
	
	// While there are more non-NULL elements...
	while (elt) {
	
		// Get the element's rational number, print it, then move to the next element
		ratNum number = *elt->number;
		printf("%d/%d\n", *number.numerator, *number.denominator);
		elt = elt->next;
	}
}

// Prints the top element of the stack (if one exists)
void print_top (stack *st) {

	// Grab the top element
	stack_elt *elt = st->top;
	
	// If it exists (not NULL)...
	if (elt) {
	
		// Grab its rational number
		ratNum number = *elt->number;
		
		// Print it out
		printf("%d/%d\n", *number.numerator, *number.denominator);
	}
}

// Finds the greatest common divisor of two integerrs
int gcd(int a, int b) {

	// So long as we haven't modded to 0 yet...
	while (b != 0) {

		// Save the old b
		int old_b = b;
	
		// Update new b to be a mod old b
		b = a % b;
	
		// Replace a with old b
		a = old_b;
	
	}
	
	// After we hit an a mod b = 0 instance, we found the gcd
	return a;
}

// Simplifies a given rational number
void simplify(ratNum *number) {

	// Get the numerator and denominator of the rational number
	int numer = *number->numerator;
	int denom = *number->denominator;
	
	// Find the gcd of the numerator and denominator
	int gcdenom = gcd(numer, denom);
	
	// Set the simplified numerator and denominator to their old versions divided by the found gcd
	*number->numerator = (*number->numerator) / gcdenom;
	*number->denominator = (*number->denominator) / gcdenom;
}

// Makes sure that any negative sign only goes with the numerator
void handle_signs(ratNum *number) {

	// Get the numerator and denominator of the rational number
	int numer = *number->numerator;
	int denom = *number->denominator;
	
	// If the denominator is negative, redirect the neg sign to the numerator
	if (denom < 0) {
	
		*number->numerator = (*number->numerator) * -1;
		*number->denominator = (*number->denominator) * -1;
	}
}

// Duplicates the top element on the stack and puts it on the top
void duplicate_top (stack *st) {

	// If there is a top to duplicate...
	if (st->top) {
	
		// Grab the top...
		stack_elt *elt = st->top;
		
		// Grab the top's rational number
		ratNum number = *elt->number;
		
		// Grab the numerator and denominator
		int numer = *number.numerator;
		int denom = *number.denominator;
		
		// Add a new element to the top with the same rational number
		add_num_to_top(st, numer, denom);
		
		// We succeeded, so print the new top
		print_top (st);
		
	} else {
	
		// If there was no top to duplicate (empty stack), send an error message
		printf("STACK ERROR\n");
	}
}

// Removes the top two elements, multiplies them, and puts their product on top of the stack
void multiply_and_replace (stack *st) {

	// If there is a top element...
	if (st->top) {
	
		// Grab the top element
		stack_elt *elt1 = st->top;
		
		// Grab the top element's rational number
		ratNum number1 = *elt1->number;
		
		// Grab the top element's numerator and denominator
		int numer1 = *number1.numerator;
		int denom1 = *number1.denominator;
		
		// If there is a second element...
		if (elt1->next) {
		
			// Grab the second element
			stack_elt *elt2 = elt1->next;
			
			// Grab the second element's rational number
			ratNum number2 = *elt2->number;
			
			// Grab the second element's numerator and denominator
			int numer2 = *number2.numerator;
			int denom2 = *number2.denominator;
			
			// Update the second element's rational number to the product of top and second
			*number2.numerator = numer1 * numer2;
			*number2.denominator = denom1 * denom2;
			
			// Simplify the product
			simplify(&number2);
			
			// Handle any potential neg sign
			handle_signs(&number2);
			
			// Remove the old top (so that new top is the updated product 2nd element)
			remove_num_from_top(st);
			
			// We succeeded, so print the new top
			print_top (st);
			
		} else {
		
			// If there wasn't a 2nd element, send an error message
			printf("STACK ERROR\n");
		}
	
	} else {
	
		// If there wasn't a top element, send an error message
		printf("STACK ERROR\n");
		
	}
}

// Removes the top two elements, adds them, and puts their sum back on top of the stack
void add_and_replace (stack *st) {

	// If there is a top element...
	if (st->top) {
	
		// Grab the top element
		stack_elt *elt1 = st->top;
		
		// Grab the top element's rational number
		ratNum number1 = *elt1->number;
		
		// Grab the top element's numerator and denominator
		int numer1 = *number1.numerator;
		int denom1 = *number1.denominator;
		
		// If there is a 2nd element...
		if (elt1->next) {
		
			// Grab the 2nd element
			stack_elt *elt2 = elt1->next;
			
			// Grab the 2nd element's rational number
			ratNum number2 = *elt2->number;
			
			// Grab the 2nd element's numerator and denominator
			int numer2 = *number2.numerator;
			int denom2 = *number2.denominator;
			
			// Update the 2nd element's rational number to the sum of the 1st and 2nd
			*number2.numerator = (numer1 * denom2) + (numer2 * denom1);
			*number2.denominator = denom1 * denom2;
			
			// Simplify the sum
			simplify(&number2);
			
			// Handle any potential neg sign
			handle_signs(&number2);
			
			// Remove the old top (so the new top is the updated sum 2nd element)
			remove_num_from_top(st);
			
			// We succeeded, so print the new top
			print_top (st);
		
		} else {
			
			// If there wasn't a 2nd element, send an error message
			printf("STACK ERROR\n");
		}
	
	} else {
	
		// If there wasn't a top element, send an error message
		printf("STACK ERROR\n");
	}
}

// Removes the top two elements, subtracts 1st from 2nd, and puts the result back on top of the stack
void subtract_and_replace (stack *st) {

	// If there is a top element...
	if (st->top) {
	
		// Grab the top element
		stack_elt *elt1 = st->top;
		
		// Grab the top element's rational number
		ratNum number1 = *elt1->number;
		
		// Grab the top element's numerator and denominator
		int numer1 = *number1.numerator;
		int denom1 = *number1.denominator;
		
		// If there is a 2nd element...
		if (elt1->next) {
		
			// Grab the 2nd element
			stack_elt *elt2 = elt1->next;
			
			// Grab the 2nd element's rational number
			ratNum number2 = *elt2->number;
			
			// Grab the 2nd element's numerator and denominator
			int numer2 = *number2.numerator;
			int denom2 = *number2.denominator;
			
			// Update the 2nd element's rational number to the 2nd - 1st
			*number2.numerator = (numer2 * denom1) - (numer1 * denom2);
			*number2.denominator = denom1 * denom2;
			
			// Simplify the result
			simplify(&number2);
			
			// Handle any potential neg sign
			handle_signs(&number2);
			
			// Remove the old top (so the new top is the updated result 2nd element)
			remove_num_from_top(st);
			
			// We succeeded, so print the new top
			print_top (st);
		
		} else {
			
			// If there wasn't a 2nd element, send an error message
			printf("STACK ERROR\n");
		}
	
	} else {
	
		// If there wasn't a top element, send an error message
		printf("STACK ERROR\n");
	}
}

// Removes the top two elements, divides the 2nd by the 1st, and puts their quotient on top of the stack
void divide_and_replace (stack *st) {

	// If there is a top element...
	if (st->top) {
	
		// Grab the top element
		stack_elt *elt1 = st->top;
		
		// Grab the top element's rational number
		ratNum number1 = *elt1->number;
		
		// Grab the top element's numerator and denominator
		int numer1 = *number1.numerator;
		int denom1 = *number1.denominator;
		
		// If we're about to divide by zero, send an error message, free memory, and exit out of the function
		if (numer1 == 0) {
			
			printf("DIVIDE BY ZERO\n");
			delete_all_entries (st);
			exit (1);
		}
		
		// If there is a second element...
		if (elt1->next) {
		
			// Grab the second element
			stack_elt *elt2 = elt1->next;
			
			// Grab the second element's rational number
			ratNum number2 = *elt2->number;
			
			// Grab the second element's numerator and denominator
			int numer2 = *number2.numerator;
			int denom2 = *number2.denominator;
			
			// Update the second element's rational number to the quotient of 2nd / 1st (flip 1st then multiply)
			*number2.numerator = numer2 * denom1;
			*number2.denominator = numer1 * denom2;
			
			// Simplify the quotient
			simplify(&number2);
			
			// Handle any potential neg sign
			handle_signs(&number2);
			
			// Remove the old top (so that new top is the updated quotient 2nd element)
			remove_num_from_top(st);
			
			// We succeeded, so print the new top
			print_top (st);
			
		} else {
		
			// If there wasn't a 2nd element, send an error message
			printf("STACK ERROR\n");
		}
	
	} else {
	
		// If there wasn't a top element, send an error message
		printf("STACK ERROR\n");
		
	}
}

// Swaps the positions of the top two elements on the stack
void swap_top_two (stack *st) {

	// If there is a 1st element...
	if (st->top) {
	
		// Grab the 1st element
		stack_elt *elt1 = st->top;
	
		// Grab the 1st element's rational number
		ratNum number1 = *elt1->number;
			
		// Grab the 1st element's numerator and denominator	
		int numer1 = *number1.numerator;
		int denom1 = *number1.denominator;
		
		// If there is a 2nd element...
		if (elt1->next) {
		
			// Grab the 2nd element
			stack_elt *elt2 = elt1->next;
			
			// Grab the 2nd element's rational number
			ratNum number2 = *elt2->number;
			
			// Grab the 2nd element's numerator and denominator
			int numer2 = *number2.numerator;
			int denom2 = *number2.denominator;
			
			// Remove the top two from the stack
			remove_num_from_top(st);
			remove_num_from_top(st);
			
			// Add back the orig 1st element
			add_num_to_top(st, numer1, denom1);
			
			// Add back the orig 2nd element (now on top)
			add_num_to_top(st, numer2, denom2);
			
			// We succeeded, so print the new top
			print_top (st);
			
		} else {
		
			// If there isn't a 2nd element, send an error message
			printf("STACK ERROR\n");
		}
	
	} else {
	
		// If there isn't a 1st element, send an error message
		printf("STACK ERROR\n");
	}
}
