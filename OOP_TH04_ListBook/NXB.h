#ifndef _NXB_H_
#define _NXB_H_
#include<iostream>
#include<vector>
#include"User.h"
#include"ListBook.h"
using namespace std;

class NXB:public User
{
private:
	vector <Sach*> dsSach;
public:
	NXB();
	~NXB();
	void addBook();
	//thêm sách mới vào danh sách của NXB

	void getData(ListBook& l);
	//lấy sách trong kho sách (list sách) bỏ vào danh sách của NXB

	void printNXBListBook();
	//in sách của NXB

	Sach* findSachfromNXBList(string tensach);
	//timf và trả về con trỏ trỏ đến Sách có tên đưuọc truyền vào trong số sach của NXB

	int updatePrice(string tenSach,float gia);
	//cập nhật lại giá sách

	void funRunUpdatePrice();
	//hàm để thực thi việc cập nhật giá sách

	int deleBook(string tensach);
	//xóa sách có tên được nhập ra khỏi danh sách của NXB --> nếu sách đó có tên trong kho sách thì tên NXB rỗng

	void funRundeleBook();
	//hàm run cho hàm deleBook...
};

#endif 