#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Buku;
class Penerbit;
class Pengarang {
public:
	string namaPengarang;
	vector<Penerbit*> daftar_penerbit;
	vector<Buku*> daftar_buku;

	Pengarang(string pNama) : namaPengarang(pNama) {}
	~Pengarang() {
		cout << "Pengarang \"" << namaPengarang << "\" Dihapus \n";
	}

	void tambahPenerbit(Penerbit*);
	void cetakPenerbit();

	void tambahBuku(Buku*);
	void cetakBuku();
};

class Penerbit {
public:
	string namaPenerbit;
	vector<Pengarang*> daftar_pengarang;

	Penerbit(string pNama) : namaPenerbit(pNama){}
	~Penerbit() {
		cout << "Penerbit \"" << namaPenerbit << "\" Dihapus\n";
	}

	void tambahPengarang(Pengarang*);
	void cetakPengarang();
};



class Buku {
public:
	string namaBuku;
	Buku(string pBuku) : namaBuku(pBuku){}
	~Buku() {
		cout << "Buku \"" << namaBuku << "\" Dihapus \n";
	}
};


// Penerbit Asosiasi
void Penerbit::tambahPengarang(Pengarang* pPengarang) {
	daftar_pengarang.push_back(pPengarang);
}
void Penerbit::cetakPengarang() {
	cout << "Daftar Pengarang pada penerbit \"" << this->namaPenerbit << "\":\n";
	for (auto& a : daftar_pengarang) {
		cout << a->namaPengarang << "\n";
	}
	cout << endl;
}

// Pengarang Asosiasi
void Pengarang::tambahPenerbit(Penerbit* pPenerbit) {
	daftar_penerbit.push_back(pPenerbit);
}
void Pengarang::cetakPenerbit() {
	cout << "Daftar penerbit yang diikuti \"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_penerbit) {
		cout << a->namaPenerbit << "\n";
	}
	cout << endl;
}

// Pengarang Agregasi
void Pengarang::tambahBuku(Buku* pBuku) {
	daftar_buku.push_back(pBuku);
}
void Pengarang::cetakBuku() {
	cout << "Daftar Buku yang dikarang \"" << this->namaPengarang << "\":\n";
	for (auto& a : daftar_buku) {
		cout << a->namaBuku << "\n";
	}
	cout << endl;
}

int main()
{
	// Penerbit
	Penerbit* pn1 = new Penerbit("Game Press");
	Penerbit* pn2 = new Penerbit("Royal Press");

	// Pengarang
	Pengarang* pg1 = new Pengarang("Abian");
	Pengarang* pg2 = new Pengarang("Indra");

	// Buku
	Buku* bk1 = new Buku("OOP1");
	Buku* bk2 = new Buku("OOP2");
	Buku* bk3 = new Buku("OOP3");
	Buku* bk4 = new Buku("OOP4");

	// Pengarang -> Penerbit
	pg1->tambahPenerbit(pn1);
	pg1->tambahPenerbit(pn2);
	pg2->tambahPenerbit(pn1);

	// Penerbit -> pengarang
	pn1->tambahPengarang(pg1);
	pn1->tambahPengarang(pg2);
	pn2->tambahPengarang(pg1);

	// Pengarang -> Buku
	pg1->tambahBuku(bk1);
	pg1->tambahBuku(bk3);
	pg2->tambahBuku(bk2);
	pg2->tambahBuku(bk4);

	pn1->cetakPengarang();
	pn2->cetakPengarang();
	pg1->cetakPenerbit();
	pg2->cetakPenerbit();
	pg1->cetakBuku();
	pg2->cetakBuku();
	
	delete pg1;
	delete pg2;
	delete pn1;
	delete pn2;

	delete bk1;
	delete bk2;
	delete bk3;
	delete bk4;
	

	
}

