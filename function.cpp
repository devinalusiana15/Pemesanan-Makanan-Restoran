#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <cstdlib>
#include "function.h"
using namespace std;

char nama [50], jawab, back, kembali;
int jumlah, pesanan, i,j, seadanya, kurang_stok, pilih, awal;
struct korea{
	char menu[30];
	int harga;
	int stok;
	};
korea data_korea[8]={{"Korean Bulgogi",30000,5},{"Korean Jjangmyeon",45000,8},{"Korean Cheese Ramyeon",55000,3},{"Tteokbokki",20000,2},
					    {"Bibimbap",24500,4},{"Classic Bingsoo",25000,7},{"Korean Lemonade",15000,4},{"Korean Tea",12000,6}};
struct cina{
	char menu[30];
	int harga;
	int stok;
	};
cina data_cina[8]={{"Fuyunghai",23000,7},{"Gou Lao Rou",27000,3},{"Sapo Tahu",29000,4},{"Hakau",20000,9},{"Bakpao",21000,0},{"Teh Krisan",13000,8},{"Kopi Yunnan",25000,5},{"Jus Buah Plum",17000,6}};
	
	
	
void Nama(){
	cout<<"Masukkan Nama Anda : " ; cin>>nama; 	
	member();
}

void member(){
    cout << "==================== SELAMAT DATANG DI CKFOOD ====================" << endl;
    cout << "1. Member" << endl;
    cout << "2. Non Member" << endl;
    cout << "3. Keluar" << endl;
    cout << endl;
    cout << "Silahkan memilih berdasarkan nomor : "; cin >> awal;
    system("cls");
    switch(awal){
        case 1:
            login();
            break;
        case 2:
            Selamat_datang();
            break;
        case 3:
            Keluar();
            break;
        default:
            cout << "Maaf nomor yang anda masukkan salah" << endl;
    }
}

// MEMBER
void login(){
    login:
    string user = "";
    string pass = "";
    cout << "==================== SELAMAT DATANG DI CKFOOD ====================" << endl;
    cout << "Silahkan login" << endl;
    cout << "Username: "; cin >> user;
    cout << "Password: "; cin >> pass;
    cout << endl;
    if (user == nama && pass == "member"){
        cout << "Login berhasil" << endl;
        Selamat_datang_mem();
    }else{
        cout << "Login gagal" << endl;
        goto login;
    }
}

void Selamat_datang_mem(){
    cout << "==================== SELAMAT DATANG DI CKFOOD ====================" << endl;
    cout << "1. Chinese Food" << endl;
    cout << "2. Korean Food" << endl;
    cout << "3. Tentang" << endl;
    cout << "4. Keluar" << endl;
    cout << endl;
    cout << "Silahkan memilih berdasarkan nomor : "; cin >> pilih;
    system("cls");
    
	switch (pilih){
		case 1:do{
			    MenuCina_mem();
			    cekstok_cina();
			    total_cina_mem;
			    struk_cina_mem();
                laporan_cina();
                cout << "[Y = ya / T = tidak]"<<endl;
            	cout << "Apakah anda ingin memesan lagi ? [Y/T]  =  ";
	            cin>>back;}
	            while(back=='y'||back=='Y');
	            Keluar();
			break;
		case 2: do{
			    MenuKorea_mem();
			    cekstok_korea();
			    total_korea_mem();
			    struk_korea_mem();
                laporan_korea();
                cout << "[Y = ya / T = tidak]"<<endl;
            	cout << "Apakah anda ingin memesan lagi ? [Y/T]  =  ";
	            cin>>back;}
	            while(back=='y'||back=='Y');
	            Keluar();
			break;
		case 3:
		    baca_tentang();
		    cout <<endl<< "Ketikkan satu karakter untuk ke menu utama : "<<endl;
	        cin>>back;
	       Selamat_datang();
		case 4:
			Keluar();
			break; 
	 	default:
		cout << "Maaf nomor yang anda masukkan salah" << endl;
	}
}

