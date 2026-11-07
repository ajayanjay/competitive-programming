#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
	
	int len = strlen(s);
	int index, top = -1;
	
	char stack_arr[len];
	
	//]
	// stackarr = (0)
	// top 1
	// index 2
	
	const char kamus[6] = {'(', ')', '[', ']', '{', '}'};
	
	for (int i = 0; i < len; ++i) {

		for (int j = 0; j < 6; ++j) {
			if (s[i] != kamus[j]) continue;
				
			// found opening bracket
			if (j % 2 == 0) {
				stack_arr[++top] = s[i]; // push opening bracket into stack

			// found closing bracket
			} else if (top == -1 || stack_arr[top] != kamus[j - 1]) { // either stack is empty (no opening bracket) or opening bracket does not match closing bracket
				return false;

			} else { // both opening and closing bracket match
				stack_arr[top--] = '0'; // pop the matching bracket from stack.
			}

			break;
		}
	}
	
	/*
		stack length indicates whether the parantheses are valid or not.
		stack is empty implies that every opening bracket met it's closing bracket. and their position is valid.
		stack is not empty implies that there are bracket that doesn't found it's closing match.

		ex: "(([[[" or "("
	*/
	return (top == -1);
}