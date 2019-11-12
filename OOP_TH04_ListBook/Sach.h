
#ifndef _SACH_H_
#define _SACH_H_
#include<iostream>
#include<string>
using namespace std;
class Sach
{
private:
	int masach;
	string tensach;
	string tacGia;
	string NXB;
	float gia;
public:
	Sach();
	Sach(string, int, float);
	Sach(const Sach& a);
	void setGia(float);
	void setMaSach(int);
	void setTenSach(string);
	void setTacGia(string);
	void setNXB(string);

	int getMaSach();
	string getTenSach();
	float getGiaSach();
	string getTacGia();
	string getNXB();

	void Nhap();
	void Xuat();
	//Sach& operator=(Sach& a);
	friend istream& operator>>(istream& IDev, Sach& a);
	friend ostream& operator<<(ostream& ODev, Sach& a);

	void filetoSach(char *a);
	~Sach();
};
#endif

