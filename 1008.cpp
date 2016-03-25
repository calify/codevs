#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k,total = 0;
bool issushu(int a){
	int aa = sqrt(a)+1;
	for(int i=2; i<=aa; i++){
		if(a%i==0){
			return false;
		}
	}
	return true;
}
void cal(const int *a, int i, int *b, int kk){//i是a的下标，kk是b的长度 
	if(kk == k){
		int sum=0;
		for(int j=0; j<k; j++){
			sum += b[j];
		}
		if(issushu(sum)){
			total++;
		}
	}
	else{
		for(int j=i; j<n;j++){
			b[kk] = a[j];
			cal(a,j+1,b,kk+1);
		}
	}
}
int main(){
	int a[20],b[20];
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	cal(a,0,b,0);
	printf("%d",total);
	return 0;
}
