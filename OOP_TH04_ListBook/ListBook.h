﻿#ifndef _LISTBOOK_H_
#define _LISTBOOK_H_
#include"Sach.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class ListBook
{
private:
	vector <Sach> lb;
public:
	void taoDanhSachSach();
	//xuất tất cả các sách có trong danh sách
	void xuatDanhSachSach();
	
	//xuất danh sách các sách đã kiểm qua thuộc tính ẩn do Tác Giả và NXB
	void xuatdanhsach_KhongAn();

	int timSachTheoTen(string&);
	int timSachTheoTacGia(string&);
	void capNhatGiaSach();
	void xoaSach();
	Sach* timSach_Ten(string name);
	Sach** timSach(string searchstring, int type);

	//dem so luong sach thuoc loai type duoc truyen vao
	int demSach(string nxb,int type);
	
	//tính tổng số sách đã bán
	int soSachDaban();

	//Sách được mua nhiều nhất
	void bestSellerBook(vector <Sach>& ds);

	int checkExistBook(Sach& a);
	int timSachTheoMaSach(int);
	int loadfromFile();


	//ghi lại các thao tác --> danh sách cuối cùng vào file.
	void writeDownToFile();
	void themSach();

};
#endif // !_LISTBOOK_H_



