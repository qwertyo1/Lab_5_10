#include "stdafx.h"

tree* formTree() {
	tree *node = new tree;
	cout << "Какой длины будет список?" << endl;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] = ";
		cin >> t;
		*node << t;
	}
	*node >> 0;
	node->treeprint(node);
	return node;
}

void menu(){
	tree *node = formTree();
	while (true) {
		cout << endl << "====== Меню работы с деревом поиска ======" << endl << " [1] Добавить элемент в дерево" << endl << " [2] Удалить элемент из дерева" << endl;
		switch (_getch()) {
		case '1': {	cout << "Значение элемента = ";
			int t;
			cin >> t;
			*node << t;
			node->treeprint(node);
			break; }
		case '2': {
			int t;
			cin >> t;
			*node >> t;
			//node = node->Remove(node, t);
			node->treeprint(node);
			break;
		}
		default: {exit(0); }
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	tree* noode = new tree;
	menu();
	system("pause");
    return 0;
}

