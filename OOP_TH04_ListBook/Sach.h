﻿
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
	//thêm thuộc tính ẩn
	bool anTacGia, anNXB;
	int sl_Daban;
public:
	Sach();
	Sach(string, int, float);
	Sach(const Sach& a);
	void setGia(float);
	void setMaSach(int);
	void setTenSach(string);
	void setTacGia(string);
	void setNXB(string);
	void setAnTacGia(bool a);
	void setAnNXB(bool a);
	void setSLDaban(int sl);

	int getMaSach();
	string getTenSach();
	float getGiaSach();
	string getTacGia();
	string getNXB();
	bool getAnTacGia();
	bool getAnNXB();
	int getSLDaban();

	Sach* getBook();
	void Nhap();
	void Xuat();
	//Sach& operator=(Sach& a);
	friend istream& operator>>(istream& IDev, Sach& a);
	friend ostream& operator<<(ostream& ODev, Sach& a);
	Sach& operator=(Sach a);
	void filetoSach(char *a);
	void sachToFile(fstream& f);
	~Sach();
};
#endif

