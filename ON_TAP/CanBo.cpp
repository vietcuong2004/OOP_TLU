#include<bits/stdc++.h>
using namespace std;

//Lớp cơ sở CAN_BO:
class CAN_BO{
	protected:
		string HoTen;
		int NamSinh;
		string GioiTinh;
		string DiaChi;
	public:
		//Constructor
		CAN_BO(){
			HoTen = GioiTinh = DiaChi = "Unknown";
			NamSinh = 0;
		}
		CAN_BO(string HoTen, string GioiTinh,string DiaChi, int NamSinh){
			this->HoTen = HoTen;
			this->DiaChi = DiaChi;
			this->GioiTinh = GioiTinh;
			this->NamSinh = NamSinh;
		}
		
		// Các hàm truy cập:
		string getHoTen(){
			return HoTen;
		}
		
		string getGioiTinh(){
			return GioiTinh;
		}
		
		string getDiaChi(){
			return DiaChi;
		}
		
		int getNamSinh(){
			return NamSinh;
		}
		
		//Các hàm sửa đổi:
		void setHoTen(string HoTen){
			this->HoTen = HoTen;
		}
		void setGioiTinh(string GioiTinh){
			this->GioiTinh = GioiTinh;
		}
		void setDiaChi(string DiaChi){
			this->DiaChi = DiaChi;
		}
		void setNamSinh(int NamSinh){
			this->NamSinh = NamSinh;
		}
		
		// Nhập thông tin:
		virtual void Nhap(){
			cout << "Nhap ten: ";  getline(cin,HoTen);
			cout << "Nhap nam sinh: "; cin >> NamSinh; cin.ignore();
			cout << "Nhap gioi tinh: "; getline(cin,GioiTinh);
			cout << "Nhap dia chi: "; getline(cin,DiaChi);
		}
		
		//Xuất thông tin:
		virtual void Xuat(){
			cout << "Ho ten: " << HoTen << endl;
			cout << "Gioi Tinh: " << GioiTinh << endl;
			cout << "Nam sinh: " << NamSinh << endl;
			cout << "Dia chi: " << DiaChi << endl;	
		}
		
		// Tinh tuoi:
		int getTuoi(){
			return 2024 - NamSinh;
		}
		
		// Toán tử !=:
		friend bool operator != (CAN_BO a , CAN_BO b){
			return a.getHoTen() != b.getHoTen(); 
		};
		
};

//Class CONG_NHAN:
class CONG_NHAN : public CAN_BO{
	private:
		string Bac;
	public:
		//Constructor:
		CONG_NHAN(){
			Bac = "Unknown";
		}
		
		CONG_NHAN(string HoTen, string GioiTinh,string DiaChi, int NamSinh, string Bac) : CAN_BO(HoTen,GioiTinh,DiaChi,NamSinh){
			this->Bac = Bac;
		}
		
		//Nhập:
		void Nhap(){
			CAN_BO::Nhap();
			cout << "Nhap bac cua cong nhan (x/7): "; getline(cin,Bac);
		}
		
		//Xuất:
		void Xuat(){
			CAN_BO::Xuat();
			cout << "Bac cua cong nhan: " << Bac << endl;
		}
};

//Class Ky_SU:
class KY_SU : public CAN_BO{
	private:
		string NganhDaoTao;
	public:
		//Constructor:
		KY_SU(){
			NganhDaoTao = "Unknown";
		}
		
		KY_SU(string HoTen, string GioiTinh,string DiaChi, int NamSinh, string Nganh) : CAN_BO(HoTen,GioiTinh,DiaChi,NamSinh){
			NganhDaoTao = Nganh;
		}
		
		//Nhập:
		void Nhap(){
			CAN_BO::Nhap();
			cout << "Nhap nganh dao tao: "; getline(cin,NganhDaoTao);
		}
		
		//Xuất:
		void Xuat(){
			CAN_BO::Xuat();
			cout << "Nganh dao tao: " << NganhDaoTao << endl;
		}
};


int main(){
	int n;
	cout << "#Nhap so luong can bo: "; cin >> n; cin.ignore();
	vector <CAN_BO*> DanhSach;
	
	//Nhập n cán bộ:
	for (int i=0; i<n; i++){
		cout << "\n>> Nguoi thu " << i+1 << ":\n";
		cout << ">> Chon [1] de nhap cho CONG_NHAN hoac [2] de nhap cho KY_SU: ";
		int choice;
		cin >> choice; cin.ignore();
		if (choice == 1){
			CONG_NHAN *x = new CONG_NHAN;
			x->Nhap();
			DanhSach.push_back(x);
		}
		
		else if (choice == 2){
			KY_SU *x = new KY_SU;
			x->Nhap();
			DanhSach.push_back(x);
		}
		
		else{
			cout << "\n>> Khong hop le, vui long nhap lai!\n";
			i--;
		}
	} 
	
	// Danh sach CAN_BO vua nhap:
	cout << "\n\n\n# DANH SACH CAN BO:\n";
	for(int i=0; i<DanhSach.size(); i++){
		cout << "\n>> Nguoi thu " << i+1 << ":\n";
		DanhSach[i]->Xuat();
	}
	
	//Danh sach cac cong nhan co tuoi >=55:
	cout << "\n\n\n# CAC CONG NHAN LON HON 55 TUOI:\n";
	for(int i=0; i<DanhSach.size(); i++){
		CONG_NHAN *cn = dynamic_cast <CONG_NHAN*> (DanhSach[i]);
		if (cn && cn->getTuoi() >= 55){
			DanhSach[i]->Xuat();
			cout << endl;
		}
	}
	
	// Tim cong nhan theo ten:
	string Ten;
	cout << "\n\n\n# Nhap ten can tim: "; getline(cin,Ten);
	regex TenCanTim = regex(Ten,regex_constants::icase);
	int check = 0;
	for (int i=0; i<DanhSach.size();i++){
		if (regex_match(DanhSach[i]->getHoTen(), TenCanTim)){
			DanhSach[i]->Xuat();
			cout << endl;
			check = 1;
		}
	}
	if(check == 0) cout << "\n>> Khong co CAN_BO can tim!";
	return 0;
}