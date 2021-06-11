#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int n;

struct person{
	int id, nim;
	float ipk;
	string nama_mahasiswa;
	string prodi;
	} persons[5];

int input_data(){
  cout << "masukkan jumlah data: ";
  (cin>>n).get();
  cout << endl;
  
  for(int i=0;i<n;i++){
  	cout << "Masukkan nama mahasiswa: ";
  	getline(cin, persons[i].nama_mahasiswa);
  	
  	cout << "Masukkan NIM mahasiswa: ";
  	(cin>>persons[i].nim).get();
  	
  	cout << "Masukkan IPK mahasiswa: ";
  	(cin>>persons[i].ipk).get();
  	
  	cout << "Masukkan prodi mahasiswa: ";
  	getline(cin, persons[i].prodi);
  	
  	cout << endl;	
  }	
}
    
int report_data(){
	float max = 0;
	string siswa_ipk_tinggi;
	
	const char separator    = ' ' ;
	const int idWidth      = 3;
    const int nameWidth     = 40;
    const int numWidth      = 8;
    const int lineWidth     = 4;
    
	cout << "Hasil output: \n";
  
    cout << left << setw(idWidth) << setfill(separator) << "ID";
    cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(nameWidth) << setfill(separator) << "Nama Mahasiswa";
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(numWidth) << setfill(separator) << "NIM";
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(numWidth) << setfill(separator) << "IPK";
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(nameWidth) << setfill(separator) << "Prodi";
  	cout << endl;
  	cout << "--------------------------------------------------------------------------------\n";
  	
  for(int i=0;i<n;i++){
  	persons[i].id = i+1;
  	cout << left << setw(idWidth) << setfill(separator) << persons[i].id;
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(nameWidth) << setfill(separator) << persons[i].nama_mahasiswa;
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(numWidth) << setfill(separator) << persons[i].nim;
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(numWidth) << setfill(separator) << persons[i].ipk;
  	cout << left << setw(lineWidth) << setfill(separator) << "|";
  	cout << left << setw(nameWidth) << setfill(separator) << persons[i].prodi;
  	cout << endl;
  	
  	if(max < persons[i].ipk){
  		max = persons[i].ipk;
  		siswa_ipk_tinggi = persons[i].nama_mahasiswa;
	  }  
  }
  cout << "Mahasiswa dengan IPK tertinggi adalah " << siswa_ipk_tinggi << " dengan IPK: " << max << endl << endl; 
}

int sequentialsearch_data(int nimsearch_elements, int flags){

	for(int i=0;i<n;i++){
		if(nimsearch_elements == persons[i].nim){
			flags = i;
		}
	}
	
	if(flags!=-1){
		cout << "NIM " << nimsearch_elements << " ditemukan dengan keterangan: \n";
		persons[flags].id = flags + 1;
  		cout << "Id      : " << persons[flags].id << endl;
		cout << "Nama    : " << persons[flags].nama_mahasiswa << endl;
		cout << "NIM     : " << persons[flags].nim << endl;
		cout << "IPK     : " << persons[flags].ipk << endl;
		cout << "Prodi   : " << persons[flags].prodi << endl << endl;
		
	} else{
		cout << "Data " << nimsearch_elements << " tidak ditemukan \n\n";
	}
	
}

int sorting(){
	int temp_nim;
	string temp_nama, temp_prodi;
	float temp_ipk;
	//proses pengurutan data (jika data belum urut)
	for(int i=1;i<n;i++){
		for(int j=n-1;j>=i;j--){
			if(persons[j].nim < persons[j-1].nim){
				temp_nim = persons[j].nim;
				persons[j].nim = persons[j-1].nim;
				persons[j-1].nim = temp_nim;
				
				temp_nama = persons[j].nama_mahasiswa;
				persons[j].nama_mahasiswa = persons[j-1].nama_mahasiswa;
				persons[j-1].nama_mahasiswa = temp_nama;
				
				temp_ipk = persons[j].ipk;
				persons[j].ipk = persons[j-1].ipk;
				persons[j-1].ipk = temp_ipk;
				
				temp_prodi = persons[j].prodi;
				persons[j].prodi = persons[j-1].prodi;
				persons[j-1].prodi = temp_prodi;
			}
		}
	}
	
	cout << "Data (NIM) setelah diurutkan: \n\n";
	
	const int idWidth = 3, nameWidth = 40, numWidth = 8, lineWidth = 4;
	const char separator = ' ';
    
	for(int i=0;i<n;i++){
		persons[i].id = i+1;
  		cout << left << setw(idWidth) << setfill(separator) << persons[i].id;
  		cout << left << setw(lineWidth) << setfill(separator) << "|";
  		cout << left << setw(nameWidth) << setfill(separator) << persons[i].nama_mahasiswa;
  		cout << left << setw(lineWidth) << setfill(separator) << "|";
  		cout << left << setw(numWidth) << setfill(separator) << persons[i].nim;
  		cout << left << setw(lineWidth) << setfill(separator) << "|";
  		cout << left << setw(numWidth) << setfill(separator) << persons[i].ipk;
  		cout << left << setw(lineWidth) << setfill(separator) << "|";
  		cout << left << setw(nameWidth) << setfill(separator) << persons[i].prodi;
  		cout << endl << endl;
	}
	
}

