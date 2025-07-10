#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int MAX = 100;

struct Buku {
    int nomor;
    string judul;
    int stok;
};

Buku daftarBuku[MAX];
int jumlahBuku = 0;

//bool openFIle(){
//	file.open(filename.c_str());
//	return file.is_open();
//}
//
//void readFile() {
//	if (!File) {
//		cout << "Gagal Membuka File!" << endl;
//		return;
//	}
//	cout << "Isi File " << filename << ": " << endl;
//	while (file.getline(buffer, bufferSize)) {
//		cout << buffer << endl;
//	}
//}
//
//FileRider() {
//	if(file.is_open()) {
//		file.close();
//	}
//	delete[] buffer;
//	buffer = NULL;
//}

void tambahBuku() {
    if (jumlahBuku >= MAX) {
        cout << "Data penuh!\n";
        return;
    }
    Buku b;
    cout << "Nomor Buku: "; cin >> b.nomor;
    cin.ignore();
    cout << "Judul Buku: "; getline(cin, b.judul);
    cout << "Stok: "; cin >> b.stok;
    daftarBuku[jumlahBuku++] = b;
    cout << "Buku ditambahkan.\n";
}

void cariBuku() {
    string ketemu;
    cout << "Masukkan judul yang dicari: ";
    cin.ignore(); getline(cin, ketemu);
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].judul.find(ketemu) != string::npos) {
            cout << "Nomor : " <<daftarBuku[i].nomor << "  | Judul :  " << daftarBuku[i].judul << "	| Stok: " << daftarBuku[i].stok << endl;
        }
    }
    cout << endl;
}

void tampilkanBuku() {
    cout << "\n=== Daftar Buku Inventaris ===\n";
    for (int i = 0; i < jumlahBuku; i++) {
        cout << "Nomor : " << daftarBuku[i].nomor << "  | Judul :  " << daftarBuku[i].judul << "	| Stok: " << daftarBuku[i].stok << endl;
    }
    cout << endl;
}

void urutkanJudulAZ() {
    for (int i = 0; i < jumlahBuku - 1; i++) {
        for (int j = i + 1; j < jumlahBuku; j++) {
            if (daftarBuku[i].judul > daftarBuku[j].judul) {
                Buku temp = daftarBuku[i];
                daftarBuku[i] = daftarBuku[j];
                daftarBuku[j] = temp;
            }
        }
    }
    cout << "Data buku diurutkan berdasarkan judul A-Z.\n";
    tampilkanBuku();
    cout << endl;
}

void simpanKeFile() {
    ofstream out("stok_buku.txt");
    for (int i = 0; i < jumlahBuku; i++) {
        out << daftarBuku[i].nomor << " | " << daftarBuku[i].judul
            << " | " << daftarBuku[i].stok << endl;
    }
    out.close();
    cout << "Data buku disimpan ke file stok_buku.txt\n";
    cout << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n===MENU ADMIN INVENTARIS BUKU===" << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Cari Buku" << endl;
        cout << "3. Lihat Semua Buku" << endl;
        cout << "4. Urutkan Judul A-Z" << endl;
        cout << "5. Simpan ke File" << endl;
        cout << "6. Logout" << endl;
        cout << "================================" << endl;
        cout << "Pilih: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tambahBuku(); break;
            case 2: cariBuku(); break;
            case 3: tampilkanBuku(); break;
            case 4: urutkanJudulAZ(); break;
            case 5: simpanKeFile(); break;
        }
    } while (pilihan != 6);

    return 0;
}

