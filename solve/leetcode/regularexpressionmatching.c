#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(const char* restrict s, char* p) {
    
	int i = 0;

	int lenS = strlen(s);
	int lenP = strlen(p);

	int j = i;

	while (i < lenS && j < lenP) {


		while (s[i] == p[j] && i < lenS && j < lenP) {
			j++; i++;
		}
		// F.S p[j] != s[i]

		if (j >= lenP) break;

		if (p[j] == '.' && p[j + 1] == '*') {

			j += 2;
			if (p[j] == 0) return true;

			while (p[j] != s[i] && i++ < lenS);
			if (i++ >= lenS) return false;
			++j;
			// F.S: i is now at a different character 
			continue;
		}
		if (p[j + 1] == '*') {
			j += 2;
			continue;
		}

		switch (p[j]) {

		case '*':
			while (s[i] == p[j - 1] && i < lenS) {
				i++;
			}
			if (s[i-1] == p[j-1] && i == lenS) return true;
			j++;
			break;

		case '.':
			p[j] = s[i];
			break;

		default :
			return false;

		}
	}

	return i >= lenS && j >= lenP;

}

int main() {

	char s[20], p[20];

	scanf("%s %s", s, p);

	if (isMatch(s, p))
		printf("matches");
	else
		printf("nah");

	system("pause");

}