#include<bits/stdc++.h>
using namespace std;

// Lớp cơ sở Người:
class Nguoi{
    private:
        string HoTen;
        int NamSinh;
    public:
        Nguoi(){
            HoTen = "Unknown";
            NamSinh = 0;
        }

        Nguoi(string HoTen, int NamSinh){
            this->HoTen = HoTen;
            this->NamSinh = NamSinh;
        }

        virtual void nhap(){
            cout << "Nhap ho ten: "; getline(cin,HoTen);
            cout << "Nhap nam sinh: "; cin >> NamSinh; cin.ignore();
        }

        virtual void xuat(){
            cout << "Ho ten: " << HoTen << endl;
            cout << "Nam sinh: " << NamSinh << endl;
        }

      int getNamSinh(){
        return NamSinh;
      };
      
      void setNamSinh(int NamSinh){
      	this->NamSinh = NamSinh;
	  };
	  
	  string getHoTen(){
	  	return this->HoTen;
	  }
	  
	  void setHoTen(string HoTen){
	  	this->HoTen = HoTen;
	  }
};

// Lớp dẫn xuất Bệnh Nhân:
class BenhNhan : public Nguoi{
    private:
        int SoNgayNamVien;
        string BenhAn;
        double GiaTienDieuTri;
    public:
        BenhNhan(){};
        BenhNhan(string HoTen, int NamSinh, string BenhAn, int SoNgayNamVien, double Gia) : Nguoi(HoTen,NamSinh){
            this->SoNgayNamVien = SoNgayNamVien;
            this->BenhAn = BenhAn;
            this->GiaTienDieuTri = Gia;
        };

        int getTuoi(){
            return 2024 - Nguoi::getNamSinh();
        }

        double TienVienPhi(){
            return SoNgayNamVien*GiaTienDieuTri;
        };

        void nhap(){
            Nguoi::nhap();
            cout << "Nhap benh an: "; getline(cin,BenhAn);
            cout << "Nhap so ngay nam vien: "; cin >> SoNgayNamVien; cin.ignore();
            cout << "Nhap gia tien dieu tri / ngay: "; cin >> GiaTienDieuTri; cin.ignore();
        };

        void xuat(){
            Nguoi::xuat();
            cout << "Tuoi: "<< getTuoi() << endl;
            cout << "Benh an:" << BenhAn << endl;
            cout << "So ngay nam vien: " << SoNgayNamVien << endl;
            cout << "So tien dieu tri / ngay: "<< GiaTienDieuTri << endl;
            cout << "Vien phi: " << TienVienPhi() << endl;
        };
};

//Lớp dẫn xuất Bác Sĩ
class BacSi : public Nguoi{
    private:
        string MaBS;
        int SoNgayLamViec;
        int TienCongNgay;
    public:
        BacSi(){};

        BacSi(string HoTen, int NamSinh, string MaBS, int SoNgayLamViec, int TienCongNgay) : Nguoi(HoTen,NamSinh){
            this->MaBS = MaBS;
            this->SoNgayLamViec = SoNgayLamViec;
            this->TienCongNgay = TienCongNgay;
        };

        int TienCongThang(){
            return SoNgayLamViec*TienCongNgay;
        };

        void nhap(){
            Nguoi::nhap();
            cout << "Nhap ma bac si: "; getline(cin,MaBS);
            cout << "Nhap so ngay lam viec: "; cin >> SoNgayLamViec; cin.ignore();
            cout << "Nhap tien cong ngay: "; cin >> TienCongNgay; cin.ignore();
        };

        void xuat(){
            Nguoi::xuat();
            cout << "Ma bac si: " << MaBS << endl;
            cout << "So ngay lam viec: " << SoNgayLamViec << endl;
            cout << "Tien cong thang: " << TienCongThang() << endl;
        };
        
        int getSoNgayLamViec(){
        	return this->SoNgayLamViec;
		}
		
		void setSoNgayLamViec(int Ngay){
			SoNgayLamViec = Ngay;
		}
};

int main(){
	vector<Nguoi*> DanhSachNguoi;
	int n; 
	cout << "Nhap so luong nguoi: "; cin >> n; cin.ignore();
	
	// Nhập danh sách người:
	for(int i=0; i<n; i++){
		cout << "\n>> Nguoi thu " << i+1 << ":";
		cout << "\n>> Bam [1] de nhap BenhNhan hoac [2] de nhap BacSi: ";
		int choice;
		cin >> choice; cin.ignore();
		if (choice == 1){
			BenhNhan* bn = new BenhNhan;
			bn->nhap();
			DanhSachNguoi.push_back(bn);
		}
		else if(choice == 2){
			BacSi* bs = new BacSi;
			bs->nhap();
			DanhSachNguoi.push_back(bs);
		}
		else{
			cout << "Loai khong hop le, vui long nhap lai!" << endl;
			i--; 
		}
	}
	
	// Xuất danh sách vừa nhập:	
	cout << "\n\n\n\n# Danh sach nguoi vua nhap: "
	for (int i = 0; i < DanhSachNguoi.size(); i++) {
        DanhSachNguoi[i]->xuat();
        cout << endl;
    }
    
	// In ra danh sách các bệnh nhân có tuổi nhỏ hơn hoặc bằng 10:
	cout << "\n\n\n\n # Danh sach benh nhan co tuoi nho hon 10:\n";
	for (int i=0; i<n; i++){
		BenhNhan* bn = dynamic_cast<BenhNhan*>(DanhSachNguoi[i]); //ép kiểu
        if (bn && bn->getTuoi() <= 10) {
            bn->xuat();
            cout << endl;
        }    
	}
	
	// Thông tin bác sĩ có ngày làm việc nhiều nhất
	int maxNgayLamViec = 0;
    BacSi* BacSiNhieuNhat;

    for (int i = 0; i < n; i++) {
        BacSi* bs = dynamic_cast<BacSi*>(DanhSachNguoi[i]);
        if (bs && bs->getSoNgayLamViec() > maxNgayLamViec) {
            maxNgayLamViec = bs->getSoNgayLamViec();
            BacSiNhieuNhat = bs;
        }
    }
	
	cout << "\n\n\n\n# Thong tin Bac Si co so ngay lam viec nhieu nhat:\n";
	BacSiNhieuNhat->xuat();
    return 0;
}