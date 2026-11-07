#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAP_SIZE 100
#define COORD_X 1
#define COORD_Y 1
#define ROWS 10
#define COLUMNS 10
#define MIN_POSITION 2  // Petak minimal (tidak boleh 1)
#define MAX_POSITION 99 // Petak maksimal (tidak boleh 100)
#define HUMAN 1
#define COM 0

typedef struct 
{
    int id;
    char namaPemain[20];
    char inisial[3];
    int posisi;
    int jumlahLemparan;
    int giliran;
    int dadu;
    int status;
}Pemain;

typedef struct
{
    int id;
    int mulut;
    int ekor;
}Ular;

typedef struct
{
    int id;
    int bawah;
    int atas;
}Tangga;

void tampilMainMenu();
void inputMainMenu();
void tampilGameplay();
void inputGameplay();
void inputPemain();
void inputKom();
void tampilHighscore();
void backToMainMenu();
void tampilContinue();

void petak(int x, int y);
void board(int x, int y, int jmlhPemain, Pemain pemain[4]);
int generateRandom(int min, int max);
void generateUlar(int *snakeHead, int *snakeTail);
void tampilUlar(int arrNum[10][10], Ular ular[4]);
void generateTangga(int *ladderTop, int *ladderBottom);
void tampilTangga(int arrNum[10][10], Tangga tangga[4]);
void numPetak(int size, int jmlhPemain, Pemain pemain[4]);
void tampilNumPetak(int x, int y, int arrNum [10][10]);
void tampilPemain(int jmlhPemain, Pemain pemain[4], int arrNum[10][10]);
void infoPemain(int x, int y, Pemain pemain);

void tampilHasilDadu();
int lemparDadu();
int cekMenang(Pemain pemain);
void getSix(Pemain *pemain);
void setPemain(int jmlhPemain, int status);
void inputNamaPemain(Pemain *pemain, int id, int status);
void gameStart(int jmlhPemain ,Pemain pemain[4]);
void giliran(Pemain *pemain);
void game(int jmlhPemain, Pemain pemain[4]);
void movePemain(Pemain *pemain);

void fileWriteBoard(Tangga tangga[4], Ular ular[4]);
void fileReadBoard(Tangga tangga[4], Ular ular[4]);
void fileClearBoard();
int cekFileBoard();

void gotoxy(int x, int y);
void clearLayar();

int main(){
    system("mode 192,48");
    srand(time(NULL));
    //board(COORD_X, COORD_Y);
    tampilMainMenu();
    return 0;
}

void tampilMainMenu(){
  printf("\033[0;32m+----------------------------------------+\n");
  printf("|             Selamat Datang             |\n");
  printf("|          Permainan Ular Tangga         |\n");
  printf("+----------------------------------------+\033[0m\n");
  printf("MAIN MENU\n1. Mulai\n2. Highscore\n3. How To Play\n4. Exit\n");
  inputMainMenu();
}

void inputMainMenu(){
  int numMenu;
  printf("Masukkan Menu Yang Ingin Anda Pilih : ");
  scanf("%d", &numMenu);
  
  int a = cekFileBoard();

  if(numMenu > 0 && numMenu <=4){
    switch (numMenu)
    {
    case 1:
      clearLayar();
      
      if (a == 1) {
      	tampilContinue();
	  } else {
	  	tampilGameplay();
	  }
      
      break;
    
    case 2:
      printf("2");
      break;

    case 3:
      printf("3");
      break;
    
    case 4:
      exit(-1);
      break;
    }
  }else {
    printf("\nPilihan anda tidak ada dalam menu\nMohon memasukkan angka yang sesuai\n\n");
    tampilMainMenu();
  }
}

void tampilContinue(){
	printf("1. Continue\n2. New Game\n");
	int i;
	
	printf("Masukan input menu: ");
	scanf("%d", &i);
	while(i > 2 || i < 0){	
		printf("Masukan input menu: ");
		scanf("%d", &i);
	}
	
	switch (i){
		case 1:
			clearLayar();
			printf("Belum Tersedia");
			break;
			
		case 2:
			clearLayar();
			tampilGameplay();
			break;
	}
}

void tampilGameplay(){
  printf("1. Multiplayer\n2. Singleplayer\n");
  inputGameplay();
}

void inputGameplay(){
  int numGameplay;

  printf("Masukkan Gameplay Yang Anda Inginkan : ");

  scanf("%d", &numGameplay);

  if(numGameplay > 0 && numGameplay <=2){
    switch (numGameplay)
    {
    case 1:
      clearLayar();
      inputPemain();
      break;
    
    case 2:
      clearLayar();
      inputKom();
      break;
    }
  }else{
    printf("Pilihan anda tidak ada dalam menu\nMohon memasukkan angka yang sesuai\n");
    tampilGameplay();
  }
}

