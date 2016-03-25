#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX 2
using namespace std;
typedef struct{
	long long mat[MAX][MAX];
}Mat;
int q = 1000000007;
Mat operator *(Mat a, Mat b){
	Mat c;
	memset(c.mat,0,sizeof(long long)*MAX*MAX);
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			for(int k=0; k<MAX; k++){
				c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
			}
			c.mat[i][j] = c.mat[i][j]%q;
		}
	}
	return c;
}
long long operator ^(Mat a, long long n){
	Mat c;
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			if(i == j){
				c.mat[i][j] = 1;
			}
			else{
				c.mat[i][j] = 0;
			}
		}
	}
	while(n>0){
		if(n%2==1){
			c = c*a;
		}
		n = n/2;
		a = a*a;
	}
	return c.mat[1][1];
}
int solve(long long n){
	Mat c;
	c.mat[0][0] = 0;
	c.mat[0][1] = 1;
	c.mat[1][0] = 1;
	c.mat[1][1] = 1;
	return c^(n-1);
}
int main(){
	long long n[1000];
	long long temp;
	int i=0;
	while(cin >> temp){
		n[i++] = temp;
	}
	//cin >> n;
	//scanf("%ld",&n);
	for(int j=0; j<i; j++){
		printf("%d\n",solve(n[j]));
	}
	return 0;
}
