#include<iostream>
#include<cstdio>
#include<cstring>
#define MAX 100
using namespace std;
int n;
int dpLineUp(int *num,int index){
	int result=0,dp[n];
	for(int i=0; i<index; i++){
		if(num[i]>=num[index]){
			dp[i] = 0;
			continue;
		}
		dp[i] = 1;
		for(int j=0; j<i;j++){
			if(num[j]<num[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		result = max(result,dp[i]);
	}
	return result;
}
int dpLineDown(int *num,int index){
	int result=0,dp[n];
	for(int i=index+1; i<n; i++){
		if(num[i]<=num[index]){
			dp[i] = 0;
			continue;
		}
		dp[i] = 1;
		for(int j=index+1; j<i;j++){
			if(num[j]>num[i]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		result = max(result,dp[i]);
	}
	return result;
}

int main(){
	int num[MAX];
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&num[i]);
	}
	int result = 0;
	for(int i=0; i<n; i++){
		result = max(result,dpLineUp(num,i)+dpLineDown(num,i)+1);
	}
	cout << n-result;
	return 0;
}
