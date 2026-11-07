#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define STR_LEN 5000

#define ll long long

bool isBearStr(char * str) {
	return strncmp(str, "bear", 4) == 0;
}

ll func(int last_bear_index, int b_index, int r_index, int strlen) {
	return (b_index - last_bear_index + 1) * ((strlen - 1) - r_index + 1);
}

int main(void) {

	char str[STR_LEN + 1];
	fgets(str, STR_LEN + 1, stdin);

	int len = strlen(str);
	if (str[len - 1] == '\n') str[--len] = '\0';

	if (len < 4) {
		printf("0");
		return 0;
	}

	ll sum = 0;
	int last_bear_index = 0;
	for (int i = 0; i < len - 3; ++i) {
		if (str[i] != 'b') continue;
		if (!isBearStr(str + i)) continue;

		int b_index = i;
		int r_index = i + 3;
		sum += func(last_bear_index, b_index, r_index, len);
		last_bear_index = b_index + 1;
	}

	printf("%lld", sum);

	return 0;
}