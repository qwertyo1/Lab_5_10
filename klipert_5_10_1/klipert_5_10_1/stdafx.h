#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

using namespace std;

class tree {
private:
	int info = 0; // ���� � �������
	tree *left = NULL; // ��������� �� ����� ���������
	tree *right = NULL; // ��������� �� ������ ���������

	tree *stree(tree *root, tree *r, int info); // ���������� ��������
	tree *dtree(tree *root, int key); // �������� ��������
public:
	tree* operator << (int value); // ���������� ��������� ���������� ��������
	tree* operator >> (int value); // ���������� ��������� �������� ��������
	void inorder(tree *root); // ������ ���������
};

tree *setElementInfo(tree t); // ���������� ��������, ���������� ������ ����� ���������� ��������
tree *askDeleteElement(tree t); // �������� ��������, ���������� ������ ����� �������� ��������