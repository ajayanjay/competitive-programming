#include <stdio.h>

int main(void) {

	int k;
	scanf("%d", &k);

	char matrix[3][3];

	int count = 0;

	//fill with all different number.
	for (int i = 0; i < 3; ++i) 
		for (int j = 0; j < 3; ++j) 
			matrix[i][j] = (++count) + '0';
	
	if (k != 0) {

		// modify with asterisk, peak brute force..

		if (k == 1) {
			matrix[0][0] = '*';
		} else if (k == 2) {
			matrix[0][0] = '*';
			matrix[1][0] = '*';
			/*
			* 2 3
			* 5 6
			7 8 9
			*/
		} else if (k == 3) {
			matrix[0][0] = '*';
			matrix[1][0] = '*';
			matrix[2][0] = '*';
			/*
			* 2 3
			* 5 6
			* 8 9
			*/
		} else if (k == 4) {
			matrix[0][0] = '*';
			matrix[1][0] = '*';
			matrix[2][0] = '*';
			matrix[1][2] = '*';
			/*
			* 2 3
			* 5 *
			* 8 9
			*/
		} else if (k == 5) {
			matrix[0][1] = '*';
			matrix[1][1] = '*';
			matrix[2][1] = '*';
			matrix[1][0] = '*';
			matrix[1][2] = '*';
			/*
			1 * 3
			* * *
			7 * 9
			*/
		} else if (k == 6) {
			matrix[0][0] = '*';
			matrix[1][0] = '*';
			matrix[2][0] = '*';
			matrix[1][2] = '*';
			matrix[0][1] = '*';
			matrix[2][1] = '*';
			/*
			* * 3
			* 5 *
			* * 9
			*/
		} else if (k == 7) {

			matrix[0][0] = '*';
			matrix[1][0] = '*';
			matrix[2][0] = '*';
			matrix[1][2] = '*';
			matrix[0][1] = '*';
			matrix[2][1] = '*';
			matrix[2][2] = '*';
			/*
			* * 3
			* 5 *
			* * *
			*/

		} else if (k == 8) {
			matrix[0][0] = '*';
			matrix[1][0] = '*';
			matrix[2][0] = '*';
			matrix[1][2] = '*';
			matrix[0][1] = '*';
			matrix[2][1] = '*';
			matrix[2][2] = '*';
			matrix[0][2] = '*';
			/*
			* * *
			* 5 *
			* * *
			*/

		} else if (k == 9) {
			for (int i = 0; i < 3; ++i)
				for (int j = 0; j < 3; ++j)
					matrix[i][j] = '*';
		}

	}
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			printf("%c", matrix[i][j]);

		printf("\n");
	}


}