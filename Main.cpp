#include "DocGia.h"

int main() {
	
	ListUser ls;
	ls.list = NULL;
	ls.listmoi = NULL;
	ls.num = 0;
	User us;
	if (dangnhap(us, ls)) {
		cout << "1. Thay doi mat khau." << endl;
		cout << "2. Cap nhat thong tin ca nhan." << endl;
		cout << "3. Tao nguoi dung." << endl;
		cout << "4. Phan quyen nguoi dung." << endl;
	}

	return 0;
}