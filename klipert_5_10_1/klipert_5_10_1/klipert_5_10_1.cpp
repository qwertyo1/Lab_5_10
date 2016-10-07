// klipert_5_10_1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"


int main()
{
	setlocale(LC_ALL, "ru");
	tree t;
	int n = askTreeSize();
	t = *setElementInfo(t, n);
	t = *askDeleteElement(t);
	system("pause");
    return 0;
}