void inputPemain(){
  int jmlhPemain;
  printf("Masukkan Jumlah Pemain (2-4) : ");
  scanf("%d", &jmlhPemain);

  while(jmlhPemain < 2 || jmlhPemain > 4){
    printf("Mohon Memasukkan Jumlah Pemain. Minimum 2 dan Maksimal 4 Pemain.\n");
    printf("Masukkan Jumlah Pemain (2-4) : ");
    scanf("%d", &jmlhPemain);
  }
  setPemain (jmlhPemain, HUMAN);
}

void inputKom(){
  int jmlhKom;
  printf("Masukkan Jumlah Bot Komputer (1-3) : ");
  scanf("%d", &jmlhKom);

  while (jmlhKom < 1 || jmlhKom > 3)
  {
    printf("Mohon Memasukkan Jumlah Pemain. Minimum 1 dan Maksimal 3 Pemain.\n");
    printf("Masukkan Jumlah Bot Komputer (1-3) : ");
    scanf("%d", &jmlhKom);
  }

  setPemain(jmlhKom+1, COM);
}

void petak(int x, int y){
    gotoxy(x,y);printf("\033[0;33m+---------+");
    gotoxy(x,y+1);printf("|");gotoxy(x+10,y+1);printf("|");
    gotoxy(x,y+2);printf("|");gotoxy(x+10,y+2);printf("|");
    gotoxy(x,y+3);printf("|");gotoxy(x+10,y+3);printf("|");
    gotoxy(x,y+4);printf("+---------+\033[0m");
}

void board(int x, int y, int jmlhPemain, Pemain pemain[4]){
    //Ular ular[4];
    //Tangga tangga[4];

    clearLayar();

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            petak(x + (j*10), y + (i*4));
        }
    }
    for (int i = 0; i < jmlhPemain; i++){
        infoPemain(x + 104, y + 8 + (i*1), pemain[i]);
    }
    numPetak(MAP_SIZE, jmlhPemain, pemain);
    tampilHasilDadu();
    gotoxy(COORD_X, 42);printf("             ");
}

void numPetak(int size, int jmlhPemain, Pemain pemain[4]){
    int papan[COLUMNS][ROWS];
    Tangga tangga[4];
    Ular ular[4];

    for (int i = 0; i < 10; i++){
        if(i % 2 == 0){
            for (int j = 0; j < 10; j++){
                papan[i][j] = size--;
            }
        }else{
            for (int j = 9; j >= 0; j--){
                papan[i][j] = size--;
            }
        }
    }
    
    fileReadBoard(tangga, ular);
    
    tampilNumPetak(COORD_X, COORD_Y, papan);
    tampilUlar(papan, ular);
    tampilTangga(papan, tangga);
    tampilPemain(jmlhPemain, pemain, papan);
}

void tampilNumPetak(int x, int y, int arrNum[10][10]){
    x = x + 1;
    y = y + 3;

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            gotoxy(x + (j*10), y + (i*4));printf("%d",arrNum[i][j]);
        }
    }
}

void tampilPemain(int jmlhPemain, Pemain pemain[4], int arrNum[10][10]){
	for (int i = 0; i < 10; i++){
		for(int j = 0; j < 10; j++){
			int count = 0;
			int a[4];
			for (int n = 0; n < jmlhPemain; n++){	
				if(pemain[n].posisi == arrNum[i][j]){
						a[count] = n;
						count++;
					}
				
			}
			if(count == 1){
				gotoxy(COORD_X + 4 + (j*10), COORD_Y + 2 +(i*4));printf("\033[0;36m%c%c\033[0m", pemain[a[0]].inisial[0], pemain[a[0]].inisial[1]);
			}else if (count == 2){
				gotoxy(COORD_X + 4 + (j*10), COORD_Y + 2 +(i*4));printf("\033[0;36m%c%c%c%c\033[0m", pemain[a[0]].inisial[0], pemain[a[0]].inisial[1], pemain[a[1]].inisial[0], pemain[a[1]].inisial[1]);
			}else if (count > 2){
				gotoxy(COORD_X + 4 + (j*10), COORD_Y + 2 +(i*4));printf("\033[0;36m%dplyrs\033[0m", count);
			}
		}
	}
}

