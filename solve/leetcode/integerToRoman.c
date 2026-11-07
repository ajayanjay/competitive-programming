#include <stdlib.h>
#include <string.h>
char* intToRomans(int num) {

	const char* roman[13] = 
	{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

	const int romanNum[13] =  
	{1,4,5,9,10,40,50,90,100,400,500,900,1000};

	char* output = (char*)malloc(16 * sizeof(char));
    output[0] = 0;

	while (num > 0) {

		for (int i = 12; i >= 0; --i) {
			if (num >= romanNum[i]) {
				strcat(output, roman[i]);
				num -= romanNum[i];
				break;
			}
		}

	}

	return output;

}

char* intToRoman(int num) {

	const char* roman[13] = 
	{"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

	const int romanNum[13] =  
	{1,4,5,9,10,40,50,90,100,400,500,900,1000};

	char* output = (char*)malloc(16 * sizeof(char));
    output[0] = 0;

	for (int i = 12; i >= 0; --i) {

		while (num >= romanNum[i]) {
			strcat(output, roman[i]);
			num -= romanNum[i];
		}

	}

	return output;

}