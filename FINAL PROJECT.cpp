#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include "fstream"
#include "malloc.h"

using namespace std;
typedef struct {
	string judul;
	int b1;
}info2;
typedef struct {
	string jurusan,nama;
	int b;
	info2 buku[100];
}info;
info peminjam[100];
info2 temp;

int pilih,option,plh,milih;
int tgl_p,bln_p;
char opt,judul_buku[30],nama_peminjam[30];
FILE *data,*data1;
void peminjaman();
void loading();
void login();
void Admin();
void Peminjam();
void Berhasil_Admin();
void daftar_buku();
void cari_buku();
void result();
void input_buku();
void rekap_harian();
int jum_pengunjung=0;

void peminjaman(){
        cin.ignore();
        cout<<"\tNama Peminjam\t= "; cin.getline(nama_peminjam,sizeof(nama_peminjam));
        cout<<"\tJudul Buku\t= "; cin.getline(judul_buku,sizeof(judul_buku));
        cout<<"\tTanggal Pinjam (ddmmyyyy)\n";
        cout << "\t\tTanggal\t= "; cin >> tgl_p;
        cout << "\t\tBulan\t= "; cin >> bln_p;
}
void input_buku(){
	data = fopen("Daftar Buku.txt", "w");
for (int i=0; i<3; i++) {
	cout << "Jurusan\t: ";
	cin.ignore();
	getline(cin,peminjam[i].jurusan);
	cout << "Jumlah koleksi buku\t: "; cin >> peminjam[i].b;
	for (int j=0; j<peminjam[i].b; j++) {
		cin.ignore();
		cout << "\tJudul\t\t: "; getline(cin,peminjam[i].buku[j].judul);
		cout << "\tKuantitas\t: "; cin >> peminjam[i].buku[j].b1;
	}
	fwrite(&peminjam[i],sizeof(peminjam[i]),1,data);
}
	fclose(data);
	Berhasil_Admin();
}
/*void update () {
	
}*/
void rekap_harian(){
    int *jum_pengunjung1;
    jum_pengunjung1=&jum_pengunjung;
    cout << "Jumlah pengjung dalam hari ini ";
    cout << *jum_pengunjung1 << " orang." << endl;
    system("pause");
    Berhasil_Admin();
	}
void daftar_buku(){
	data = fopen("Daftar Buku Perpus.txt","r");
	for (int i=0; i<3; i++) {
		fread(&peminjam[i],sizeof(peminjam[i]),1,data);
	}
	for (int i=0; i<3; i++) {
	for (int j=0; j<peminjam[i].b; j++) {
		for (int k=j+1; k<peminjam[i].b; k++)
            if (peminjam[i].buku[j].judul>peminjam[i].buku[k].judul) {
                temp=peminjam[i].buku[j];
                peminjam[i].buku[j]=peminjam[i].buku[k];
                peminjam[i].buku[k]=temp;
            }
	}
}
for (int i=0; i<3; i++) {
    cout << "Jurusan\t: " << peminjam[i].jurusan << endl;
	cout << "Jumlah koleksi buku\t: " << peminjam[i].b << endl;
        for (int j=0; j<peminjam[i].b; j++) {
            cout << "\tJudul\t\t: " << peminjam[i].buku[j].judul << endl;
            cout << "\tKuantitas\t: " << peminjam[i].buku[j].b1 << endl;
        }
}


fclose(data);
system("PAUSE");
Peminjam();
}

