// klipert_5_10_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

void menu(tree t) {
	while (true) {
		cout << endl << "====== Меню работы с деревом поиска ======" << endl << " [1] Добавить элемент в дерево" << endl << " [2] Удалить элемент из дерева" << endl;
		switch (_getch()) {
		case '1': {	t = *setElementInfo(t, 1);	break; }
		case '2': { t = *askDeleteElement(t); break; }
		default: { exit(0); }
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	tree t;
	int n = askTreeSize();
	t = *setElementInfo(t, n);
	menu(t);
	system("pause");
    return 0;
}