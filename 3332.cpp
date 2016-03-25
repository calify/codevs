#include<cstdio>
#include<cstring>
#define MAX 3
#define MOD 1000000007
using namespace std;
typedef struct{
	long long mat[MAX][MAX];
}Mat;
Mat operator *(Mat a, Mat b){
	Mat c;
	memset(c.mat,0,sizeof(long long)*MAX*MAX);
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			for(int k=0; k<MAX; k++){
				c.mat[i][j] += a.mat[i][k]*b.mat[k][j];
			}
			c.mat[i][j] = c.mat[i][j]%MOD;
		}
	}
	return c;
}
long long operator ^(Mat a,int b){
	Mat c;
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			if(i==j){
				c.mat[i][j] = 1;
			}
			else{
				c.mat[i][j] = 0;
			}
		}
	}
	while(b>0){
		if(b%2==1)
			c = c*a;
		b = b/2;
		a = a*a;
	}
	return c.mat[0][0];
}
int main(){
	int n;
	scanf("%d",&n);
	int a[100];
	for(int i=0; i<n; i++){
		scanf("%d",&a[i]);
	}
	Mat c;
	c.mat[0][0] = 1;
	c.mat[0][1] = 1;
	c.mat[0][2] = 0;
	c.mat[1][0] = 0;
	c.mat[1][1] = 0;
	c.mat[1][2] = 1;
	c.mat[2][0] = 1;
	c.mat[2][1] = 0;
	c.mat[2][2] = 0;
	for(int i=0; i<n; i++){
		printf("%ld\n",c^(a[i]-1));
	}
	return 0;
}
