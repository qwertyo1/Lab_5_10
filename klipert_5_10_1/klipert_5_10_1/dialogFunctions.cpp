#include "stdafx.h"

int askTreeSize() {
	cout << "Укажите количество элементов дерева: ";
	int n;
	cin >> n;
	return n;
}

tree *setElementInfo(tree t, int n) {
	for (int i = 0; i < n; i++)
	{
		cout << "Значение элемента [" << i << "] = ";
		int info;
		cin >> info;
		t.stree(&t, &t, info);
	}
	t.inorder(&t);	cout << endl;
	return &t;
}

tree *askDeleteElement(tree t) {
	cout << "Укажите значение удаляемого элемента: ";
	int info;
	cin >> info;
	t.dtree(&t, info);
	t.inorder(&t);	cout << endl;
	return &t;
}