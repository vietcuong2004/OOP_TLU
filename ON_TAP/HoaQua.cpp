#include<bits/stdc++.h>
using namespace std;

class HoaQua{
	private:
		string MaHoaQua;
		string XuatXu;
		string TenHoaQua;
		double Gia;
		double ThanhTien;
	public:
		//Constructor:
		HoaQua(){
			MaHoaQua = XuatXu = TenHoaQua = "Unknown";
			Gia = ThanhTien = 0;
		}
		
		HoaQua(string MaHoaQua,string XuatXu, string TenHoaQua, double Gia, double ThanhTien){
			this->MaHoaQua = MaHoaQua;
			this->XuatXu = XuatXu;
			this->TenHoaQua = TenHoaQua;
			this->Gia = Gia;
			this->ThanhTien = ThanhTien;
		}
		
		//Ham truy cap:
		string getMaHoaQua(){
			return MaHoaQua;
		}
		string getTenHoaQua(){
			return TenHoaQua;
		}
		string getXuatXu(){
			return XuatXu;
		}
		double getGia(){
			return Gia;
		}
		
		//Ham sua doi:
		void setMaHoaQua(string Ma){
			MaHoaQua = Ma;
		}
		void setTenHoaQua(string Ten){
			TenHoaQua = Ten;
		}
		void setXuatXu(string XuatXu){
			this->XuatXu = XuatXu;
		}
		void setGia(double Gia){
			this->Gia = Gia;
		}
		void setThanhTien(double x){
			ThanhTien = x;
		}
		//Neu cho setThanhTien la ham thuan ao thi se bi loi khi nap chong toan tu
		//Nap chong toan tu khong cho phep nap chong cac bien phuong thuc thuan ao
		virtual double getThanhTien(){
			return 0;
		}
		
		//Nhap:
		virtual void Nhap(){
			cout << "Nhap Ma hoa qua: "; getline(cin,MaHoaQua);
			cout << "Nhap ten hoa qua: "; getline(cin,TenHoaQua);
			cout << "Nhap Xuat Xu: "; getline(cin,XuatXu);
			cout << "Nhap gia: "; cin >> Gia; cin.ignore();
		}
		//Xuat:
		virtual void Xuat(){
			cout << "Ma hoa qua: " << MaHoaQua << endl;
			cout << "Ten hoa qua: " << TenHoaQua << endl;
			cout << "Xuat xu: " << XuatXu << endl;
			cout << "Gia: " << fixed << setprecision(2) << Gia << endl;
		}
		
		// Nap chong toan tu +:
		friend double operator + (HoaQua p1, double p2){
			return p1.getThanhTien() + p2;
		}
		
		//Destructor
		~HoaQua(){};
};

class DuaHau : public HoaQua{
	private:
		double KhoiLuong;
	public:
		//Constructor
		DuaHau(){
			KhoiLuong = 0;
		}
		DuaHau(string MaHoaQua,string XuatXu, string TenHoaQua, double Gia, double ThanhTien, double KhoiLuong) : HoaQua(MaHoaQua,XuatXu,TenHoaQua,Gia,ThanhTien){
			this->KhoiLuong = KhoiLuong;
		}
		
		//Truy cap/ sua doi:
		double getKhoiLuong(){
			return KhoiLuong;
		}
		void setKhoiLuong(double KL){
			KhoiLuong = KL;
		}
		
		//Cap nhat gia tri thanh tien:
		double getThanhTien(){
			return KhoiLuong * HoaQua::getGia();	
		}
		
		//Nhap,xuat:
		void Nhap(){
			HoaQua::Nhap();
			cout << "Nhap khoi luong (kg): "; 
			cin >> KhoiLuong; cin.ignore();
			setThanhTien(getThanhTien());
		}
		
		void Xuat(){
			HoaQua::Xuat();
			cout << "Khoi luong: " << fixed << setprecision(2) << KhoiLuong << endl;
			cout << "Thanh Tien: " << fixed << setprecision(2) << getThanhTien() << endl; 
		}
		//Destructor;
		~DuaHau(){};
};

class QuaDua : public HoaQua{
	private:
		int SoLuong;
	public:
		//Constructor
		QuaDua(){
			SoLuong = 0;
		}
		QuaDua(string MaHoaQua,string XuatXu, string TenHoaQua, double Gia, double ThanhTien, int SoLuong) : HoaQua(MaHoaQua,XuatXu,TenHoaQua,Gia,ThanhTien){
			this->SoLuong = SoLuong;
		}
		
		//Truy cap/ sua doi:
		int getSoLuong(){
			return SoLuong;
		}
		void setSoLuong(int SL){
			SoLuong = SL;
		}
		
		//Cap nhat gia tri thanh tien:
		double getThanhTien(){
			return SoLuong * HoaQua::getGia();
		}
		
		//Nhap,xuat:
		void Nhap(){
			HoaQua::Nhap();
			cout << "Nhap so luong (qua): "; 
			cin >> SoLuong; cin.ignore();
			setThanhTien(getThanhTien());
		}
		void Xuat(){
			HoaQua::Xuat();
			cout << "So luong: "  << SoLuong << endl;
			cout << "Thanh Tien: " << fixed << setprecision(2) << getThanhTien() << endl; 
		}
		//Destructor;
		~QuaDua(){
		};
};

int main(){
	int n;
	double TongTien;
	vector<HoaQua*> DonHang;
	cout << "# Nhap so luong qua: "; cin >> n; cin.ignore();
	for (int i=0; i<n; i++){
		cout <<"\n>> Qua thu " << i+1 << ":\n";
		cout << ">> Chon [1] de nhap DUAHAU hoac [2] de nhap QUADUA: ";
		int choice;
		cin >> choice; cin.ignore();
		if(choice == 1){
			DuaHau* x = new DuaHau;
			x->Nhap();
			DonHang.push_back(x);
			TongTien = x->getThanhTien()+TongTien;
		}
		else if(choice == 2){
			QuaDua* x = new QuaDua;
			x->Nhap();
			DonHang.push_back(x);
			TongTien = x->getThanhTien()+TongTien;
		}
		else{
			cout << ">> Nhap lai!\n";
			i--;
		}		
	}
	
	cout << "\n\n#Danh sach qua vua nhap:";
	for(int i=0;i<DonHang.size();i++){
		cout <<"\n>> Qua thu " << i+1 << ":\n";
		DonHang[i]->Xuat();
	}
	
	cout << "\n\n# Tong so tien = " << fixed << setprecision(2) << TongTien;
	return 0;
}