void cari_buku(){
	bool found;
	char judul[100];

	cout << "Pencarian Buku\n";
	cin.ignore();
	cout << "\tMasukkan judul buku yang akan dicari\t= "; cin.getline(judul,sizeof(judul));
	found=false;
	data = fopen("Daftar Buku Perpus.txt","r");
	for (int i=0; i<3; i++) {
		fread(&peminjam[i],sizeof(peminjam[i]),1,data);
	}
	for (int i=0; i<3; i++) {
        for (int j=0; j<peminjam[i].b; j++) {
            if (peminjam[i].buku[j].judul==judul)
            {
            		cout << "Jurusan\t: " << peminjam[i].jurusan << endl;
                    cout << "\tJudul\t\t: " << peminjam[i].buku[j].judul << endl;
                    cout << "\tKuantitas\t: " << peminjam[i].buku[j].b1 << endl;
                    found=true;

            }
        }
	}
    if (found=false){
    cout << "\nBuku " << judul << " tidak ditemukan.";}
fclose(data);
system("PAUSE");
Peminjam();
}
int tgl_k(int *t) {
	for(int i=0; i<4; i++) {
        *t++;
    }
}
void result(){
	cout<< "=========================================";
	cout << "\n+Berikut adalah data peminjaman Anda+\n";
	cout<< "=========================================\n";
	cout<<"\tNama Peminjam\t= " << nama_peminjam << endl;
    cout<<"\tJudul Buku\t= " << judul_buku << endl;
    if (tgl_p>=1 && tgl_p<=25 && bln_p>=1 &&  bln_p<=12) {
     cout << "\tTanggal Pinjam\t= " << tgl_p << "-" << bln_p << "-2018\n";
     cout << "\tTanggal Kembali\t= " << tgl_k(&tgl_p) << "-" << bln_p << "-2018\n"; //"tgl_p+3 << "-" << bln_p << "-2018\n"";
     system("pause");
     login();
    }
    else
        Peminjam();
}
void Berhasil_Admin(){
	system("cls");
	cout<<"MENU\n1. Input Daftar Buku\n2. Rekap Harian\n3. Kembali ke Menu awal\n";
	cout<<"Pilih Menu (masukkan angka) : ";cin>>plh;
	switch(plh){
		case 1 : system("cls"); input_buku(); break;
		case 2 : rekap_harian();break;
		case 3 : login();break;
		default: Berhasil_Admin();
	}

}

void Admin(){
	system("cls");
	string pass ="";
	char ch;
	cout<<"Password : ";
	ch = _getch();
	while(ch !=13){
		pass.push_back(ch);
		cout<< '*';
		ch = _getch();
	}
	if (pass == "hilihkinthil"){

		loading();

	}
	else {
  do{
		system("cls");
		cout<<"Pasword Salah!"<<endl;
		cout<<"1.Coba Lagi?\n2.Kembali?\n";
		cout<<"Pilih Angka"<<endl;cin>>option;
		if(option==1) {
			Admin();
		}
		if(option==2) {
			system("cls");
			login();
		}

		}while(option>2);
	}
}

void Peminjam(){
	system("cls");

		cout<<"MENU : \n1. Daftar Buku\n2. Cari Buku\n3. Peminjaman\n";
	cout<<"Pilih Menu (masukkan angka)= ";cin>>milih;
	switch(milih){
		case 1 : daftar_buku() ;break;
		case 2 : cari_buku() ;break;
		case 3 : peminjaman(); result(); break;
		case 69: Admin(); break;
		default: Peminjam();
	}
}

void login(){
    system("cls");
    cout<<"+===========================================================+\n";
    cout<<"+Selamat Datang Di E-Library Fakultas Teknik Industri UPNVYK+\n";
	cout<<"+===========================================================+\n";
	cout<<"Login Sebagai : \n1. Admin\n2. Peminjam\n";
	cout<<"Silahkan pilih menu (masukkan angka)= ";cin>>pilih;
	if (pilih==1){
			Admin();
			cout<<endl;
	}
	if (pilih==2) {
            jum_pengunjung=jum_pengunjung+1;
			Peminjam();
			cout<<endl;
	}
	if (pilih>2){
			system("cls");
			login();
	}

}
void loading(){

	cout<<endl;
	cout<<"\n\n\t\t\t Please wait"<<endl;
	cout<<"\n\n\n";
	cout<<"\t\t\tLoading";
	for(int i=0;i<20;i++){
		cout<<".";
		Sleep(500);
	}
	cout<<endl;
	cout<<"\t\t\t Succesfully";
	Sleep(1000);
	system("cls");

	Berhasil_Admin();
}
int main(){
	login();

}
