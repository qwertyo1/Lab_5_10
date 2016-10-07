#include "stdafx.h"

tree *setElementInfo(tree t) {
	cout << "Значение нового элемента = ";
	int info;
	cin >> info;
	t << info;
	t.inorder(&t);	cout << endl;
	return &t;
}

tree *askDeleteElement(tree t) {
	cout << "Укажите значение удаляемого элемента: ";
	int info;
	cin >> info;
	t >> info;
	t.inorder(&t);	cout << endl;
	return &t;
}