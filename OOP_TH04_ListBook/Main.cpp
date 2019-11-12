#include"NXB.h"
#include"TacGia.h"
//int main()
//{
//	DS_HoaDon ds;
//	HoaDon s;
//	ListBook l;
//	//Sach a;
//	//cin >> a;
//	l.taoDanhSachSach();
//	l.xuatDanhSachSach();
//	/*l.capNhatGiaSach();
//	l.xuatDanhSachSach();
//	l.xoaSach();
//	l.xuatDanhSachSach();
//	if(s.taoHoaDon(l))
//	s.xuatHoaDon();*/
//	do
//	{
//		int lenh;
//		ds.themHoaDon(l);
//		cout << "Tiep tuc them hoa don: Tiep tuc(1) - Ngung nhap(0) "; cin >> lenh;
//		if (lenh == 0) break;
//	} while (true);
//	cout << endl;
//	cout << "DANH SACH HOA DON" << endl;
//	ds.xuatDSHoaDon();
//	return EXIT_SUCCESS;
//}

int main()
{
	//khoi tao list sach
	//ListBook l; 
	//l.loadfromFile();
	//l.xuatDanhSachSach();
	// Lam viec voi Guest
	//Guest g;
	//g.timSach(l);

	//
	////Khoi tao User
	//string t = "ABC";
	//User user; user.setTenUser(t); t = "123"; user.setPassUser(t);
	//int tuoi = 19; user.setTuoiUser(tuoi);
	//int lenh;
	//cout << "Ban co muon tiep tuc mua sach" << endl;
	//cout << "Tiep tuc(1) - Ngung (0) "; cin >> lenh;
	//if (lenh == 0)
	//{
	//	cout << "Cam on quy khach da su dung dich vu" << endl;
	//	return 0;
	//}
	//string id,mk;
	////vòng lập đăng nhập 
	//do
	//{
	//	cout << "VUI LONG DANG NHAP TRUOC KHI MUA";
	//	cout << "Hay nhap ID cua ban: "; cin >> id;
	//	cout << "Nhap vao mat khau cua ban: "; cin >> mk;

	//	//nếu đăng nhập thành công thì thoát khỏi vòng lập
	//	if (id == user.getTenUser() && mk == user.getPassUser())
	//	{
	//		cout << "Dang nhap thanh cong." << endl;
	//		break;
	//	}

	//	//ngược lịa in ra lỗi đăng nhập
	//	cout << "Dang nhap loi." << endl;
	//	//cho người dùng chọn option đăng nhập lại hoặc thoát.
	//	cout << "Tiep tuc(1) - Ngung (0) "; cin >> lenh;
	//	if (lenh == 0)
	//	{
	//		cout << "Cam on quy khach da su dung dich vu" << endl;
	//		return 0;
	//	}
	//} while (true);
	//
	//DS_HoaDon User_DSHD;
	//User_DSHD=user.muaSach(l);

	//User_DSHD.xuatDSHoaDon();

	//cout << "Ban co muon sua hoa don cua minh" << endl;
	//cout << "Tiep tuc(1) - Ngung nhap(0) "; cin >> lenh;
	//if (lenh == 0)
	//{
	//	cout << "Cam on quy khach da su dung dich vu" << endl;
	//	return 0;
	//}

	//

	//do
	//{
	//	int lenh;
	//
	//	user.upDateHoaDon(User_DSHD);
	//	cout << "Tiep tuc chinh sua hoa don: Tiep tuc(1) - Ngung nhap(0) "; cin >> lenh;
	//	if (lenh == 0) break;
	//} while (true);

	//User_DSHD.xuatDSHoaDon();
	//
	//User_DSHD.xoaHoaDon();

	//User_DSHD.xuatDSHoaDon();
	//cout<<"Tong tien ma ban da mua la: "<<User_DSHD.tongTienHoaDon();

	ListBook l;
	l.loadfromFile();
	l.xuatDanhSachSach();
	
	/*NXB nxb1;
	string tenNXB = "KH&KT";
	string pass = "123";
	nxb1.setPassUser(pass);
	nxb1.setTenUser(tenNXB);
	do
	{
		string mk;
		cout << "Nhap mat khau: "; cin >> mk;
		if (mk == nxb1.getPassUser()) {
			cout << "dang nhap thanh cong" << endl; break;
		}
		else { cout << "Sai Mat khau. Can dang nhap lai. " << endl; }
	} while (true);
	nxb1.getData(l);
	nxb1.printNXBListBook();
	nxb1.funRunUpdatePrice();
	nxb1.printNXBListBook();
	l.xuatDanhSachSach();
	nxb1.addBook();
	nxb1.printNXBListBook();
	nxb1.funRundeleBook();
	nxb1.printNXBListBook();
	l.xuatDanhSachSach();*/
	
	TacGia tg;
	tg.setPassUser("123");
	tg.setTenUser("TranDanThu");
	do
	{
		string mk;
		cout << "Nhap mat khau: "; cin >> mk;
		if (mk == tg.getPassUser()) {
			cout << "dang nhap thanh cong" << endl; break;
		}
		else { cout << "Sai Mat khau. Can dang nhap lai. " << endl; }
	} while (true);

	tg.getData(l);
	tg.printTacGiaListBook();

	tg.funRunUpdateNameBook();
	tg.printTacGiaListBook();
	l.xuatDanhSachSach();

	tg.funRundeleBook();
	tg.printTacGiaListBook();
	l.xuatDanhSachSach(); 

}