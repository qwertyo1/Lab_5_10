#include "stdafx.h"

void menu(tree t) {
	while (true) {
		cout << endl << "====== ���� ������ � ������� ������ ======" << endl << " [1] �������� ������� � ������" << endl << " [2] ������� ������� �� ������" << endl;
		switch (_getch()) {
		case '1': {	t = *setElementInfo(t);	break; }
		case '2': { t = *askDeleteElement(t); break; }
		default: { exit(0); }
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	tree t;
	menu(t);
	system("pause");
    return 0;
}