void MenuCina_mem(){
		cout<<"============================== CK Food =============================="<<endl;
		cout<<"=========================== Chinese Food ============================"<<endl;
		cout<<endl;
		cout<<"Pilihan menu yang tersedia---"<<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		cout<<"|	[1] Fuyunghai        = Rp 23.000                            |"   <<endl;
		cout<<"|	[2] Ayam Koloke      = RP 27.000                            |"   <<endl;
		cout<<"|	[3] Sapo Tahu        = RP 29.000                            |"   <<endl;
		cout<<"|	[4] Hakau            = Rp 20.000                            |"   <<endl;
		cout<<"|	[5] Bakpao           = Rp 21.000                            |"   <<endl;
		cout<<"|	[6] Teh Krisan	     = Rp 13.000                            |"   <<endl;
		cout<<"|	[7] Kopi Yunnan	     = Rp 25.000                            |"   <<endl;
		cout<<"|	[8] Jus Buah Plum    = Rp 17.000                            |"   <<endl;
		cout<<"|	[9] Deskripsi Menu                                          |"   <<endl;
		cout<<"|	[10] Kembali                                                |"   <<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		
		cout<<"		(Masukkan Pesanan Menu berdasarkan Nomor)"<<endl;
		cout<<" Silahkan Pilih Pesanan anda : "; cin >> pesanan;
		
		// percabangan untuk pesanan
		switch(pesanan){
			case 1:	
				break;
			case 2:
				j=1;
				break;
			case 3:
				j=2;
				break;
			case 4:
				j=3;
				break;
			case 5:
				j=4;
				break;
			case 6:
				j=5;
				break;
			case 7:
				j=6;
				break;
			case 8:
				j=7;
				break;
			case 9: //menampilkan file deskripsi menu
				j=8;
				baca_menuC();
				MenuCina_mem();
				break;	
			case 10:
				Selamat_datang_mem();
				
			default:
				cout << "Pilihan menu yang anda pilih tidak tersedia..." << endl;
				MenuCina_mem();	
		}	
		cout<< "Anda Memilih " << data_cina[j].menu << endl;
		cout<<endl;
		cout<<"Jumlah pesanan yang dibeli : "; cin>>jumlah;	
}



int total_cina_mem(){
	    int diskon, b, tot;
	    tot = jumlah * data_cina[j].harga;
	    diskon = tot * 0.10;
	    tot = tot - diskon;
	return (tot);
}

void struk_cina_mem(){
	int kurang, kembalian, bayar;
	int diskon;
	diskon = jumlah * data_cina[j].harga * 0.10;
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "|  	            Chinese Food                       |" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "\tNama Pemesan          : "	<< nama     <<endl;
	cout << "\tMenu Pesanan          : "	<< data_cina[j].menu  <<endl;
	cout << "\tJumlah Pesanan        : "	<< jumlah   <<" porsi" <<endl;
	cout << "\tHarga Pesanan         : "	<< data_cina[j].harga << " * " << jumlah << endl;
	cout << "\tDiskon Member         : Rp " <<diskon << endl;
	cout << "\tTotal Pembayaran      : Rp " << total_cina_mem()	  <<endl;
	
	cout << "--------------------------------------------" << endl;
	cout << "Silahkan bayar disini 		 : Rp."; 		cin>>bayar;
	cout << endl;

	while (bayar < total_cina_mem()){
		cout << "Saldo anda kurang, Silahkan bayar lagi : Rp. "; cin>>kurang;
		bayar = bayar + kurang;
	}
		
		kembalian = bayar - total_cina_mem();
		cout << "Uang yang anda bayar \t\t\t Rp. " << bayar<<endl;
		cout << "Uang kembalian \t\t\t\t Rp. "     << kembalian <<endl;
		cout << "##################################################"<<endl;
}		



