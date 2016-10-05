// stdafx.h: включаемый файл дл€ стандартных системных включаемых файлов
// или включаемых файлов дл€ конкретного проекта, которые часто используютс€, но
// не часто измен€ютс€
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>

using namespace std;

typedef struct _treeElem {
	int value;
	struct _treeElem *left;
	struct _treeElem *right;
} treeElem;

typedef struct _treeNode {
	treeElem *head;
} treeNode;

class tree {
private:
	treeElem *head;
public:
	treeElem *add_to_tree(treeElem *t, int value)
	{
		if (t == NULL)  // если нет сыновей - создаем новый элемент
		{
			treeElem *root = new treeElem;
			root->value = value;
			root->left = root->right = NULL;
			return root;
		}
		if (t->value < value)          // добавлем ветвь
			t->right = add_to_tree(t->right, value);
		else
			t->left = add_to_tree(t->left, value);
		return t;
	}
};