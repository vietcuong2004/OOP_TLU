#include<iostream>
using namespace std;

class Tong{
	private:
		int num1,num2;
	public:
		//Ham khoi tao:
		Tong(int a, int b){
			num1 = a;
			num2 = b;
		}
		int TinhTong(){
			return num1 + num2;
		}
};

int main(){
	int a,b;
	cin >> a >> b;
	Tong Tong(a,b);
	cout << Tong.TinhTong();
	return 0;
}
