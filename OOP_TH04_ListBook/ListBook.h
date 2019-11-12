#pragma once
#ifndef _LISTBOOK_H_
#define _LISTBOOK_H_
#include"Sach.h"
#include<fstream>
#include<vector>
class ListBook
{
private:
	vector <Sach> lb;
public:
	void taoDanhSachSach();
	void xuatDanhSachSach();
	int timSachTheoTen(string&);
	int timSachTheoTacGia(string&);
	void capNhatGiaSach();
	void xoaSach();
	Sach* timSach_Ten(string& name);
	Sach** timSach(string searchstring, int type);
	int demSach(string nxb,int type);
	//dem so luong sach thuoc loai type duoc truyen vao

	int timSachTheoMaSach(int);
	int loadfromFile();
};
#endif // !_LISTBOOK_H_



