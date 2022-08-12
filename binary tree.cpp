#include<iostream>
#define Max 100
using namespace std;

typedef struct Node {          //��㶨��
	int data;
	struct Node* lchild, * rchild;
}Node;

/*�������������ඨ��*/
class BST {
public:
	void Create(int a[],int n);
	int Search(Node* bt, int aim, int path[], int i);
	int nonSearch(int aim, int path[], int i);
	void Delete(int target);
	void Deletehelp(Node *p);
	void Display(Node *bt);
	void Insert(Node* &p,int c);
	int InOrderTraverse(Node* bt);
public:
	Node* bt;
};

/*���ò��뺯����ʵ�ֶ����������Ĵ���*/
void BST::Insert(Node* &bt, int elem) {
	Node* p;
	p = new Node;
	p->data = elem;
	p->lchild = p->rchild = NULL;

	if (bt== NULL) {                        //������ֵ�����ڵ�
		bt = p;
		return;
	}
	if (bt->data == elem) return;
	/*�ݹ������������*/
	if (bt->data < elem) {
		Insert(bt->rchild, elem);           
		return;
	}
	else Insert(bt->lchild, elem);
	return;
}

void BST::Create(int a[],int n) {
	int i;
	for (i = 0; i < n; i++) {
		Insert(bt, a[i]);
	}
}

/*��������Լ���Ƿ�Ϊ����������*/
int BST::InOrderTraverse(Node* bt) {           //�ݹ��㷨
	int i=0;
	int b[Max];
	if (bt) {
		InOrderTraverse(bt->lchild);
		cout << bt->data << " ";
	    b[i] = bt->data;
		i++;
		InOrderTraverse(bt->rchild);
	}
	return b[i];                                //��������b[i]�����ж�
}

/*������������������ű��ʽ*/
void BST::Display(Node* bt){ 
	if (bt != NULL)
	{
		cout << bt->data;
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			cout << "(";                              //�к��ӽ��ʱ�������(��
			Display(bt->lchild);
			if (bt->rchild != NULL) cout << ",";      //���Һ��ӽ��ʱ�����������
			Display(bt->rchild);
			cout << ")";                             //�к��ӽ��ʱ�������)��
		}
	}
}

/*�����㷨*/
/*�ݹ��㷨*/
int BST::Search(Node* bt, int aim,int path[],int i) {
	int flag = 0;
	Node* t = bt;
	if (t == NULL)
		return i;
	if (t->data == aim) {
		path[i + 1] = t->data;
		return i + 1;
	}
		path[i + 1] = t->data;
	if (t->data < aim)
		return Search(t->rchild,aim,path,i+1);
	else return Search(t->lchild,aim,path,i+1);
}

/*�ǵݹ��㷨*/
int BST::nonSearch(int aim,int path[], int i) {
	int flag = 0;
	Node* t = bt;
	while (t) {
		if (t->data == aim) {
			path[i + 1] = t->data;
			return i+1;
		}
		path[i + 1] = t->data;
		if (t->data < aim) {
			t = t->rchild;
			i++;
		}
		else {
			t = t->lchild;
			i++;
		}
	}
}

/*ɾ���㷨*/
void BST::Delete(int target) {
	Node* p = bt;
	Node* f = NULL;
	Node* q, * s;
	q = s = NULL;
	/*����Ҫɾ���Ľ��*/
	if (!p) return;
	while (p) {
		if (p->data == target)
			break;
		f = p;
		if (p->data > target)
			p = p->lchild;
		else
			p = p->rchild;
	}
	/*�����������*/
	/*��������Ϊ��*/
	if (p->lchild && p->rchild) {
		q = p;
		s = p->lchild;
		while (s->rchild)               //Ѱ��ǰ�����  		
		{
			q = s; s = s->rchild;
		}
		p->data = s->data;
		if (q != p) {
			q->rchild = s->lchild;     	//�ؽ�������
		}
		else q->lchild = s->lchild;        		//�ؽ�������
		delete s;
	}
	/*���ҽ���һ������*/
	else {
		if (!p->rchild) {            //������              		
			q = p; p = p->lchild;
		}//else if
		else if (!p->lchild) {       //������
			q = p; p = p->rchild;
		}
		/*��ɾ�����ΪҶ�ӽ��*/
		if (!f) bt = p;
		else if (q == f->lchild) f->lchild = p;
		else f->rchild = p;
		delete q;
	}
}

int main() {
	BST B;
	B.bt = NULL;
	int a[10] = { 4,9,0,1,8,6,3,5,2,7 };
	int n = 10;
	B.Create(a, n);

	/*���������������Ƿ�Ϊ����������*/
	cout << "�������������������Ϊ��" << endl;
	int c[Max] = { B.InOrderTraverse(B.bt) };
	int flag = 1;
	for (int i = 0; i < 9; i++) {
		if (c[i] > c[i++]) {
			flag = 0; break;
		}
	}
	cout << endl;
	cout << "�жϸ����Ƿ�Ϊ����������:" << endl;
	system("pause");

	if (flag == 1) cout << "�����Ƕ�����������" << endl;
	cout << endl;

	/*������������������ű��ʽ*/
	cout << "���������������ű��ʽΪ��" << endl;
	B.Display(B.bt);
	cout << endl;


	/*����ݹ���ǵݹ���ҵ�·��*/
	int aim, result1, result2;
	int path[Max];
	cout << "������Ҫ���ҵĽ��Ԫ�أ�" << endl;
	cin >> aim;
	cout << "�ݹ��㷨�Ĳ���·���ǣ�" << endl;
	result1 = B.Search(B.bt, aim, path, -1);
	for (int j = 0; j < result1; j++) {
		cout << path[j] << " ";
	}
	cout << endl;

	cout << "�ǵݹ��㷨�Ĳ���·���ǣ�" << endl;
	result2 = B.nonSearch(aim,path, -1);
	for (int j = 0; j < result2; j++) {
		cout << path[j] << " ";
	}
	cout << endl;

	int target;
	cout << "������Ҫɾ���Ľ��Ԫ�أ�" << endl;
	cin >> target;
	B.Delete(target);

	B.Display(B.bt);

	return 0;
}


