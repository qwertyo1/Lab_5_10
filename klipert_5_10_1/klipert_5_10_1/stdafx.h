#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <conio.h>

using namespace std;

class tree {
private:
	int info = 0;
	//struct tree *root = NULL;
	tree *left = NULL;
	tree *right = NULL;
public:
	tree *stree(tree *root, tree *r, int info)
	{
		if (!r) {
			r = new tree;
			if (!r) {
				printf("Ќе хватает пам€ти\n");
				exit(0);
			}
			r->left = NULL;
			r->right = NULL;
			r->info = info;
			if (!root) return r; /* первый вход */
			if (info < root->info) root->left = r;
			else root->right = r;
			return r;
		}
		if (info < r->info)
			stree(r, r->left, info);
		else
			stree(r, r->right, info);

		return root;
	}

	void inorder(tree *root)
	{
		if (!root) return;

		inorder(root->left);
		if (root->info) cout << root->info << " ";
		inorder(root->right);
	}

	tree *dtree(tree *root, int key)
	{
		tree *p, *p2;

		if (!root) return root; /* вершина не найдена */

		if (root->info == key) { /* удаление корн€ */
								 /* это означает пустое дерево */
			if (root->left == root->right) {
				free(root);
				return NULL;
			}
			/* или если одно из поддеревьев пустое */
			else if (root->left == NULL) {
				p = root->right;
				free(root);
				return p;
			}
			else if (root->right == NULL) {
				p = root->left;
				free(root);
				return p;
			}
			/* или есть оба поддерева */
			else {
				p2 = root->right;
				p = root->right;
				while (p->left) p = p->left;
				p->left = root->left;
				free(root);
				return p2;
			}
		}
		if (root->info < key) root->right = dtree(root->right, key);
		else root->left = dtree(root->left, key);
		return root;
	}
};

int askTreeSize();
tree *setElementInfo(tree t, int n = askTreeSize());
tree *askDeleteElement(tree t);