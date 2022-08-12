#include<iostream>
#define Max 100
using namespace std;

typedef struct Node {          //结点定义
	int data;
	struct Node* lchild, * rchild;
}Node;

/*二叉排序树的类定义*/
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

/*调用插入函数来实现二叉排序树的创建*/
void BST::Insert(Node* &bt, int elem) {
	Node* p;
	p = new Node;
	p->data = elem;
	p->lchild = p->rchild = NULL;

	if (bt== NULL) {                        //树空则赋值给根节点
		bt = p;
		return;
	}
	if (bt->data == elem) return;
	/*递归插入左右子树*/
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

/*中序遍历以检查是否为二叉排序树*/
int BST::InOrderTraverse(Node* bt) {           //递归算法
	int i=0;
	int b[Max];
	if (bt) {
		InOrderTraverse(bt->lchild);
		cout << bt->data << " ";
	    b[i] = bt->data;
		i++;
		InOrderTraverse(bt->rchild);
	}
	return b[i];                                //返回数组b[i]用以判断
}

/*输出二叉排序树的括号表达式*/
void BST::Display(Node* bt){ 
	if (bt != NULL)
	{
		cout << bt->data;
		if (bt->lchild != NULL || bt->rchild != NULL)
		{
			cout << "(";                              //有孩子结点时才输出“(”
			Display(bt->lchild);
			if (bt->rchild != NULL) cout << ",";      //有右孩子结点时才输出“，”
			Display(bt->rchild);
			cout << ")";                             //有孩子结点时才输出“)”
		}
	}
}

/*查找算法*/
/*递归算法*/
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

/*非递归算法*/
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

/*删除算法*/
void BST::Delete(int target) {
	Node* p = bt;
	Node* f = NULL;
	Node* q, * s;
	q = s = NULL;
	/*查找要删除的结点*/
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
	/*结点的三种情况*/
	/*子树均不为空*/
	if (p->lchild && p->rchild) {
		q = p;
		s = p->lchild;
		while (s->rchild)               //寻找前驱结点  		
		{
			q = s; s = s->rchild;
		}
		p->data = s->data;
		if (q != p) {
			q->rchild = s->lchild;     	//重接右子树
		}
		else q->lchild = s->lchild;        		//重接左子树
		delete s;
	}
	/*有且仅有一颗子树*/
	else {
		if (!p->rchild) {            //左子树              		
			q = p; p = p->lchild;
		}//else if
		else if (!p->lchild) {       //右子树
			q = p; p = p->rchild;
		}
		/*被删除结点为叶子结点*/
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

	/*用中序遍历来检测是否为二叉排序树*/
	cout << "二叉排序树的中序遍历为：" << endl;
	int c[Max] = { B.InOrderTraverse(B.bt) };
	int flag = 1;
	for (int i = 0; i < 9; i++) {
		if (c[i] > c[i++]) {
			flag = 0; break;
		}
	}
	cout << endl;
	cout << "判断该树是否为二叉排序树:" << endl;
	system("pause");

	if (flag == 1) cout << "该树是二叉排序树！" << endl;
	cout << endl;

	/*输出二叉排序树的括号表达式*/
	cout << "二叉排序树的括号表达式为：" << endl;
	B.Display(B.bt);
	cout << endl;


	/*输出递归与非递归查找的路径*/
	int aim, result1, result2;
	int path[Max];
	cout << "请输入要查找的结点元素：" << endl;
	cin >> aim;
	cout << "递归算法的查找路径是：" << endl;
	result1 = B.Search(B.bt, aim, path, -1);
	for (int j = 0; j < result1; j++) {
		cout << path[j] << " ";
	}
	cout << endl;

	cout << "非递归算法的查找路径是：" << endl;
	result2 = B.nonSearch(aim,path, -1);
	for (int j = 0; j < result2; j++) {
		cout << path[j] << " ";
	}
	cout << endl;

	int target;
	cout << "请输入要删除的结点元素：" << endl;
	cin >> target;
	B.Delete(target);

	B.Display(B.bt);

	return 0;
}


