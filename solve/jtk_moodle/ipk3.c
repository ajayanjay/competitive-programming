#include <stdio.h>
#include <conio.h>

void inputkan(); 
int chartonilai(char a);
void printkan(char nama[], float nilai);

int main() {
    for (int j = 0; j < 3; j++) {
    	inputkan();
	}
}

void inputkan(){
	char nama[25];
	int nilai = 0;
	const int lib[4] = {4, 3, 3, 2};
	
	scanf("%[^\n]%*c", nama);
	for (int i = 0; i < 4; ++i) {
		nilai += chartonilai(getchar()) * lib[i];
		if (getchar() == '\n') break;
	}
	
	float ipk = (float) nilai / 12;
	printkan(nama, ipk);
}

int chartonilai (char a) {
    switch (a) {
        case 'A': return 4;
        case 'B': return 3;
        case 'C': return 2;
        case 'D': return 1;
        case 'E': return 0;
        default : return -1;
    }
}

void printkan(char nama[], float nilai) {
    printf("%s %.2f\n", nama, nilai);
}