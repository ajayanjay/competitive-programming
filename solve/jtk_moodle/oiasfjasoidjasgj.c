/* File			: */
/* Deskripsi	: */
/* Nama / NIM	: */
/* Tanggal		: */

#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <wchar.h>

#include <locale.h>

void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main(int argc, char ** argv) {
	
//	int num;
//	scanf("%d", &num);
//	
//	printf("\n ____ ");
//	printf("\n|    |");
//	
//	//concat
//	//case 
//	
//	printf("\n| ? |", num); // number based spacing LADDER SNAKE
//	printf("\n|____|");

	setlocale(LC_CTYPE, "");

  wchar_t star1 = 0x2606;

  wchar_t star2 = 0x2605;

  wprintf(L"Black Star: %lc\n",star1);

  wprintf(L"White Star: %lc\n",star2);

    return 0;
}
