/* Hasbi Ardianto Pratama */
/* NIM : C2C021020 */

# include <iostream>
# include <conio.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <windows.h>

using namespace std;

int maks, top, pil, karakter, i;
int top2;
char elemen, aa, bb;
char stack[20], infiks[20], postfiks[20], stack2[20], hasil[20];
void delay();

/* Buat prosedur untuk fungsi mengubah warna */

void setcolor(unsigned short color) {
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon,color);
}

/* Buat prosedur untuk fungsi yang memggerakkan kursor */

void gotoxy(int x, int y) {
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
/* Membuat stack */

int create(int x) {
	top = 0;
	setcolor(13);
	gotoxy(50,3);
	printf("  							");
	for (i=0;i<100;i++) {
		gotoxy(59,4+i);
		printf("		");
	}
	if(x<=20) {
		for(i=0;i<=x;i++) {
			if(i==x) {
				gotoxy(60,4+i);
				printf("====");
			} else {
				gotoxy(59,4+i);
				printf("|	|");
			}
		}
	}
}
/* Menambah elemen */
int push(char aa) 
	{
	gotoxy(50,2);
	printf("					");
	if(top == maks) 
	{
		gotoxy(53,2);
		printf("    -OVERFLOW-");
	}
	else {
		stack[top]=aa;
		for(i=0;i<11;i++) {
			gotoxy(50+i,3);
			cout<<" ";
			gotoxy(51+i,3);
			cout<<aa;
			delay();
		}
		for(i=0;i<(maks-top);i++) {
			gotoxy(61,3+i);
			cout<<" ";
			gotoxy(61,4+i);
			cout<<aa;
			delay();
		}
		top = top + 1;
	}
}
/* Menghapus elemen */
int pop(){
	gotoxy(50,2);
	printf("					");
	if(top == 0) {
		gotoxy(53,2);
		printf("    -UNDERFLOW-");
	} else {
		bb = stack[top-1];
		for (i=(maks-(top-1));i>0;i--) {
			gotoxy(61,3+i);
			cout<<" ";
			gotoxy(61,2+i);
			cout<<bb;
			delay();
		}
		for (i=10;i<21;i++) {
			gotoxy(50+i,3);
			cout<<" ";
			gotoxy(51+i, 3);
			cout<<bb;
			delay();
		}
		gotoxy(71,3);
		printf(" ");
		top = top -1;

	}
}
/* Pilihan Menu */
int main() {
	maks = 0;
	top = 0;
	do {
		gotoxy(3,1);
		setcolor(2);
		printf("=====================================");
		gotoxy(3, 2);
		setcolor(6);
		printf("		 PROGRAM STACK 21A20			");
		gotoxy(3, 3);
		setcolor(2);
		printf("=====================================");
		gotoxy(4, 4);
		setcolor(6);
		printf("1 : BUAT STACK BARU ");
		gotoxy(4, 5);
		printf("2 : TAMBAH ELEMEN");
		gotoxy(4, 6);
		printf("3 : HAPUS ELEMEN");
		gotoxy(4, 7);
		printf("4 : KELUAR");
		gotoxy(3, 9);
		setcolor(2);
		printf("======================================");
		for(i=10;i<20;i++) {
			gotoxy(3, i);
			printf("						");
		}
		gotoxy(3, 10);
		setcolor(6);
		printf("Masukkan Pilihan : "); cin>>pil;
		switch(pil){
			case 1 :{
				gotoxy(3,12);
				printf("Masukkan Kapasitas stack (Maksimal 20) : ");cin>>maks;
				create(maks);
				break;
			}
			case 2 :{
				if(maks==0) {
					gotoxy(3,12);
					printf("Stack Belum Dibuat. Create stack terlebih dahulu");
					getch();
				} else {
					gotoxy(3,12);
					printf("Masukkan satu karakter : "); cin>>elemen;
					push(elemen);
				}
				break;
			}
			case 3 : {
				if(maks==0) {
					gotoxy(3,12);
					printf("Stack Belum Dibuat. Create stack terlebih dahulu");
					getch();
				} else {
					pop();
				} 
				break;
			}
		}
	}
	while(pil!=4);
}
void delay() {
	for(int y = 1; y < 100; y++)
	for(int x = 1; x < 100; x++) 
	for(int p = 1; p < 30 ; p++)
	cout<<"";	
}
