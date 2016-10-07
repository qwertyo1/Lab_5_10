#include "stdafx.h"

tree * tree::stree(tree *root, tree *t, int info)
{
	if (!t) {
		t = new tree;
		if (!t) {
			cout << "Ќе хватает пам€ти!" << endl;
			exit(0);
		}
		t->left = NULL;
		t->right = NULL;
		t->info = info;
		if (!root) return t; // первый вход
		if (info < root->info) root->left = t;
		else root->right = t;
		return t;
	}
	if (info < t->info)
		stree(t, t->left, info);
	else
		stree(t, t->right, info);

	return root;
}

void tree::inorder(tree *root)
{
	if (!root) return;

	inorder(root->left);
	if (root->info) cout << root->info << " ";
	inorder(root->right);
}

tree * tree::dtree(tree *t, int key)
{
	tree *p, *p2;

	if (!t) return t; // вершина не найдена

	if (t->info == key) { // удаление корн€
							 // это означает пустое дерево
		if (t->left == t->right) {
			free(t);
			return NULL;
		}
		// или если одно из поддеревьев пустое
		else if (t->left == NULL) {
			p = t->right;
			free(t);
			return p;
		}
		else if (t->right == NULL) {
			p = t->left;
			free(t);
			return p;
		}
		// или есть оба поддерева
		else {
			p2 = t->right;
			p = t->right;
			while (p->left) p = p->left;
			p->left = t->left;
			free(t);
			return p2;
		}
	}
	if (t->info < key) t->right = dtree(t->right, key);
	else t->left = dtree(t->left, key);
	return t;
}

tree * tree::operator << (int value) {
	return stree(this, this, value);
}

tree * tree::operator >> (int value) {
	return dtree(this, value);
}