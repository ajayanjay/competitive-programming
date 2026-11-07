#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50002
#define ll long long

const char* key = "tamocompetindo";
int key_len = 14;

int my_strcmp(const char* a, int fixes) {

	int mismatch = 0;

	for (int i = 0; i < key_len; ++i) {
		if (a[i] == key[i]) continue;

		mismatch++;
		if (mismatch > fixes) return mismatch;
	}

	return mismatch;
}

int main(void) {

	int k;
	char s[MAX_LENGTH];

	scanf("%d", &k);
	getchar();
	fgets(s, MAX_LENGTH, stdin);

	ll slen = strlen(s);
	s[--slen] = '\0';

	if (slen < 14) {
		printf("NAO");
		return 0;
	}

	if (k == 14) {
		printf("SIM");
		return 0;
	}

	for (ll i = 0; i < slen; ++i) {
		if (slen - i < 14) {
			printf("NAO");
			return 0;
		}

		int missmatch = my_strcmp(s + i, k);

		if (missmatch <= k) {
			printf("SIM");
			return 0;
		}
	}

	printf("NAO");
	return 0;
}

// tenosseussonho
// tamocompetindo