void MenuKorea_mem(){
		cout<<"================================ CK Food ================================"<<endl;
		cout<<"============================== Korean Food =============================="<<endl;
		cout<<endl;
		cout<<"Pilihan menu yang tersedia---"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"|	[1] Korean Bulgogi         = Rp 30.000                            |"   <<endl;
		cout<<"|	[2] Korean Jjangmyeon      = RP 45.000                            |"   <<endl;
		cout<<"|	[3] Korean Cheese Ramyeon  = RP 55.000                            |"   <<endl;
		cout<<"|	[4] Tteokbokki             = Rp 20.000                            |"   <<endl;
		cout<<"|	[5] Bibimbap               = Rp 24.500                            |"   <<endl;
		cout<<"|	[6] Classic Bingsoo        = Rp 25.000                            |"   <<endl;
		cout<<"|	[7] Korean Strawberry Milk = Rp 15.000                            |"   <<endl;
		cout<<"|	[8] Corn Tea               = Rp 12.000                            |"   <<endl;
		cout<<"|	[9] Deskripsi Menu                                                |"   <<endl;
		cout<<"|	[10] Kembali                                                      |"   <<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		
		cout<<"			(Masukkan Pesanan Menu berdasarkan Nomor)"<<endl;
		cout<<" Silahkan Pilih Pesanan anda : "; cin >> pesanan;
		
		//Percabangan
		switch(pesanan){
			case 1:	
				break;
			case 2:
				i=1;	
				break;
			case 3:
				i=2;
				break;
			case 4:
				i=3;
				break;
			case 5:
				i=4;
				break;
			case 6:
				i=5;
				break;
			case 7:
				i=6;
				break;
			case 8:
				i=7;
				break;
			case 9:
				i=8;
				baca_menuK();
				MenuKorea_mem();
				break;
			case 10:
			    Selamat_datang_mem();
			    
			default:
				cout << "Pilihan menu yang anda pilih tidak tersedia..." << endl;
				MenuKorea_mem();
		}
		cout<<"	Anda memilih " << data_korea[i].menu <<endl;
		cout<<endl;
		cout<<"Jumlah makanan yang dibeli : "; cin>> jumlah;
}

void cekstok_korea(){
	if (jumlah > data_korea[i].stok){
		cout<<"Maaf pesanan yang anda pilih melebihi stok kami"<<endl;
		cout<<"Jumlah stok yang tersedia "<< data_korea[i].stok<<endl;
		seadanya = data_korea[i].stok;
		kurang_stok= jumlah - data_korea[i].stok;
		cout<<"Porsi yang ada "<<seadanya<<endl;
		cout<<"Kekurangan porsi "<<kurang_stok<<endl;			
		cout<<"Apakah anda mau membeli sejumlah yang ada di stok? [Y/T]"<<endl;
		cin>>jawab;
		if(jawab=='y'||jawab=='Y'){
			jumlah = data_korea[i].stok;
			data_korea[i].stok = data_korea[i].stok - jumlah;
		}
		else if(jawab=='t'||jawab=='T'){
		    ulang_korea();
		}
		else{
		    cout<<"input tidak valid"<<endl;
		    cekstok_korea();
		}
	}
}

int total_korea_mem(){
	    int diskon, b, tot;
	    tot = jumlah * data_korea[i].harga;
	    diskon = tot * 0.10;
	    tot = tot - diskon;
	return (tot);
}

void struk_korea_mem(){
		int kurang, kembalian, bayar, tot;
		int diskon;
	    diskon = jumlah * data_korea[i].harga * 0.10;
		cout << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "|  	             Korean Food                       |" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "\tNama Pemesan          : "	<< nama     <<endl;
		cout << "\tMenu Pesanan          : "	<< data_korea[i].menu  <<endl;
		cout << "\tJumlah Pesanan        : "	<< jumlah   <<" porsi" <<endl;
		cout << "\tHarga Pesanan         : "	<< data_korea[i].harga << " * " << jumlah << endl;
		cout << "\tDiskon Member         : Rp " <<diskon<<endl;
		cout << "\tTotal Pembayaran      : Rp " << total_korea_mem()  <<endl;
		
		cout << "--------------------------------------------" << endl;
		cout << "Silahkan bayar disini 		 : Rp."; 		cin>>bayar;
		cout << endl;
		
		while (bayar < total_korea_mem()){
			cout << "Saldo anda kurang, Silahkan bayar lagi : Rp. "; cin>>kurang;
			bayar= bayar + kurang;
		}
		
		kembalian = bayar - total_korea_mem();
		cout << "Uang yang anda bayar \t\t\t Rp. " << bayar<<endl;
		cout << "Uang kembalian \t\t\t\t Rp. "     << kembalian <<endl;
		cout << "##################################################"<<endl;
		
}

