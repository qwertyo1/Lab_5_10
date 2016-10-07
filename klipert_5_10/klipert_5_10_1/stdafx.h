#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

using namespace std;

class tree {
private:
	int info = 0; // поле с данными
	tree *left = NULL; // указатель на левое поддерево
	tree *right = NULL; // указатель на правое поддерево

	tree *stree(tree *root, tree *r, int info); // добавление элемента
	tree *dtree(tree *root, int key); // удаление элемента
public:
	tree* operator << (int value); // перегрузка оператора добавления элемента
	tree* operator >> (int value); // перегрузка оператора удаления элемента
	void inorder(tree *root); // печать элементов
};

tree *setElementInfo(tree t); // добавление элемента, возвращает список после добавления элемента
tree *askDeleteElement(tree t); // удаление элемента, возвращает список после удаления элемента