#include "DangNhap.h"

int findUser(User us, ListUser l)
{
	for (int i = 0; i < l.num; i++) {
		if (us.username == l.list[i].username && us.password == l.list[i].password) {
			return i;
		}
	}
	return -1;
}

bool dangnhap(User& us, ListUser l)
{
	int choose;
	do {
		system("cls");
		cout << "1. Dang nhap. " << endl;
		cout << "2. Thoat." << endl;
		cout << "You choose: ";
		cin >> choose;
		if (choose == 2) break;
		else if (choose == 1) {
			system("cls");
			cout << "username: ";
			cin >> us.username;
			cout << "password: ";
			cin >> us.password;
			for (int i = 0; i < l.num; i++) {
				if (us.username == l.list[i].username && us.password == l.list[i].password) {
					return 1;
				}
			}
			cout << "Tai khoan hoac mat khau khong chinh xac." << endl;
			system("pause");
		}
	} while (1);
	return 0;
}

void thaydoiMK(User& us, ListUser& l)
{
	char* password = new char[50];
	char* newpassword = new char[50];
	char* newpassword2 = new char[50];
	do {
		cout << "Nhap mat khau hien tai:";
		gets_s(password, 50);
		cout << "Nhap mat khau moi: ";
		gets_s(newpassword, 50);
		cout << "Nhap lai mat khau moi: ";
		gets_s(newpassword2, 50);
		if (password != us.password) {
			cout << "Mat khau khong dung! Vui long nhap lai!" << endl;
		}
		else if (newpassword != newpassword2) {
			cout << "2 mat khau khong giong nhau! Vui long nhap lai!" << endl;
		}
	} while (password != us.password || newpassword != newpassword2);
	int i = findUser(us, l);
	us.password = newpassword;
	l.list[i].password = newpassword;
}

void capnhathongtin(User& us, ListUser& l) //change 1 inf 1 times
{
	cout << "Ho ten: " << us.inf.hoten << endl;
	cout << "Ngay sinh: " << us.inf.ngaysinh.ngay << "/" << us.inf.ngaysinh.thang << "/" << us.inf.ngaysinh.nam << endl;
	cout << "CMND: " << us.inf.CMND << endl;
	cout << "SDT: " << us.inf.SDT << endl;
	int temp;
	int i = findUser(us, l);
	do {
		cout << "Nhap thong tin muon thay doi: " << endl;
		cout << "1. Ho ten" << endl;
		cout << "2. Ngay sinh" << endl;
		cout << "3. CMND" << endl;
		cout << "4. SDT" << endl;
		cout << "0. thoat" << endl;
		cout << "Choose number: ";
		cin >> temp;
		if (temp == 0) {
			break;
		}
		else if (temp == 1) {
			char* hoten2 = new char[50];
			cout << "Nhap ho ten: ";
			gets_s(hoten2, 50);
			us.inf.hoten = hoten2;
			l.list[i].inf.hoten = hoten2;
			break;
		}
		else if (temp == 2) {
			Date ngaysinh2;
			cout << "Nhap ngay sinh: ";
			cout << "Ngay: ";
			cin >> ngaysinh2.ngay;
			cout << "Thang: ";
			cin >> ngaysinh2.thang;
			cout << "Nam: ";
			cin >> ngaysinh2.nam;
			us.inf.ngaysinh = ngaysinh2;
			l.list[i].inf.ngaysinh = ngaysinh2;
			break;
		}
		else if (temp == 3) {
			char* CMND2 = new char[10];
			cout << "Nhap CMND: ";
			cin >> CMND2;
			us.inf.CMND = CMND2;
			l.list[i].inf.CMND = CMND2;
			break;
		}
		else if (temp == 4)
		{
			char* SDT2 = new char[10];
			cout << "Nhap SDT: ";
			cin >> SDT2;
			us.inf.SDT = SDT2;
			l.list[i].inf.SDT = SDT2;
			break;
		}
		else {
			cout << "Nhap khong dung. Vui long nhap lai!" << endl;
			system("cls");
		}
	} while (temp < 0 || temp > 4);
}

Date nhapngaysinh()
{
	Date temp;
	cout << "Nhap ngay: ";
	cin >> temp.ngay;
	cout << "Nhap thang: ";
	cin >> temp.thang;
	cout << "Nhap nam: ";
	cin >> temp.nam;
	return temp;
}

User taoUser(char* phanquyen)
{
	User nv;
	cout << "username: ";
	cin >> nv.username;
	cout << "password: ";
	cin >> nv.password;
	nv.phanquyen = phanquyen;
	cout << "Ho ten: ";
	gets_s(nv.inf.hoten, 50);
	nv.inf.ngaysinh = nhapngaysinh();
	cout << "CMND: ";
	cin >> nv.inf.CMND;
	cout << "SDT: ";
	cin >> nv.inf.SDT;
	return nv;
}

void taonguoidung(User us, ListUser& l)
{
	if (us.phanquyen == "Nhan vien") {
		cout << "Ban khong co quyen tao nguoi dung." << endl;
	}
	else if (us.phanquyen == "Quan ly") {
		cout << "Tao nhan vien: ";
		char a[10] = "Nhan vien";
		User us2 = taoUser(a);
	}
	else if (us.phanquyen == "admin") {
		int temp;
		cout << "1. Tao nhan vien." << endl;
		cout << "2. Tao Quan ly." << endl;
		cout << "You choose: ";
		cin >> temp;
		if (temp == 1) {
			char a[10] = "Nhan vien";
			User us2 = taoUser(a);
		}
		else if (temp == 2) {
			char a[10] = "Quan ly";
			User us2 = taoUser(a);
		}
		else {
			cout << "Nhap sai!" << endl;
		}
	}

}

void phanloai(User us, ListUser& l)
{
	if (us.phanquyen == "Nhan vien") {
		cout << "Ban khong co quyen phan loai." << endl;
	}
	else if (us.phanquyen == "Quan ly") {
		cout << "Ban khong co quyen phan loai." << endl;
	}
	else if (us.phanquyen == "admin") {
		User tk;
		cout << "Nhap username and password cua tai khoan phan loai: ";
		cout << "username: ";
		cin >> tk.username;
		cout << "password: ";
		cin >> tk.password;
		int i = findUser(tk, l);
		if (i == -1) {
			cout << "tai khoan khong ton tai." << endl;
		}
		else {
			cout << "Nhap chuc vu: ";
			gets_s(l.list[i].phanquyen, 10);
		}
	}
}

void aftersignup(char* phanquyen)
{
	if (phanquyen == "Nhan vien") {

	}
}