void laporan_korea(){
	
	fstream tubesFile;
	tubesFile.open("laporan_korea.txt", ios ::app);
	
	tubesFile<<endl<<"Nama : "<<nama<<endl;
	tubesFile<<"Menu makanan : "<<data_korea[i].menu<<endl;
	tubesFile<<"Total : "<<total_korea()<<endl;
	
	tubesFile.close();
}

//BACA FILE
void baca_menuK(){
    fstream menuKFile;
	menuKFile.open("menu_korea.txt", ios::in);
	if(menuKFile.is_open()){
		string line;
		while(getline(menuKFile,line)){
			cout<<line<<endl;
		}
		menuKFile.close();
	}
}

void baca_tentang(){
    fstream tentangFile;
	tentangFile.open("tentang.txt", ios::in);
	if(tentangFile.is_open()){
		string line;
		while(getline(tentangFile,line)){
			cout<<line<<endl;
		}
		tentangFile.close();
	}
}

//NON Member
void Selamat_datang(){

    cout << "==================== SELAMAT DATANG DI CKFOOD ====================" << endl;
    cout << "1. Chinese Food" << endl;
    cout << "2. Korean Food" << endl;
    cout << "3. Tentang" << endl;
    cout << "4. Keluar" << endl;
    cout << endl;
    cout << "Silahkan memilih berdasarkan nomor : "; cin >> pilih;
    
	switch (pilih){
		case 1:do{
			    MenuCina();
			    cekstok_cina();
			    total_cina;
			    struk_cina();
                laporan_cina();
                cout << "[Y = ya / T = tidak]"<<endl;
            	cout << "Apakah anda ingin memesan lagi ? [Y/T]  =  ";
	            cin>>back;}
	            while(back=='y'||back=='Y');
	            Keluar();
			break;
		case 2: do{
			    MenuKorea();
			    cekstok_korea();
			    total_korea();
			    struk_korea();
                laporan_korea();
                cout << "[Y = ya / T = tidak]"<<endl;
            	cout << "Apakah anda ingin memesan lagi ? [Y/T]  =  ";
	            cin>>back;}
	            while(back=='y'||back=='Y');
	            Keluar();
			break;
		case 3:
		    baca_tentang();
		    cout <<endl<< "Ketikkan satu karakter untuk ke menu utama : "<<endl;
	        cin>>back;
	       Selamat_datang();
		case 4:
			Keluar();
			break; 
	 	default:
		cout << "Maaf nomor yang anda masukkan salah" << endl;
	}
}

void MenuCina(){
		cout<<"============================== CK Food =============================="<<endl;
		cout<<"=========================== Chinese Food ============================"<<endl;
		cout<<endl;
		cout<<"Pilihan menu yang tersedia---"<<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		cout<<"|	[1] Fuyunghai        = Rp 23.000                            |"   <<endl;
		cout<<"|	[2] Ayam Koloke      = RP 27.000                            |"   <<endl;
		cout<<"|	[3] Sapo Tahu        = RP 29.000                            |"   <<endl;
		cout<<"|	[4] Hakau            = Rp 20.000                            |"   <<endl;
		cout<<"|	[5] Bakpao           = Rp 21.000                            |"   <<endl;
		cout<<"|	[6] Teh Krisan	     = Rp 13.000                            |"   <<endl;
		cout<<"|	[7] Kopi Yunnan	     = Rp 25.000                            |"   <<endl;
		cout<<"|	[8] Jus Buah Plum    = Rp 17.000                            |"   <<endl;
		cout<<"|	[9] Deskripsi Menu                                          |"   <<endl;
		cout<<"|	[10] Kembali                                                |"   <<endl;
		cout<<"---------------------------------------------------------------------"<<endl;
		
		cout<<"		(Masukkan Pesanan Menu berdasarkan Nomor)"<<endl;
		cout<<" Silahkan Pilih Pesanan anda : "; cin >> pesanan;
		
		// percabangan untuk pesanan
		switch(pesanan){
			case 1:	
				break;
			case 2:
				j=1;
				break;
			case 3:
				j=2;
				break;
			case 4:
				j=3;
				break;
			case 5:
				j=4;
				break;
			case 6:
				j=5;
				break;
			case 7:
				j=6;
				break;
			case 8:
				j=7;
				break;
			case 9: //menampilkan file deskripsi menu
				j=8;
				baca_menuC();
				MenuCina();
				break;	
			case 10:
				Selamat_datang();
				
			default:
				cout << "Pilihan menu yang anda pilih tidak tersedia..." << endl;
				MenuCina();	
		}	
		cout<< "Anda Memilih " << data_cina[j].menu << endl;
		cout<<endl;
		cout<<"Jumlah pesanan yang dibeli : "; cin>>jumlah;	
}

