#include "stdafx.h"

tree *setElementInfo(tree t) {
	cout << "�������� ������ �������� = ";
	int info;
	cin >> info;
	t << info;
	t.inorder(&t);	cout << endl;
	return &t;
}

tree *askDeleteElement(tree t) {
	cout << "������� �������� ���������� ��������: ";
	int info;
	cin >> info;
	t >> info;
	t.inorder(&t);	cout << endl;
	return &t;
}