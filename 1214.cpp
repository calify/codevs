/*
����:calify@vip.qq.com
��Ŀ:p1214 �߶θ���
*/

/*
//���дһ�ݿ����ύ�Ĵ��룿��P1000 A+BΪ��
#include <iostream>
using namespace std;
int main()
{
    int a, b; //��������������
    cin >> a >> b; //�ӱ�׼��������������������
    cout << a + b << endl; //�������׼�������

}
// ��ɳ����Ժ󣬵���·����ύ�����ɿ������Խ��
*/
#include<iostream>
using namespace std;
struct Line{
	int left;
	int right;
	int num;
	int isExit;
}*l;
int check(int i, int j){					//�ж��߶�i�Ƿ�������߶�j�� 
	if(!l[j].isExit){
		return 0;
	}
	if(l[i].left>l[j].left&&l[i].left<l[j].right){
		return 1;	
	}
	if(l[i].right>l[j].left&&l[i].right<l[j].right){
		return 1;
	}
	return 0;
}
int success(int n){
	int total = 0;
	for(int i=0; i<n; i++){
		if(l[i].isExit&&l[i].num){
			return 0;
		}
		else if(l[i].isExit&&!l[i].num){
			total++;
		}
	}
	return total;
}
int main(){
	int n;
	cin >> n;
	l = new Line[n];
	for(int i=0; i<n; i++){
		int left,right;
		cin >> left >> right;
		if(left>right){
			swap(left,right);
		}
		l[i].left = left;
		l[i].right = right;
		l[i].num = 0;
		l[i].isExit = 1;
		for(int j=0; j<i; j++){
			if(check(i,j)){
				l[i].num++;
			}
			if(check(j,i)){
				l[j].num++;
			}
		}
	}
	int max = -1;
	int index;
	int total;
	while(!(total=success(n))){
		for(int i=0; i<n; i++){
			if(l[i].isExit&&l[i].num>max){
				max = l[i].num;
				index = i;
			}
		}
		if(max != -1){
			for(int i=0; i<n; i++){
				if(check(index,i)){
					l[i].num--;
				}
			}
			l[index].isExit = 0;
			index = -1;
			max = -1;
		}
	}
	cout << total;
	return 0;
}