void baca_menuC(){
    fstream menuCFile;
	menuCFile.open("menu_cina.txt", ios::in);
	if(menuCFile.is_open()){
		string line;
		while(getline(menuCFile,line)){
			cout<<line<<endl;
		}
		menuCFile.close();
	}
}

void cekstok_cina(){
	if (jumlah > data_cina[j].stok){
		cout<<"Maaf pesanan yang anda pilih melebihi stok kami"<<endl;
		cout<<"Jumlah stok yang tersedia = "<< data_cina[j].stok<<endl;
		seadanya = data_cina[j].stok;
		kurang_stok= jumlah - data_cina[j].stok;
		cout<<"Porsi yang ada "<<seadanya<<endl;
		cout<<"Kekurangan porsi "<<kurang_stok<<endl;			
		cout<<"Apakah anda mau membeli sejumlah yang ada di stok? [Y/T]"<<endl;
		cin>>jawab;
		if(jawab=='y'||jawab=='Y'){
			jumlah = data_cina[j].stok;
			data_cina[j].stok = data_cina[j].stok - jumlah;
		}
		else if(jawab=='t'||jawab=='T'){
		    ulang_cina();
		}
		else{
		    cout<<"input tidak valid"<<endl;
		    cekstok_cina();
		}
	}
}

void ulang_cina(){
	char kembali;
	cout << "[Y = ya / T = tidak]"<<endl;
	cout << "Apakah anda ingin memesan lagi ? [Y/T]  =  ";
	cin>>kembali;
	if(kembali=='y'||kembali=='Y'){
	    cout<<endl;
        MenuCina();
	}
}

int total_cina(){
		int a;
		a = jumlah * data_cina[j].harga;
	return (a);
}

void struk_cina(){
	int kurang, kembalian, bayar;
	cout << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "|  	            Chinese Food                       |" << endl;
	cout << "-------------------------------------------------------" << endl;
	cout << "\tNama Pemesan          : "	<< nama     <<endl;
	cout << "\tMenu Pesanan          : "	<< data_cina[j].menu  <<endl;
	cout << "\tJumlah Pesanan        : "	<< jumlah   <<" porsi" <<endl;
	cout << "\tHarga Pesanan         : "	<< data_cina[j].harga << " * " << jumlah << endl;
	cout << "\tTotal Pembayaran      : Rp " << total_cina()	  <<endl;
	
	cout << "--------------------------------------------" << endl;
	cout << "Silahkan bayar disini 		 : Rp."; 		cin>>bayar;
	cout << endl;

	while (bayar < total_cina()){
		cout << "Saldo anda kurang, Silahkan bayar lagi : Rp. "; cin>>kurang;
		bayar = bayar + kurang;
	}
		
		kembalian = bayar - total_cina();
		cout << "Uang yang anda bayar \t\t\t Rp. " << bayar<<endl;
		cout << "Uang kembalian \t\t\t\t Rp. "     << kembalian <<endl;
		cout << "##################################################"<<endl;
}

void laporan_cina(){
	
	fstream tubesFile;
	tubesFile.open("laporan_cina.txt", ios ::app);
	
	tubesFile<<endl<<"Nama : "<<nama<<endl;
	tubesFile<<"Menu makanan : "<<data_cina[j].menu<<endl;
	tubesFile<<"Total : "<<total_cina()<<endl;
	
	tubesFile.close();
}

