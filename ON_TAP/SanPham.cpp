#include <bits/stdc++.h>
using namespace std;
 
class SANPHAM {
	private:
		string ten;
		double gia;
	public:
		SANPHAM(string ten, double gia) : ten(ten), gia(gia) {}
		string getTen() {
			return ten;
		}
		// Duoc a
		double getGia() {
			return gia;
		}
		void setTen(string ten) {
			this->ten = ten;
		}
		void setGia(double gia) {
			this->gia = gia;
		}
		virtual void input(){
			cout << "Nhap thong tin san pham:\n";
			cin.ignore();
			cout << "Ten: "; getline(cin, this->ten);
			cout << "Gia: "; cin >> this->gia;
		}
		virtual void output() {
			cout << "Thong tin san pham:\n";
			cout << "Ten: " << ten << "\n" \
			<< "Gia: " << gia << "\n";
		}
		virtual double money() = 0;
};
 
class DOHOP : public SANPHAM {
	private:
		int quan; // quantity
	public:
		DOHOP(string ten, double gia, int quan) : SANPHAM(ten, gia), quan(quan) {}
		void input() {
			SANPHAM::input();
			cout << "So luong nguoi yeu anh Quan: "; cin >> quan;
		}
		// Ham thanh toan lam ham ao hay gi a?
		double money() {
			return quan * SANPHAM::getGia();
		}
		void output() {
			SANPHAM::output();
			cout << "So luong: " << quan << "\n" \
			<< "Tien can thanh toan: " << money() << "\n";
		}
};
 
class RAUQUAN : public SANPHAM {
	private:
		double weight;
	public:
		RAUQUAN(string ten, double gia, double weight) : SANPHAM(ten, gia), weight(weight) {}
		void input() {
			SANPHAM::input();
			cout << "Can nang cua anh Quan: "; cin >> weight;
		}
		// Ham thanh toan lam ham ao hay gi a?
		double money() {
			return weight * SANPHAM::getGia();
		}
		void output() {
			SANPHAM::output();
			cout << "Can nang: " << weight << "\n" \
			<< "Tien can thanh toan: " << money() << "\n";
		}
};
 
int main() {
	cout << "Nhap so san pham: "; int n; cin >> n;
	vector<SANPHAM*> sp; 
	for (int i = n; i > 0; --i) {
		int type;
		do {
			cout << "Nhap 1 de do hop hoac 0 rau qua: "; cin >> type;
			if (type) {
				DOHOP* dh = new DOHOP("", 0, 0);
				dh->input();
				sp.push_back(dh);
			} else {
				RAUQUAN* rq = new RAUQUAN("", 0, 0);
				rq->input();
				sp.push_back(rq);
			}
		} while(type != 1 && type != 0);
	}
	double maxPrice = 0;
	int idx = 0;
	for (int i = 0; i < n; ++i) {
		sp[i]->output();
		if (sp[i]->money() > maxPrice) {
			maxPrice = sp[i]->money();
			idx = i;
		}
	}
	cout << "San pham thanh toan nhieu nhat dau tien:\n";
	sp[idx]->output();
}