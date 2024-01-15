#include<bits/stdc++.h>
using namespace std;

class NhanVien{
	// khai báo là protected để lớp con truy cập
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		//Constructor:
		NhanVien(){};
		NhanVien(string Ten, int NamSinh, string GioiTinh, string DiaChi){
			this->DiaChi = DiaChi;
			this->GioiTinh = GioiTinh;
			this->HoTen = Ten;
			this->NamSinh = NamSinh;
		}
		
		// Truy cập:
		string getHoTen(){
			return HoTen;
		}
		
		// Nhập:
		friend istream& operator >> (istream& in, NhanVien &NV){
			cout << "Nhap ho ten: "; getline(in,NV.HoTen);
			cout << "Nhap nam sinh: "; in >> NV.NamSinh; in.ignore();
			cout << "Nhap gioi tinh: "; in >> NV.GioiTinh;
			cout << "Nhap dia chi: "; in >> NV.DiaChi;
			return in;
		} 
		
		//Xuất:
		friend ostream& operator << (ostream& out, NhanVien &NV){
			out << "Ho ten: " << NV.HoTen << endl;
			out << "Nam Sinh: " << NV.NamSinh << endl;
			out << "Gioi Tinh: " << NV.GioiTinh << endl;
			out << "Dia chi: " << NV.DiaChi << endl;
			return out;
		}
};

// Lớp dẫn xuất:
class CongNhan : public NhanVien{
	private:
		int TienLuong;
		string CongViec;
	public:
		CongNhan(){};
		CongNhan(string Ten, int NamSinh, string GioiTinh, string DiaChi, int TienLuong, string CongViec) : NhanVien(Ten,NamSinh,GioiTinh,DiaChi){
			this->TienLuong = TienLuong;
			this->CongViec = CongViec;
		}
		
		//Toán tử nhập kế thừa từ lớp cơ sở:
		friend istream& operator >> (istream& in, CongNhan &CN){
			in >> (NhanVien&)(CN);
			cout << "Nhap Tien Luong: "; in >> CN.TienLuong; in.ignore();
			cout << "Nhap Cong Viec: "; getline(in,CN.CongViec);
			return in;
		}
		
		// Toán tử xuất:
		friend ostream& operator << (ostream& out, CongNhan& CN){
			out << (NhanVien&) (CN);
			out << "Tien Luong: " << CN.TienLuong << endl;
			out << "Cong Viec: " << CN.CongViec << endl;
			return out;
		}
};

int main(){
	int n;
	cout << "#Nhap so cong nhan: "; cin >> n; cin.ignore();
	vector<CongNhan> DanhSachCongNhan;
	
	// Nhập danh sách công nhân:
	for (int i=0; i<n; i++){
		cout << "\n>> Cong nhan thu " << i+1 << ":\n";
		CongNhan cn;
		cin >> cn;
		DanhSachCongNhan.push_back(cn);
	}
	
	// Xuất danh sách công nhân vừa nhập:
	cout << "\n\n\n\n#Danh sach cong nhan vua nhap:\n";
	for (int i=0; i<n; i++){
		cout << "\n>> Cong nhan thu " << i+1 << ":\n";
		cout << DanhSachCongNhan[i];
	}
	
	// Tìm kiếm nhân viên theo họ tên:
	string Name;
	cout << "\n\n\n\n #Nhap ten nhan vien can tim: "; getline(cin,Name);
	regex TenCanTim = regex(Name,regex_constants::icase);
	for (int i=0; i<DanhSachCongNhan.size();i++){
		if (regex_match(DanhSachCongNhan[i].getHoTen(),TenCanTim))
			cout << DanhSachCongNhan[i] << endl;
	} 
	return 0;
}