#include<cstdio>
#include<cstring>
#define MAX 2
using namespace std;
typedef struct{
	int mat[MAX][MAX];
}Mat;
typedef struct{
	int n;
	int q;
}data;
int q;
Mat operator *(Mat a, Mat b){
	Mat c;
	memset(c.mat,0,sizeof(int)*MAX*MAX);
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
int operator ^(Mat a, int n){
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
int solve(data d){
	q = d.q;
	Mat c;
	c.mat[0][0] = 0;
	c.mat[0][1] = 1;
	c.mat[1][0] = 1;
	c.mat[1][1] = 1;
	return c^(d.n);
}
int main(){
	int t;
	data d[10000];
	scanf("%d",&t);
	for(int i=0; i<t; i++){
		int n,q;
		scanf("%d%d",&n,&q);
		d[i].n = n;
		d[i].q = q;
	}
	for(int i=0; i<t; i++){
		printf("%d\n",solve(d[i]));
	}
	return 0;
}
