#include <bits/stdc++.h>
using namespace std;
struct Sinhvien{
	string name;
	string lop;
	double diem;
};
void change(int *n){
	*n = 1000;
}

int main(){
	// Tổng ôn con trỏ và cấp phát động
	Sinhvien s; // cấp phát tĩnh
	Sinhvien *ptr = new SinhVien(); // cấp phát động
	s.name = "Phuc";
	s.lop = "An Toan Thong Tin";
	s.diem = 3.6;
	Sinhvien *ptr = &s;
	int *ptr = &a; // giá trị con trỏ chính là địa chỉ của biến mà nó quản lí
	cout << ptr->name << endl;
	cout << ptr->lop << endl;
	cout << ptr->diem << endl;
	delete ptr; // giải phóng bộ nhớ đã chiếm chỗ ở trên
   
	return 0;
}