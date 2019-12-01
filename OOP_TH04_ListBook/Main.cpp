#include"Header.h"

int main()
{
	ListBook l;
	l.loadfromFile();
	l.xuatDanhSachSach();
	
	funRun(l);
	l.writeDownToFile();
}