#include<iostream>
#define Max 200
using namespace std;


int main(){
/*创建有序顺序表*/
	int Sq[Max];
	int n,i;
	int aim;
	int flag=0;
	cout << "请输入有序顺序表的元素个数：" << endl;
	cin >> n;
	cout << "请按从小到大的顺序输入元素：" << endl;
	for (i = 0; i < n; i++) 
		cin >> Sq[i];
	int high = n - 1;
	int low = 0;
	cout << "请输入要查找的元素:" << endl;
	cin >> aim;
	while (low <= high) {
		int mid = (high + low) / 2;
		if (Sq[mid] == aim){
			cout << "查找到元素" << aim << "，其下标为" << mid<< endl;
			flag = 1;
			break;
		}
		else if (aim<Sq[mid]) high = mid - 1;                   //根据算法对范围（low、high）变化
		else if (aim>Sq[mid])low = mid + 1;
	}
	if (flag == 0) cout << "查找失败！" << endl;
	return 0;
}