int generateRandom(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Fungsi untuk menghasilkan posisi ular
void generateUlar(int *snakeHead, int *snakeTail) {
    do {
        *snakeHead = generateRandom(MIN_POSITION + 10, MAX_POSITION); // Kepala ular (di atas)
        *snakeTail = generateRandom(MIN_POSITION, *snakeHead - 1);   // Ekor ular (di bawah)
    } while ((*snakeHead - 1) / 10 == (*snakeTail - 1) / 10);         // Pastikan kepala dan ekor tidak dalam baris yang sama
}

// Fungsi untuk menghasilkan posisi tangga
void generateTangga(int *ladderTop, int *ladderBottom) {
    do {
        *ladderBottom = generateRandom(MIN_POSITION, MAX_POSITION - 10); // Dasar tangga (di bawah)
        *ladderTop = generateRandom(*ladderBottom + 1, MAX_POSITION);    // Ujung tangga (di atas)
    } while ((*ladderTop - 1) / 10 == (*ladderBottom - 1) / 10);         // Pastikan ujung atas dan dasar tidak dalam baris yang sama
}

void tampilUlar(int arrNum[10][10], Ular ular[4]){
    for(int n = 0; n < 4; n++){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (ular[n].mulut == arrNum[i][j] || ular[n].ekor == arrNum[i][j]){
                    gotoxy(COORD_X + 1 + (j * 10), COORD_Y + 1 + (i * 4));printf("\033[0;31mU%d\033[0m", ular[n].id);
                }
            }
        }
    }
}

void tampilTangga(int arrNum[10][10], Tangga tangga[4]){
    for(int n = 0; n < 4; n++){
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                if (tangga[n].atas == arrNum[i][j] || tangga[n].bawah == arrNum[i][j]){
                    gotoxy(COORD_X + 1 + (j * 10), COORD_Y + 1 + (i * 4));printf("\033[0;32mT%d\033[0m", tangga[n].id);
                }
            }
        }
    }
}

void infoPemain(int x, int y, Pemain pemain){
    gotoxy(x,y);printf("%s (%c%c) : %d", pemain.namaPemain, pemain.inisial[0], pemain.inisial[1], pemain.posisi);
}

void setPemain(int jmlhPemain, int status){
  Pemain pemain[4];
  if(status == 1){
    for (int i = 0; i < jmlhPemain; i++){
      pemain[i].id = i+1;
      inputNamaPemain(&pemain[i], i+1, HUMAN);
      pemain[i].inisial[0] = pemain[i].namaPemain[0];
      pemain[i].inisial[1] = pemain[i].namaPemain[1];
      pemain[i].posisi = 0;
      pemain[i].giliran = i;
      pemain[i].dadu = 0;
      pemain[i].jumlahLemparan = 0;
      pemain[i].status = 1;
    }
  }else{
    pemain[0].id = 1;
    inputNamaPemain(&pemain[0], 1, HUMAN);
    pemain[0].inisial[0] = pemain[0].namaPemain[0];
    pemain[0].inisial[1] = pemain[0].namaPemain[1];
    pemain[0].posisi = 0;
    pemain[0].giliran = 0;
    pemain[0].dadu = 0;
    pemain[0].jumlahLemparan = 0;
    pemain[0].status = 1;

    for (int i = 1; i < jmlhPemain; i++){
      pemain[i].id = i+1;
      inputNamaPemain(&pemain[i], i+1, COM);
      pemain[i].inisial[0] = pemain[i].namaPemain[0];
      pemain[i].inisial[1] = pemain[i].namaPemain[3];
      pemain[i].posisi = 0;
      pemain[i].giliran = i;
      pemain[i].dadu = 0;
      pemain[i].jumlahLemparan = 0;
      pemain[i].status = 1;
    }
  }
  clearLayar();
  gameStart(jmlhPemain, pemain);
}

void inputNamaPemain(Pemain *pemain, int id, int status){
  if (status == 1)
  {
    printf("Masukkan nama Pemain %d: ", id);
    scanf("%s", pemain->namaPemain);
  }
  else{
    sprintf(pemain->namaPemain, "COM%d", pemain->id);
  }
}

void gameStart(int jmlhPemain ,Pemain pemain[4]){
  Ular ular[4];
  Tangga tangga[4];
  for(int i = 0; i < 4; i++){
    ular[i].id = i+1;
    tangga[i].id = i+1;
    generateUlar(&ular[i].mulut, &ular[i].ekor);
    generateTangga(&tangga[i].atas, &tangga[i].bawah);
  }
  fileWriteBoard(tangga, ular);
  board(COORD_X, COORD_Y, jmlhPemain, pemain);
  game(jmlhPemain, pemain);
}

void tampilHasilDadu(){
  gotoxy(105,2);printf("\033[0;36mTampilan Hasil Dadu");
  gotoxy(105,3);printf("+-----------------+");
  gotoxy(105,4);printf("|");gotoxy(123,4);printf("|");
  gotoxy(105,5);printf("|");gotoxy(123,5);printf("|");
  gotoxy(105,6);printf("|");gotoxy(123,6);printf("|");
  gotoxy(105,7);printf("+-----------------+\033[0m");
}

