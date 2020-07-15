#pragma once
#include <iostream>
#include <fstream>
using namespace std;

struct Date
{
	int ngay, thang, nam;
};
struct InforUser
{
	char* hoten = new char[100];
	Date ngaysinh;
	char* CMND = new char[10];
	char* SDT = new char[10];
};
struct User
{
	char* username = new char[50];
	char* password = new char[50];
	char* phanquyen = new char[10];
	InforUser inf;
};
struct ListUser
{
	User* list;
	User* listmoi;
	int num;
};

void getListUser(ifstream filein, ListUser& list);
void writeListUser(ofstream fileout, ListUser& list);

int findUser(User us, ListUser l);
bool dangnhap(User& us, ListUser l);
void thaydoiMK(User& us, ListUser& l);
void capnhathongtin(User& us, ListUser& l);
Date nhapngaysinh();
User taoUser(char* phanquyen);
void taonguoidung(User us, ListUser& l);
void phanloai(User us, ListUser& l);

