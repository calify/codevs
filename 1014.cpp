#include<iostream>
#include<cstdio>
#define MAX 31
using namespace std;
int v,n,weight[MAX],dp[20001]={0};
int main(){
	scanf("%d%d",&v,&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&weight[i]);
	}
	//int max_weight = -1;
	for(int i=1; i<=n; i++){
		for(int j=v; j>=0; j--){
			dp[j] = weight[i]<=j?max(dp[j-weight[i]]+weight[i],dp[j]):dp[j];;
		}	
	}
	printf("%d",v-dp[v]);
	return 0;
}
