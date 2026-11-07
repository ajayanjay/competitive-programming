#include <stdio.h>
#include <string.h>


#define MAX_LENGTH 21

void int_to_8bitc(char * buff, int dig, int start_pos) {
    int cnt = 7;
    while (cnt >= 0) {
        buff[start_pos++] = ((dig & (1 << cnt)) ? '1' : '0');
        cnt--;
    }
}


void dig_to_hexc(char * hex, int dig, int start_pos) {
	const char *hex_chars = "0123456789ABCDEF";
    hex[start_pos] = hex_chars[(dig >> 4) & 0xF];
    hex[start_pos + 1] = hex_chars[dig & 0xF];
}

int main(void) {

	char buff[MAX_LENGTH];

	fgets(buff, MAX_LENGTH, stdin);

	int size = strlen(buff);
	buff[--size] = 0;

	int digits[4] = {0};
	int ptr = 0;

	for (int i = 0; i < 4; ++i) {

		int dig[3] = {0};

		int j = 0;
		while (buff[ptr] != '\0' && buff[ptr] != '.') {
			int temp = buff[ptr] - '0';

			dig[j++] = temp;
			ptr++;
		}

		int dig_cnt = 3 - j;

		if (dig_cnt == 1) {
			dig[2] = dig[1];
			dig[1] = dig[0];
			dig[0] = 0;
		} else if (dig_cnt == 2) {
			dig[2] = dig[0];
			dig[0] = 0;
		} 


		digits[i] = dig[0] * 100 + dig[1] * 10 + dig[2];
		ptr++;

		printf("%d : ", digits[i]);
	}

	printf("\n");


	char biner[64] = {0};
	for (int i = 0; i < 4; ++i) {
		int_to_8bitc(biner, digits[i], i * 8);
	}

	int biner_size = strlen(biner);

	printf("Binary: [");
	for (int i = 0; i < biner_size; ++i) {
		printf("%c", biner[i]);
		if ((i + 1) % 4 == 0 && i != biner_size - 1)
        	printf(" ");
    
	}
	printf("]\n");

	char hex[16] = {0};

	for (int i = 0; i < 8; i +=2 ) {
		dig_to_hexc(hex, digits[i / 2], i);
	}

	printf("Hexadecimal: [%s]\n", hex);
	printf("CAT 2002::/16: [2002%s::1/64]\n", hex);





	return 0;
}	