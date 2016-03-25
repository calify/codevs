#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 100
using namespace std;
int dp[MAX][MAX*MAX];  
int main(){
	int n,c,v[MAX],w[MAX];
	memset(dp,0,sizeof(int)*MAX*MAX);
	cin >> n >> c;
	for(int i=0; i<n; i++){
		scanf("%d",&v[i]);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&w[i]);
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=c; j++){
				dp[i][j] = v[i-1]<=j?max(dp[i-1][j],dp[i-1][j-v[i-1]]+w[i-1]):dp[i-1][j];
		}
	}
	cout << dp[n][c];
	return 0;
}
