# include <iostream>
# include<conio.h>
# include<stdlib.h>
# define MaxQ 10

using namespace std;

struct Queue{
	string Isi [MaxQ];
	int Right, Left;
}Q;

void init () {
	int Right = -1;
	int Left = -1;
}
void display() {
	if (Q.Left == -1){
		cout<<"Queue Kosong !"<<endl;
	} else {
		for(int i = Q.Left;i <= Q.Right; i++) {
			cout<<Q.Isi[i]<< " | ";
		}
	}
}

void insertRight (string Data) {
	if (Q.Right>=MaxQ-1) {
		cout<<"Data tidak bisa masuk"<<endl;
	} else {
		if (Q.Left==-1) {
			Q.Left++;
			Q.Right++;
		} else {
			Q.Right = Q.Right+1;
		}
		Q.Isi[Q.Right] = Data;
		cout<<"Data yang masuk : "<<Q.Isi[Q.Right]<<endl;
	}
	display();
}

void insertLeft (string Data) {
	if (Q.Left == -1) {
		Q.Left = 0;
		Q.Isi[++Q.Right] = Data;
		cout<<"Data yang masuk : "<<Data<<endl;
	} else if (Q.Left!=0) {
		Q.Isi[--Q.Left]=Data;
		cout<<"Data yang masuk : "<<Data<<endl;
	} else {
		cout<<"Data tidak bisa masuk !"<<endl;	
	}
	display();
}

void deleteLeft() {
	if (Q.Left==-1) {
		cout<<"Tidak bisa menghapus :: Data kosong !"<<endl;
		return;
	} else {
		cout<<"Data yang dihapus : "<<Q.Isi[Q.Left]<<endl;
		if (Q.Left==Q.Right) {
			Q.Left = Q.Right = -1;
			return;
		} else 
			Q.Left = Q.Left +1;
	}
	display();
}
void deleteRight(){
	if(Q.Left == -1){
		cout<<"Tidak bisa menghapus :: Queue Kosong !"<<endl;
		return;
	} else {
		cout<<"Data yang dihapus : "<<Q.Isi[Q.Right]<<endl;
		if (Q.Left == Q.Right){
			Q.Left = Q.Right = -1;
		} else 
			Q.Right = Q.Right-1;
	}
	display();
}
int main() {
	int PIL;
	string Data;
    do {
    system("cls");
    cout<<"|=========================|\n";
    cout<<"|    ANTRIAN  D.E.QUEUE   |\n";
    cout<<"|=========================|\n";
    cout<<"| 1. INSERT KANAN         |\n";
    cout<<"| 2. INSERT KIRI          |\n";
    cout<<"| 3. DELETE KANAN         |\n";
    cout<<"| 4. DELETE KIRI          |\n";
    cout<<"| 5. DISPLAY              |\n";
    cout<<"| 6. EXIT                 |\n";
    cout<<"|=========================|\n";
    cout<<endl;
    cout<<"Masukan Pilihan (1-5) :"; cin>>PIL;
    cout<<endl;
    switch (PIL)
    {
    case 1:
    	cout<<"Masukkan Data : ";cin>>Data;
        insertRight(Data);
        break;
    case 2:
    	cout<<"Masukkan Data : ";cin>>Data;
        insertLeft(Data);
        break;
    case 3:
    	deleteRight();
    	break;
    case 4:
    	deleteLeft();
    	break;
    case 5:
    	display();
    	break;
    case 6:
        cout<<"TERIMA KASIH"<<endl;
        break;
    default:
		cout << " PILIHAN SALAH ! ";
		break;
    }
    getch();
    }
    while (PIL!=7);
}
