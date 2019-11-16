#ifndef _TACGIA_H_
#define _TACGIA_H_
#include"Account.h"
class TacGia:public Account
{
private:
	vector<Sach*> dsSach;
public:
	TacGia();
	TacGia(string ten, string pass);
	~TacGia() {};
	void addBook(Sach* a);
	//thêm sách mới vào danh sách của Tác Giả

	void getData(ListBook& l);
	//lấy sách trong kho sách (list sách) bỏ vào danh sách của Tác Giả

	void printTacGiaListBook();
	//in sách của Tác Giả

	
	Sach* findSachfromTacGiaList(string tensach);
	//tìm và trả về con trỏ trỏ đến sách trong ListBook có tên được truyền vào trong số Sách của Tác Giả

	int updateTenSach(string tensach);
	//cập nhật lại tên sách

	void funRunUpdateNameBook();
	//hàm run cho hàm int updateTen(string tensach, string tensachmoi);

	int deleBook(string tensach);
	//xóa sách có tên được nhập ra khỏi danh sách của Tác Giả --> nếu sách đó có tên trong kho sách thì tên NXB rỗng

	void funRundeleBook();
	//hàm run cho hàm deleBook..

	int printMenu();

	virtual void funRunMenu(ListBook& lb);
};



#endif // !_TACGIA_H_



