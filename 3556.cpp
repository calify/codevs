#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 101*101
using namespace std;
//int dp[MAX][MAX];
int main(){
	int n,m,t,a;
	//int v[MAX],w[MAX],k[MAX];
	int *v,*w,*k,**dp;
	//memset(dp,0,sizeof(int)*MAX*MAX);
	cin >> n >> m >> t >> a;
	v = new int[n*m+1];
	w = new int[n*m+1];
	k = new int[n*m+1];
	dp = new int*[n*m+1];
	t = min(t,a);
	for(int i=0; i<=t;i++){
		dp[i] = new int[t+1];
		memset(dp,0,sizeof(int)*(t+1));
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			scanf("%d",&v[(i-1)*m+j]);
			w[(i-1)*m+j] = (i+j)*2;
		} 
	}
	for(int i=1; i<=n*m; i++){
		scanf("%d",&k[i]);
	}
	int result = -1;
	for(int i=1; i<=n*m; i++){
		for(int j=1; j<=t; j++){
				if(k[i]&&v[i]){
					if(w[i]<j){
						if(dp[i-1][j]<dp[i-1][j-w[i]]+v[i]){
							dp[i][j] = dp[i-1][j-w[i]]+v[i];
							k[i]--;
						}
						else{
							dp[i][j] = dp[i-1][j];
						}
					}
					else{
						dp[i][j] = dp[i-1][j];
					}	
				}
				result = max(result,dp[i][j]);
		}	
	}
	for(int i=1; i<=n*m; i++){
		for(int j=1; j<=t; j++){
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	cout << result;
	delete[] v;
	delete[] w;
	delete[] k;
	for(int i=0; i<=t;i++){
		delete[] dp[i];
	}
	delete[] dp;
	return 0;
}
