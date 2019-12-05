#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#ifndef _NXB_H_
#define _NXB_H_
#include"UuDai.h"
#include"Account.h"

class NXB:public Account
{
private:
	vector <Sach*> dsSach;
public:
	NXB();
	NXB(string ten, string pass) {
		mTen = ten; mPass = pass;
	}
	~NXB();
	void addBook(Sach* a);
	//thêm sách mới vào danh sách của NXB

	void getData(ListBook& l);
	//lấy sách trong kho sách (list sách) bỏ vào danh sách của NXB

	void printNXBListBook();
	//in sách của NXB

	Sach* findSachfromNXBList(string tensach);
	//timf và trả về con trỏ trỏ đến Sách có tên đưuọc truyền vào trong số sach của NXB

	int updatePrice(string tenSach);
	//cập nhật lại giá sách

	void funRunUpdatePrice();
	//hàm để thực thi việc cập nhật giá sách

	int deleBook(string tensach);
	//xóa sách có tên được nhập ra khỏi danh sách của NXB --> nếu sách đó có tên trong kho sách thì tên NXB rỗng

	void funRundeleBook();
	//hàm run cho hàm deleBook...

	//in menu cho NXB
	int printMenu();

	virtual void funRunMenu(ListBook& lb, DS_UuDai& dsud);
	virtual string nameclass();
	virtual void sendMessage();
	
	virtual int checkExistAccount(string name_account);
};

#endif 