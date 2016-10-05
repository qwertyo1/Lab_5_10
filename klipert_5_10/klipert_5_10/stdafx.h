#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

using namespace std;

class tree {
private:
	int value = NULL;
	class tree *left = NULL;
	class tree *right = NULL;
public:
	tree *add_to_tree(tree *root, int value)
	{
		if (root == NULL)  // ���� ��� ������� - ������� ����� �������
		{
			tree *root = new tree;
			root->value = value;
			root->left = root->right = 0;
			return root;
		}
		if (root->value < value)          // �������� �����
			root->right = add_to_tree(root->right, value);
		else
			root->left = add_to_tree(root->left, value);
		return root;
	}

	tree* operator << (int value) {
		return add_to_tree(this, value);
	}

	tree& operator >> (int value) {
		tree * root = this;
		tree * pointer = root;
		tree * parent = NULL;

		while (pointer != NULL && pointer->value != value)
		{
			parent = pointer;
			if (value < pointer->value)
				pointer = pointer->left;
			else
				pointer = pointer->right;
		}

		if (pointer != NULL)
		{
			tree * removed = NULL;

			if (pointer->left == NULL || pointer->right == NULL)
			{
				tree * child = NULL;
				removed = pointer;

				if (pointer->left != NULL)
					child = pointer->left;
				else if (pointer->right != NULL)
					child = pointer->right;

				if (parent == NULL)
					root = child;
				else
				{
					if (parent->left == pointer)
						parent->left = child;
					else
						parent->right = child;
				}
			}
			else
			{
				tree * mostLeft = pointer->right;
				tree * mostLeftParent = pointer;

				while (mostLeft->left != NULL)
				{
					mostLeftParent = mostLeft;
					mostLeft = mostLeft->left;
				}

				pointer->value = mostLeft->value;
				removed = mostLeft;

				if (mostLeftParent->left == mostLeft)
					mostLeftParent->left = NULL;
				else
					mostLeftParent->right = NULL;
			}
			delete removed;
		}
		*this = *root;
		return *root;
	}

	void treeprint(tree *root) {
		if (root != NULL) { //���� �� ���������� ������ ����
			treeprint(root->left); //����������� ������� ������ ������ ���������
			cout << root->value << " "; //���������� ������ ������
			treeprint(root->right); //����������� ������� ������ ������� ���������
		}
	}
};