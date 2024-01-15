#include<bits/stdc++.h>
using namespace std;

// lớp cơ sở:
class Vehicles{
	private:
		double NormalSpeed;//Tốc độ tiêu chuẩn
	public:
		Vehicles(){
			NormalSpeed = 0;
		}
		
		Vehicles(double Speed){
			this->NormalSpeed = Speed;
		};
		
		double getNormalSpeed(){
			return this->NormalSpeed;
		}
		
		virtual const double maxSpeed() = 0;// hàm thuần ảo
		
		virtual void input(){
			cout << "Nhap toc do tieu chuan: ";
			cin >> NormalSpeed;
			cin.ignore(1);
		}
		
		virtual void output(){
			cout << ">> Toc do tieu chuan: " << NormalSpeed << endl;
		}
};


// Lớp dẫn xuất ferrari
class Ferrari : public Vehicles{
	private:
		string Color;
		double Speed_Constant; //Hệ số tốc độ
	public:
		Ferrari(){};
		Ferrari(double NormalSpeed, string Color, double Speed_Constant) : Vehicles(NormalSpeed){
			this->Color = Color;
			this->Speed_Constant = Speed_Constant;
		}
		
		const double maxSpeed(){
			return this->Speed_Constant * getNormalSpeed();
		}
		
		void input(){
			Vehicles::input(); // Gọi hàm nhập của lớp cơ sở để nhập tốc độ tiêu chuẩn
			cout << "Nhap mau sac: ";
			getline(cin,Color);
			cout << "Nhap he so toc do: ";
			cin >> Speed_Constant;
			cin.ignore(1);
		}
		
		void output(){
			Vehicles::output();
			cout << ">> Mau sac xe: " << Color << endl;
			cout << ">> He so toc do cua xe: " << Speed_Constant << endl;	
			cout << ">> Toc do toi da cua xe: " << maxSpeed() << endl;
		}
		
		friend bool operator > (Ferrari T1,Ferrari T2){
			return T1.maxSpeed() > T2.maxSpeed();
		}
};

int main(){
	int n;
	cout << "Nhap so luong xe Ferrari: "; cin >> n;
	vector<Ferrari> Fer(n);

	for(int i=0; i<n; i++){
		cout << "+ Xe thu " << i+1 << ":\n";
		Fer[i].input();
		cout << endl;
	}
	
	cout << "Danh sach xe vua nhap:\n";
	for (int i=0; i<n; i++){
		cout << " + Xe thu " << i+1 << ":\n";
		Fer[i].output();
		cout << endl;
	}
	
	Ferrari The_Fastest = Fer[0];
	for (int i = 1; i<n; i++){
		if (Fer[i] > The_Fastest)
			The_Fastest = Fer[i];
	}
	
	cout << "Xe co toc do toi da lon nhat:\n";
	The_Fastest.output();
	return 0;
}