int binarysearch_data(int nimsearch_elements, int flags){
	sorting(); //fungsi untuk mengurutkan data yang belum terurut
	int awal, tengah, akhir;
	
	//proses pencarian data (setelah data berhasil diurutkan)
	awal = 0;
	akhir = n-1;
	tengah = (awal+akhir)/2;
	
	do{
		if(nimsearch_elements < persons[tengah].nim){
			akhir = tengah - 1;
		}
		else if(nimsearch_elements > persons[tengah].nim){
			awal = tengah + 1;
		}
		tengah = (awal+akhir)/2;
	}
	while(awal <= akhir && nimsearch_elements != persons[tengah].nim);
	
	if(nimsearch_elements == persons[tengah].nim){
		flags = tengah;
	}
	
	if(flags!=-1){
		cout << "data " << nimsearch_elements << " ditemukan dengan keterangan: \n";
		persons[flags].id = flags + 1;
  		cout << "Id      : " << persons[flags].id << endl;
		cout << "Nama    : " << persons[flags].nama_mahasiswa << endl;
		cout << "NIM     : " << persons[flags].nim << endl;
		cout << "IPK     : " << persons[flags].ipk << endl;
		cout << "Prodi   : " << persons[flags].prodi << endl << endl;
	} else{
		cout << "data " << nimsearch_elements << " tidak ditemukan \n";
	}
}

int interpolsearch_data(int nimsearch_elements, int flags){
	sorting(); //fungsi untuk mengurutkan data yang belum terurut
	int rendah, tinggi, pos;
	float posisi;
	
	//proses pencarian data (setelah data berhasil diurutkan)
	rendah = 0;
	tinggi = n-1;
	
	do{
		posisi = ((nimsearch_elements - persons[rendah].nim) / (persons[tinggi].nim - persons[rendah].nim));
		posisi = posisi * (tinggi-rendah) + rendah;
		pos = floor(posisi);
		
		if(nimsearch_elements == persons[pos].nim){
			flags = pos;
			break;
		}
		
		if(nimsearch_elements < persons[pos].nim){
			tinggi = pos - 1;
		} else if(nimsearch_elements > persons[pos].nim){
			rendah = pos + 1;
		}
	}
	while(nimsearch_elements >= persons[rendah].nim && nimsearch_elements <= persons[tinggi].nim);
	
	if(flags!=-1){
		cout << "data " << nimsearch_elements << " ditemukan dengan keterangan: \n";
		persons[flags].id = flags + 1;
  		cout << "Id      : " << persons[flags].id << endl;
		cout << "Nama    : " << persons[flags].nama_mahasiswa << endl;
		cout << "NIM     : " << persons[flags].nim << endl;
		cout << "IPK     : " << persons[flags].ipk << endl;
		cout << "Prodi   : " << persons[flags].prodi << endl << endl;
		
	} else{
		cout << "data " << nimsearch_elements << " tidak ditemukan \n";
	}
}

int searching_data(){
	int searching;
	int nimsearch_element = 0, flag = -1;

	cout << "Masukkan NIM mahasiswa yang ingin dicari: ";
	cin >> nimsearch_element;
	cout << endl;
	
	cout << "Pilih metode searching yang ada:"<<endl;
	cout << "1. Sequential Search" << endl;
	cout << "2. Binary Search" << endl;
	cout << "3. Interpolation Search " << endl;
	cout << "Kamu memilih nomor: ";
	cin >> searching;
	cout << endl;
	
	enum opsi{SEQUENTIAL = 1, BINARY, INTERPOLATION};
	
	switch(searching){
		case SEQUENTIAL:
			cout << "Metode Sequential Search\n" << "---------------------------\n";
			sequentialsearch_data(nimsearch_element, flag);
			break;
		case BINARY:
			cout << "Metode Binary Search\n" << "---------------------------\n";
			binarysearch_data(nimsearch_element, flag);
			break;
		case INTERPOLATION:
			cout << "Metode Interpolation Search" << "---------------------------\n";
			interpolsearch_data(nimsearch_element, flag);
			break;
		default:
			cout << "Anda salah memasukkan kode" << endl;
			break;	
	}
}

int option(){
	int nomor;
	
	cout << "Pilih Menu yang ada:\n";
	cout << "1. Input Data" << endl;
	cout << "2. Searching Data" << endl;
	cout << "3. Report Data " << endl;
	cout << "4. Selesai"      << endl;
	cout << "Kamu memilih nomor: ";
	cin >> nomor;
	cout << endl;
	
	return nomor;
}

int main(){
	cout << "Program Data Mahasiswa Noviyana - 20200801048\n";
	cout << "---------------------------------------------\n\n";
	
	int pilih = option();
	char lanjut;
	
	enum opsi{ INPUT = 1, SEARCH, READ, FINISH};
	
	while(pilih!= FINISH){
		switch(pilih){
			case INPUT:
				input_data();
				break;
			case SEARCH:
				searching_data();
				break;
			case READ:
				report_data();
				break;
			default:
				cout << "Anda salah memasukkan kode" << endl;
				break;	
	    }
	    
		pil_lanjut:
		
		cout << "Kembali ke menu utama? (Y/N) :";
		cin >> lanjut;
		if((lanjut == 'y') | (lanjut == 'Y')){
	   		pilih = option();
		}
		else if((lanjut == 'n') | (lanjut == 'N')){
	    	break;
		}
		else{
			goto pil_lanjut;
		} 
  	} // akhir while loop
  	
	cout << "Program telah selesai" << endl;
	return 0;
}
