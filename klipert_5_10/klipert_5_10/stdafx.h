// stdafx.h: ���������� ���� ��� ����������� ��������� ���������� ������
// ��� ���������� ������ ��� ����������� �������, ������� ����� ������������, ��
// �� ����� ����������
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

typedef struct _treeElem {
	void *value;
	struct _treeElem *left;
	struct _treeElem *right;
	struct _treeElem *top;
} treeElem;

typedef struct _treeNode {
	treeElem *head;
} treeNode;

class huy {

};