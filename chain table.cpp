#include<iostream>
using namespace std;

typedef struct Node {
	int data;
	Node* next;
}Node;

int main() {
	/*������������*/
	Node* L;
	L = new Node;
	L->next = NULL;

	Node* p, * q;
	int n, i;
	p = L;
	cout << "���������������Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "���������������Ԫ�أ�" << endl;
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
	cout << "������Ҫ���ҵ�Ԫ�أ�" << endl;
	cin >> aim;
	for (i = 1; i <= n; i++) {
		if (f->data == aim) {
			cout << "���ҵ�Ԫ��" << aim << ",�ǵ�" << i << "�����" << endl;
			flag = 1;
			break;
		}
		else f = f->next;
	}
	if (flag == 0) cout << "����ʧ�ܣ�" << endl;
	return 0;
}
