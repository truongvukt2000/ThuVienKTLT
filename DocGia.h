#pragma once
#include "DangNhap.h"

struct DocGia
{
	char* hoten = new char[50];
	Date ngaysinh;
	char* CMND = new char[10];
	char* SDT = new char[10];
};

struct ListDG
{
	DocGia* list;
	int num;
};

void getListDG(ifstream filein, ListDG& list);
void writeListDG(ofstream fileout, ListDG list);

void xuatListDG(ListDG& list);
void addDG(ListDG& list);
void suathongtinDG(DocGia& dg, ListDG& list);
void xoathongtinDG(DocGia dg, ListDG& list);
DocGia findCMND(char* CMND, ListDG list);
DocGia findhoten(char* hoten, ListDG list);