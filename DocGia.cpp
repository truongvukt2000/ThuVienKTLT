#include "DocGia.h"

void xuatListDG(ListDG& list)
{
	for (int i = 0; i < list.num; i++) {
		cout << "1." << endl;
		cout << "Ho ten: " << list.list[i].hoten << endl;
		cout << "Ngay sinh: " << list.list[i].ngaysinh.ngay << "/" << list.list[i].ngaysinh.thang << "/" << list.list[i].ngaysinh.nam << endl;
		cout << "CMND: " << list.list[i].CMND << endl;
		cout << "SDT: " << list.list[i].SDT << endl;
	}
}

void addDG(ListDG& list)
{
	DocGia temp;
	cout << "Ho ten:";
	fflush(stdin);
	gets_s(temp.hoten, 50);
	cout << "Ngay sinh: ";
	temp.ngaysinh = nhapngaysinh();
	cout << "CMND: ";
	cin >> temp.CMND;
	cout << "SDT: ";
	cin >> temp.SDT;
}

void suathongtinDG(DocGia& dg, ListDG& list)
{
	for (int i = 0; i < list.num; i++) {
		if (dg.CMND == list.list[i].CMND) {
			int temp;
			do {
				cout << "1. Ho ten. " << endl;
				cout << "2. Ngay sinh." << endl;
				cout << "3. CMND." << endl;
				cout << "4. SDT." << endl;
				cout << " 0. thoat." << endl;
				cout << "You choose: ";
				cin >> temp;
				cin >> temp;
				if (temp == 0) {
					break;
				}
				else if (temp == 1) {
					char* hoten2 = new char[50];
					cout << "Nhap ho ten: ";
					gets_s(hoten2, 50);
					dg.hoten = hoten2;
					list.list[i].hoten = hoten2;
					break;
				}
				else if (temp == 2) {
					Date ngaysinh2 = nhapngaysinh();
					dg.ngaysinh = ngaysinh2;
					list.list[i].ngaysinh = ngaysinh2;
					break;
				}
				else if (temp == 3) {
					char* CMND2 = new char[10];
					cout << "Nhap CMND: ";
					cin >> CMND2;
					dg.CMND = CMND2;
					list.list[i].CMND = CMND2;
					break;
				}
				else if (temp == 4)
				{
					char* SDT2 = new char[10];
					cout << "Nhap SDT: ";
					cin >> SDT2;
					dg.SDT = SDT2;
					list.list[i].SDT = SDT2;
					break;
				}
				else {
					cout << "Nhap khong dung. Vui long nhap lai!" << endl;
					system("cls");
				}
			} while (temp < 0 || temp >4);
		}
	}
}

void xoathongtinDG(DocGia dg, ListDG& list)
{
	for (int i = 0; i < list.num; i++) {
		if (dg.CMND == list.list[i].CMND) {
			for (int j = i; j < list.num - 1; j++) {
				list.list[j] = list.list[j + 1];
			}
			list.num--;
		}
	}
}

DocGia findCMND(char* CMND, ListDG list)
{
	DocGia temp;
	temp.hoten = temp.CMND = temp.SDT = NULL;
	temp.ngaysinh.ngay = temp.ngaysinh.thang = temp.ngaysinh.nam = 0;
	for (int i = 0; i < list.num; i++) {
		if (list.list[i].CMND == CMND) {
			temp = list.list[i];
			return temp;
		}
	}
	return temp;
}

DocGia findhoten(char* hoten, ListDG list)
{
	DocGia temp;
	temp.hoten = temp.CMND = temp.SDT = NULL;
	temp.ngaysinh.ngay = temp.ngaysinh.thang = temp.ngaysinh.nam = 0;
	for (int i = 0; i < list.num; i++) {
		if (list.list[i].hoten == hoten) {
			temp = list.list[i];
			return temp;
		}
	}
	return temp;
}
