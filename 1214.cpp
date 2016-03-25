/*
作者:calify@vip.qq.com
题目:p1214 线段覆盖
*/

/*
//如何写一份可以提交的代码？以P1000 A+B为例
#include <iostream>
using namespace std;
int main()
{
    int a, b; //定义两个变量名
    cin >> a >> b; //从标准输入流中输入两个整数
    cout << a + b << endl; //输出到标准输出流中

}
// 完成程序以后，点击下方的提交，即可看到测试结果
*/
#include<iostream>
using namespace std;
struct Line{
	int left;
	int right;
	int num;
	int isExit;
}*l;
int check(int i, int j){					//判断线段i是否存在于线段j中 
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