int lemparDadu(){
  int dadu;
  dadu = (rand() % 6) + 1;

  gotoxy(114,5);printf("%d", dadu);

  return dadu;
}

void movePemain(Pemain *pemain){
	Tangga tangga[4];
	Ular ular[4];
	
	pemain->dadu = lemparDadu();
  if(pemain->dadu > 0){
  	if(pemain->dadu == 6){
  		if(pemain->posisi + pemain->dadu > 100){
  			pemain->posisi = 100 - (pemain->posisi + pemain->dadu - 100);
		  }else{
		  pemain->posisi = pemain->posisi + pemain->dadu;	
		  }
  		getSix(&*pemain);
	  }
    if(pemain->posisi + pemain->dadu > 100){
  			pemain->posisi = 100 - (pemain->posisi + pemain->dadu - 100);
		  }else{
		  pemain->posisi = pemain->posisi + pemain->dadu;	
		  }
    pemain->dadu = 0;
  }
  
  fileReadBoard(tangga,ular);
  
  for (int i = 0; i < 4; i++){
  	if(pemain->posisi == ular[i].mulut){
  		pemain->posisi = ular[i].ekor;
	  }
	  if(pemain->posisi == tangga[i].bawah){
	  	pemain->posisi = tangga[i].atas;
	  }
  }
}

void getSix(Pemain *pemain){
	gotoxy(126,4);printf("ANDA MENDAPATKAN ANGKA 6!!!");
	gotoxy(126,5);printf("SILAHKAN MENGOCOK DADU LAGI");
	int n = getch();
	if(n == ' '){
    movePemain(&*pemain);
    }
}

void game(int jmlhPemain, Pemain pemain[4]){
	
	int pemenang;
	int menang = 0;
	while (menang != 1){
	  for (int i = 0; i < jmlhPemain; i++){
	    if(pemain[i].giliran == 0){
	      giliran(&pemain[i]);
	      menang = cekMenang(pemain[i]);
	      if(menang == 1){
	      	pemenang = i;
		  }
	      for (int j = 0; j < jmlhPemain; j++){
	      	if(pemain[j].giliran == 0){
	      		pemain[j].giliran = jmlhPemain-1;
			  }else{
			  	pemain[j].giliran =  pemain[j].giliran - 1;
			  }
		  }
	      board(COORD_X, COORD_Y, jmlhPemain, pemain);
	    }
	    if (menang == 1) break;
	 }
	}
	printf("Game Berakhir");
	fileClearBoard();
}

int cekMenang(Pemain pemain){
	int menang = 0;
	if(pemain.posisi == 100){
 		menang = 1;
	}
	return menang;
}

void champhion(int jmlhPemain, Pemain pemain){
	clearLayar();
	printf("\033[0;32m===============================\n");
	printf("\033[0;32mSELAMAT KEPADA SANG JUARA!!!!!!\n");
	printf("\033[0;32m===============================\n");
	
}

void giliran(Pemain *pemain){
  int n;
  gotoxy(125,2);printf("Kepada %s", pemain->namaPemain);
  gotoxy(125,3);printf("Tekan space...");
  n = getch();
  if(n == ' '){
    movePemain(&*pemain);
  }
  pemain->jumlahLemparan++;
}

void fileWriteBoard(Tangga tangga[4], Ular ular[4]){
    FILE* fptr = fopen("board.bin", "wb");

    for(int i = 0; i < 4; i++){
    	fwrite(&ular[i], sizeof(Ular), 1, fptr);
	}
	for(int i = 0; i < 4; i++){
    	fwrite(&tangga[i], sizeof(Tangga), 1, fptr);
	}
    fclose(fptr);
}

void fileReadBoard(Tangga tangga[4], Ular ular[4]){
    FILE* fptr = fopen("board.bin", "rb");
    for (int i = 0; i < 4; i++){
    	fread(&ular[i], sizeof(Ular), 1, fptr);
	}
	for (int i = 0; i < 4; i++){
    	fread(&tangga[i], sizeof(Tangga), 1, fptr);
	}
    fclose(fptr);
}

int cekFileBoard(){
	int a;
	FILE* fptr = fopen("board.bin", "rb");
	
	fread(&a, sizeof(int), 1, fptr);
	
	fclose(fptr);
	
	if(a != 0){
		return 1;
	}else{
		return 0;
	}
}

void fileClearBoard(){
	FILE* fptr = fopen("board.bin", "wb");
	fclose(fptr);
}

void gotoxy(int x, int y){
    COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void clearLayar(){
    system("cls");
}
