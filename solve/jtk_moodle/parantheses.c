/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isValid(char* s) {
    char bruh[6] = {'(', ')', '[', ']', '{', '}'};
	
	int len = strlen(s);
	int currentindex;
	bool found;
	
	for(int i = 0; i < len; i++) {
		
		found = false;
		for (int k = 0; k < 6; k += 2) {
			if (s[i] == bruh[k]) {
				currentindex = k;
				found = true;
				break;
			}
		}
		
		if (!found){
			continue;
		}
		
		for (int j = i + 1; j < len; j++) {
			
			if (s[j] == '0') {
				return false;
			}
			
			if (s[j] == bruh[currentindex+1]) {
				found = false;
				s[i] = '0';
				s[j] = '0';
				break;
			}
		}
		
		if (found) {
			return false;
		}
		
	}
	
	for (int i = 0 ;i < len; i++) {
		for (int j = 0 ; j < 6; j++) {
			if (s[i] == bruh[j]) {
				return false;
			}
		}
	}
	
	return true;
	
	
}

int main() {

/* Kamus */

/* Program */
	

    return 0;
}
