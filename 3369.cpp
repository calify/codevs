#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int a[2501];
	int dp[2501];
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
	}
	int n1=0,n2=0;
	dp[0] = 1;
	for(int i=1; i<=n; i++){
		int t;
		if(a[i]==1){
			n1++;
			t=1;
		}
		else{
			n2++;
			t=2;
		}
		if(!n1||!n2||abs(n1-n2)<=m){
			dp[i] = dp[i-1];
		}
		else{
			dp[i] = dp[i-1] + 1;
			if(t==1){
				n1=1;
				n2=0;
			}
			else{
				n1=0;
				n2=1;
			}
		}
	}
	printf("%d",dp[n]);
	return 0;
}