void Keluar(){
	cout << "======================= Terimakasih telah mengunjungi CK Food =======================" << endl;
	cout << "================================ Sampai jumpa kembali ===============================" << endl;
	exit(0);
}



void MenuKorea(){
		cout<<"================================ CK Food ================================"<<endl;
		cout<<"============================== Korean Food =============================="<<endl;
		cout<<endl;
		cout<<"Pilihan menu yang tersedia---"<<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		cout<<"|	[1] Korean Bulgogi         = Rp 30.000                            |"   <<endl;
		cout<<"|	[2] Korean Jjangmyeon      = RP 45.000                            |"   <<endl;
		cout<<"|	[3] Korean Cheese Ramyeon  = RP 55.000                            |"   <<endl;
		cout<<"|	[4] Tteokbokki             = Rp 20.000                            |"   <<endl;
		cout<<"|	[5] Bibimbap               = Rp 24.500                            |"   <<endl;
		cout<<"|	[6] Classic Bingsoo        = Rp 25.000                            |"   <<endl;
		cout<<"|	[7] Korean Strawberry Milk = Rp 15.000                            |"   <<endl;
		cout<<"|	[8] Corn Tea               = Rp 12.000                            |"   <<endl;
		cout<<"|	[9] Deskripsi Menu                                                |"   <<endl;
		cout<<"|	[10] Kembali                                                      |"   <<endl;
		cout<<"--------------------------------------------------------------------------"<<endl;
		
		cout<<"			(Masukkan Pesanan Menu berdasarkan Nomor)"<<endl;
		cout<<" Silahkan Pilih Pesanan anda : "; cin >> pesanan;
		
		//Percabangan
		switch(pesanan){
			case 1:	
				break;
			case 2:
				i=1;	
				break;
			case 3:
				i=2;
				break;
			case 4:
				i=3;
				break;
			case 5:
				i=4;
				break;
			case 6:
				i=5;
				break;
			case 7:
				i=6;
				break;
			case 8:
				i=7;
				break;
			case 9:
				i=8;
				baca_menuK();
				MenuKorea();
				break;
			case 10:
			    Selamat_datang();
			    
			default:
				cout << "Pilihan menu yang anda pilih tidak tersedia..." << endl;
				MenuKorea();
		}
		cout<<"	Anda memilih " << data_korea[i].menu <<endl;
		cout<<endl;
		cout<<"Jumlah makanan yang dibeli : "; cin>> jumlah;
}

int total_korea(){
		int a;
		a = jumlah * data_korea[i].harga;
	return(a);
}

void struk_korea(){
		int kurang, kembalian, bayar;
		cout << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "|  	             Korean Food                       |" << endl;
		cout << "-------------------------------------------------------" << endl;
		cout << "\tNama Pemesan          : "	<< nama     <<endl;
		cout << "\tMenu Pesanan          : "	<< data_korea[i].menu  <<endl;
		cout << "\tJumlah Pesanan        : "	<< jumlah   <<" porsi" <<endl;
		cout << "\tHarga Pesanan         : "	<< data_korea[i].harga << " * " << jumlah << endl;
		cout << "\tTotal Pembayaran      : Rp " << total_korea()  <<endl;
		
		cout << "--------------------------------------------" << endl;
		cout << "Silahkan bayar disini 		 : Rp."; 		cin>>bayar;
		cout << endl;
		
		while (bayar < total_korea()){
			cout << "Saldo anda kurang, Silahkan bayar lagi : Rp. "; cin>>kurang;
			bayar= bayar + kurang;
		}
		
		kembalian = bayar - total_korea();
		cout << "Uang yang anda bayar \t\t\t Rp. " << bayar<<endl;
		cout << "Uang kembalian \t\t\t\t Rp. "     << kembalian <<endl;
		cout << "##################################################"<<endl;
		
}

void ulang_korea(){
	cout << "[Y = ya / T = tidak]"<<endl;
	cout << "Apakah anda ingin memesan lagi ? [Y/T]  =  ";
	cin>>kembali;
	if(kembali=='y'||kembali=='Y'){
	    cout<<endl;
        MenuKorea();
	}
}





