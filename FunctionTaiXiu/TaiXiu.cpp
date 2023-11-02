#include <map>
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

//Tạo Định Nghĩa Cho Mỗi Chuỗi = static và cố định định nghĩa = enum
static enum TaiXiuValue
{
	evNotDefined,
	evTai,
	evXiu,
	evDoanSo,
	evEnd
};

//Tạo đường dẫn đến các giá trị của chuỗi
static map<string, TaiXiuValue> s_mapTaiXiuValues;

//Tạo nhận giá trị người dùng nhập
static char usInput[_MAX_PATH];

//Tạo phần kích hoạt
static void KichHoat();

void KichHoat()
{
	s_mapTaiXiuValues["Tai"] = evTai;
	s_mapTaiXiuValues["Xiu"] = evXiu;
	s_mapTaiXiuValues["Doan"] = evDoanSo,
	s_mapTaiXiuValues["Thoat"] = evEnd;

	cout << "Ban co " << s_mapTaiXiuValues.size() <<" lua chon" << endl;
}

int nhapso()
{
	cout << "Nhap so ban doan tu 1 den 16: \n";
	return 0;
}

int main(int argc, char* argv[]) //argc cho biết tham số đã nhập kể cả tên chương trình
// argv[] các pointer trỏ đến các chuỗi là tham số đi theo sau tên chương trình
// tương đương int main()
{
	//int(*fncptr)() = nhapso; //pointer dùng cho hàm
	while (true)
	{
		//Nhận tham số người dùng nhập
		cout << "-----------"<<endl;
		KichHoat();
		cout << "Lua chon: Tai/Xiu/Doan/Thoat" << endl;
		cout << "Nhap vao lua chon cua ban: "<<endl;
		cout.flush();//tương đương endl, dùng để scan và xuất output ngay lập tức mà ko lưu trữ lại vùng nhớ đệm
		cin.getline(usInput,_MAX_PATH);//_Max_Path = độ dài lớn nhất của số chữ nhập vào = 256, nếu nhập hơn thì không được
		srand(time(0));// tao seed random
		int random = rand() %16 + 1;//random tu 1->16
		//random_device rd;//random cach 2
		//mt19937 rng(rd());
		//uniform_int_distribution<int> uni(1, 16);
		//auto random = uni(rng);//random cach 2
		switch (s_mapTaiXiuValues[usInput])
		{
			case evTai:
				cout << "Nha cai da ra so " << random << "\n";
				if (random <= 8)
				{
					cout << "Ban da thua" << endl;
				}
				else if(random > 8)
				{
					cout << "Ban da thang" << endl;
				}
				break;
			case evXiu:
				cout << "Nha cai da ra so " << random << "\n";
				if (random <= 8)
				{
					cout << "Ban da thang" << endl;
				}
				else if ( random > 8)
				{
					cout << "Ban da thua" << endl;
				}
				break;
			case evDoanSo:
				int DoanSo;
				//fncptr();
				nhapso();
				cin >> DoanSo;
				if (DoanSo < 17 && DoanSo > 0)
				{
					cout << "Nha cai da ra so " << random << "\n";
					if (DoanSo == random)
						cout << "Ban da thang" << endl;
					else if (DoanSo != random)
						cout << "Ban da thua" << endl;
				}
				else
				{
					cout << " Yeu cau nhap lai " << endl;
				}
				cin.ignore();//Bỏ qua các số đã nhập để thực hiện lại chương trình không bị scan trúng khi lặp = while và cho ra case default
				break;
			case evEnd:
				cout << "Ban da chon thoat chuong trinh" << endl;
				return (0);
			default:
				cout << " Lua Chon " << usInput << " ban nhap khong phu hop" << endl;
				break;
		}
	}
	return 0;
}