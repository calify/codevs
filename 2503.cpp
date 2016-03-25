#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 101
using namespace std;
//int dp[MAX][10000];
int dp[10000];
int main(){
	int m,n,p[MAX],w[MAX],h[MAX];
	//memset(dp,0,sizeof(int)*MAX*10000);
	memset(dp,0,sizeof(int)*10000);
	scanf("%d%d",&m,&n);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&p[i],&w[i],&h[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=m; j>=1; j--){
			for(int k=0;k<=h[i];k++){
				if(j>=k*p[i]){
					dp[j] = max(dp[j],dp[j-k*p[i]]+k*w[i]);
				}
				//else{
				//	dp[i][j] = dp[i-1][j];
				//}	
			}
			//s = max(s,dp[i][j]);
		}	
	}
	//for(int i=1; i<=n; i++){
		//for(int j=1; j<=m; j++){
			//printf("%d ",dp[i][j]);
	//	}
	//	printf("\n");
	//}
	printf("%d",dp[m]);
	return 0;
}
