#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 1000
using namespace std;
int dp[MAX][MAX*100];
int main(){
	int n,m,prices[MAX];
	memset(dp,0,sizeof(int)*MAX*MAX);
	cin >> n >> m;
	for(int i=0; i<n; i++){
		scanf("%d",&prices[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
				dp[i][j] = prices[i-1]<=m?max(dp[i-1][j],dp[i-1][j-prices[i-1]]+prices[i-1]):dp[i-1][j];
		}
	}
	cout << m-dp[n][m];
	return 0;
}
