# include <iostream>
# include<conio.h>
# include<stdlib.h>
# include<math.h>
# define MaxQ 10

using namespace std;

struct Queue{
	string Isi[MaxQ];
	int Depan;
	int Belakang;
	int flag;
}Q;

void init() {
	int Depan = MaxQ;
	int Belakang = MaxQ;
	int flag = 0;
}
void printQueue()
{
    system("cls");
    int i;
    int j = 1;
    for(i = 0 ;i < MaxQ;i++)
    {
        cout<<"["<<j<<"] "<<Q.Isi[i]<<endl;
        j++;
    }
}
void enQueue() {
	if (Q.Belakang==MaxQ){
		Q.Belakang=0;
	}
	if((Q.Belakang==Q.Depan)&&Q.flag==1){	
			cout<<"Queue Penuh !"<<endl;
		}else {
			Q.flag = 1;
			string Data;
			cout<<"Masukan Antrian : "; cin>>Data;
			Q.Isi[Q.Belakang]= Data;
			Q.Belakang++;
			printQueue();
	}
}
void deQueue() {
	string Hsl;
	if((Q.Depan!=Q.Belakang)||Q.flag==1) {
		cout<<"Mengeluarkan Antrian : "<<Q.Isi[Q.Depan];
		Q.Isi[Q.Depan]=Hsl;
		Q.Depan++;
		if(Q.Depan>=MaxQ) {
			Q.Depan=0;
		} if (Q.Depan==Q.Belakang) {
			Q.flag=0;
		}
	} else {
		cout<<"Queue Kosong";
	}
	printQueue();
}

int main() {
	int PIL;
    do {
    system("cls");
    cout<<"|=========================|\n";
    cout<<"|   ANTRIAN MELINGKAR     |\n";
    cout<<"|=========================|\n";
    cout<<"| 1. INSERT               |\n";
    cout<<"| 2. DELETE               |\n";
    cout<<"| 3. EXIT                 |\n";
    cout<<"|=========================|\n";
    cout<<endl;
    cout<<"Masukan Pilihan (1-3) :"; cin>>PIL;
    cout<<endl;
    switch (PIL)
    {
    case 1:
        enQueue();
        break;
    case 2:
        deQueue();
        break;
    case 3:
        cout<<"TERIMA KASIH"<<endl;
        break;
    }
    getch();
    }
    while (PIL<3);
}


