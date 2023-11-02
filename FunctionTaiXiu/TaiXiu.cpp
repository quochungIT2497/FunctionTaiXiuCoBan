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
	//evValue3,
	evEnd
};

//Tạo đường dẫn đến các giá trị của chuỗi
static map<string, TaiXiuValue> s_mapTaiXiuValues;

//Tạo nhận giá trị người dùng nhập
static char usInput[_MAX_PATH];
//static int usInPut[_MAX_PATH];

//Tạo phần kích hoạt
static void KichHoat();

void KichHoat()
{
	s_mapTaiXiuValues["Tai"] = evTai;
	s_mapTaiXiuValues["Xiu"] = evXiu;
	s_mapTaiXiuValues["Thoat"] = evEnd;

	cout << "Ban co " << s_mapTaiXiuValues.size() <<" lua chon" << endl;
}

int main(int argc, char* argv[]) //argc cho biết tham số đã nhập kể cả tên chương trình
// argv[] các pointer trỏ đến các chuỗi là tham số đi theo sau tên chương trình
// tương đương int main()
{
	KichHoat();
	while (true)
	{
		//Nhận tham số người dùng nhập
		cout << "Lua chon: Tai/Xiu/Thoat" << endl;
		cout << "Nhap vao lua chon cua ban: "<<endl;
		//cout.flush();//tương đương endl, dùng để scan và xuất output ngay lập tức mà ko lưu trữ lại vùng nhớ đệm
		cin.getline(usInput,_MAX_PATH);//_Max_Path = độ dài lớn nhất của số chữ nhập vào = 256, nếu nhập hơn thì không được
		//srand(time(0));
		//int random = rand() %16 + 1;// tao random tu so 1->16
		random_device rd;//random cach 2
		mt19937 rng(rd());
		uniform_int_distribution<int> uni(1, 16);
		auto random = uni(rng);//random cach 2
		cout << "Nha cai da ra so "<< random << "\n";
		switch (s_mapTaiXiuValues[usInput])
		{
			case evTai:
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
				//int random = rand() % 16 + 1;
				if (random <= 8)
				{
					cout << "Ban da thang" << endl;
				}
				else if ( random > 8)
				{
					cout << "Ban da thua" << endl;
				}
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