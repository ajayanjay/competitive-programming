#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int strStr(const char* restrict haystack, const char* restrict needle) {

	int i = 0;

	int lenHaystack = strlen(haystack);
	int lenNeedle = strlen(needle);

	int maxLen = lenHaystack - lenNeedle;

	int indexFound;

	while (i <= maxLen) {

		while (needle[0] != haystack[i++])
			if (i > maxLen) return -1;
		
		//F.S: needle found the first occuring or not

		indexFound = --i;

		int j = 0;
		while (needle[j] == haystack[i]) {
			if (++j == lenNeedle) return indexFound;
			if (++i == lenHaystack) return -1;
		}
		//F.S: either j equal to lenNeedle (needle found) or not

		i = indexFound + 1;

	}

	return -1;

}

int main() {

	char haystack[64], needle[32];

	scanf("%s %s", haystack, needle);

	printf("%d", strStr(haystack, needle));

	system("pause");

}