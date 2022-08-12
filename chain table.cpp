#include<iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

int main() {
	/*创建有序单链表*/
	Node* L;
	L = new Node;
	L->next = NULL;

	Node* p, * q;
	int n, i;
	p = L;
	cout << "请输入有序单链表的元素个数：" << endl;
	cin >> n;
	cout << "请输入有序单链表的元素：" << endl;
	for (i = 1; i <= n; i++) {
		q = new Node;
		cin >> q->data;
		q->next = p->next;
		p->next = q;
		p = q;
	}

	int aim;
	int flag = 0;
	Node* f=L->next;
	cout << "请输入要查找的元素：" << endl;
	cin >> aim;
	for (i = 1; i <= n; i++) {
		if (f->data == aim) {
			cout << "查找到元素" << aim << ",是第" << i << "个结点" << endl;
			flag = 1;
			break;
		}
		else f = f->next;
	}
	if (flag == 0) cout << "查找失败！" << endl;
	return 0;
}
