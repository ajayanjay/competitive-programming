#include <stdio.h>

void swap_col(char ** bits, int col1, int col2, int n) {
	for (int i = 0; i < n; ++i) {
		char temp = bits[i][col1];
		bits[i][col1] = bits[i][col2];
		bits[i][col2] = temp;
	}
}

void swap_row(char ** bits, int row1, int row2, int n) {
	for (int i = 0; i < n; ++i) {
		char temp = bits[row1][i];
		bits[row1][i] = bits[row2][i];
		bits[row2][i] = temp;
	}
}

int main(void) {
	int n;

	scanf("%d", &n);

	char bits[n][n + 1];

	for (int i = 0; i < n; ++i) {
		fgets(bits[i], n + 1, stdin);
		bits[i][n] = '\0';
	}



}

/*

	01101		
	11001		
	01111 ->		
	11101
	00010
*/