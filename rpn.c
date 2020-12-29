/*
 * rpn.c
 */

#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 100

int main () {

	// Make a charracter array for where the input strings will reside
	char input[MAX_LINE_LENGTH];
	
	// Make a character array for where the input command will reside
	char command[MAX_LINE_LENGTH];
	
	// Set aside a spot for the number to be added to the stack
	int *num;
	
	// Create a stack instance
	stack theStack;

	// Initialize the stack
	init_stack (&theStack);

	// While the program is running...
	while (1) {
		
		int valid_command = 0;
		
		int preemptive_free = 0;
		
		// Allocate some of that sweet sweet memory for the command string
		char* strcommand = (char*) malloc (sizeof(char) * (MAX_LINE_LENGTH + 1));
		
		// Allocate some of that sweet sweet memory for the command number
		num = malloc(sizeof(num));
		
		// Get the user's command
		fgets (input, MAX_LINE_LENGTH, stdin);
		
		// Check for decimal int command (1 meaning the decimal was found but not the string)
		if (sscanf(input, "%d%s", num, command) == 1) {
		
			// Add the decimal int to the stack (prints out new top if was successful)
			add_int_to_top (&theStack, *num);
			
			valid_command = 1;
		}
		
		// If we have a string command (not a decimal int to input)...
		if (sscanf(input, "%s%d", command, num) == 1) {
	
			int i;
		
			// Make the command all lower case
			for (i = 0; i <= strlen(command); i++) {

				command[i] = tolower(command[i]);
			}
			
			// Fill in the string command as the now lowercase command
			strcpy(strcommand, command);
			
			// Check for + command (0 meaning the string command was exactly "+")
			if (strcmp(strcommand, "+") == 0) {
			
				// Add top two, remove them, place sum on top (prints new top if successful)
				add_and_replace(&theStack);
					
				valid_command = 1;
			}
			
			// Check for - command (0 meaning the string command was exactly "-")
			if (strcmp(strcommand, "-") == 0) {
			
				// Subtract top from 2nd, removes them, places result on top (prints new top if successful)
				subtract_and_replace(&theStack);
					
				valid_command = 1;
			}
			
			// Check for * command (0 meaning the string command was exactly "*")
			if (strcmp(strcommand, "*") == 0) {
			
				// Multiply the top two, remove them, and place product on top (prints new top if successful)
				multiply_and_replace(&theStack);
					
				valid_command = 1;
			}
			
			// Check for dup command (0 meaning the string command was exactly "dup")
			if (strcmp(strcommand, "dup") == 0) {
			
				// Duplicate the top and put it on top (prints new top if successful)
				duplicate_top(&theStack);
					
				valid_command = 1;
			}
			
			// Check for swap command (0 meaning the string command was exactly "swap")
			if (strcmp(strcommand, "swap") == 0) {
			
				// Swaps top two elements (prints new top if successful)
				swap_top_two(&theStack);
					
				valid_command = 1;
			}
	
			// Check for quit command (0 meaning the string command was exactly "quit")
			if (strcmp(strcommand, "quit") == 0) {
						
				valid_command = 1;	
						
				// Delete all the entries (freeing them from memory)
				delete_all_entries(&theStack);
				
				// Free the command string's memory
				free(strcommand);
				
				// Free that command number's memory
				free(num);
				
				// Exit the program (0 bc it's a successful termination)
				exit (0);
			}
			
			// Check for drop command (0 meaning the string command was exactly "drop")
			if (strcmp(strcommand, "drop") == 0) {
			
				// If there is a top to remove...
				if (theStack.top) {
				
					// Remove it
					remove_num_from_top(&theStack);
				
					// If there's still a top afterwards...
					if (theStack.top) {
						
						// Print it
						print_top(&theStack);
					}
				}
					
				valid_command = 1;	
			}
			
			// Check for clear command (0 meaning the clear command was exactly "clear")
			if (strcmp(strcommand, "clear") == 0) {
			
				// Delete all the entries (freeing them from memory)
				delete_all_entries(&theStack);
					
				valid_command = 1;
			}
			
			// Check for / command (0 meaning the string command was exactly "/")
			if (strcmp(strcommand, "/") == 0) {
				
				// Preemptively free string/number commands in case of 0 division exit
				/* EXTRA NOTE: division has to go last since it preemptively frees the commands. 
				 * I originally had it before others and it made it impossible to do the later checks 
				 * since the commands had been freed (this is some gross code but it fixed the problem 
				 * of "still reachable" commands in memory after 0 division 
				 */
				free(strcommand);
				free(num);
				
				// Make it known that we've already freed strcommand and name
				preemptive_free = 1;
				
				// Divide the 2nd by the top, removes them, places quotient on top (prints new top if successful)
				divide_and_replace(&theStack);
					
				valid_command = 1;
			}
		}
		
		// If the entered command didn't match any of the valid options...
		if (valid_command == 0) {
		
			// Print out that it was an invalid command
			printf("INVALID COMMAND\n");
		}
		 
		// If we haven't already freed during division (preemptive in case of / by 0)...
		if (preemptive_free == 0) { 
		 
			// Free the string command (we're done with it)
			free(strcommand);
		
			// Free the command number (we're done with it)
			free(num);
		}
	}
	
	return 0;
}
