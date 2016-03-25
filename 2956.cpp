#include<cstdio>
using namespace std;
int sum = 0;
int n;
void dfs(int k){
	if(k==n){
		sum++;
	}
	else if(k<n){
		dfs(k+2);
		dfs(k+3);
	}
}
int main(){
	long long a[151];
	a[0] = 0;
	a[1] = 0;
	a[2] = 1;
	a[3] = 1;
	scanf("%d",&n);
	for(int i=4; i<=n; i++){
		a[i] = a[i-2] + a[i-3];
	}
	printf("%ld",a[n]);
	return 0;
}
