#include<iostream>
#define Max 200
using namespace std;


int main(){
/*��������˳���*/
	int Sq[Max];
	int n,i;
	int aim;
	int flag=0;
	cout << "����������˳����Ԫ�ظ�����" << endl;
	cin >> n;
	cout << "�밴��С�����˳������Ԫ�أ�" << endl;
	for (i = 0; i < n; i++) 
		cin >> Sq[i];
	int high = n - 1;
	int low = 0;
	cout << "������Ҫ���ҵ�Ԫ��:" << endl;
	cin >> aim;
	while (low <= high) {
		int mid = (high + low) / 2;
		if (Sq[mid] == aim){
			cout << "���ҵ�Ԫ��" << aim << "�����±�Ϊ" << mid<< endl;
			flag = 1;
			break;
		}
		else if (aim<Sq[mid]) high = mid - 1;                   //�����㷨�Է�Χ��low��high���仯
		else if (aim>Sq[mid])low = mid + 1;
	}
	if (flag == 0) cout << "����ʧ�ܣ�" << endl;
	return 0;
}

