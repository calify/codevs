#include<iostream>
#include<cstring>
#define MAX 5000
using namespace std;
int main(){
	int dp[MAX],num[MAX],n,result=0;
	cin >> n;
	for(int i=0; i<n; i++){
		int temp;
		cin >> temp;
		num[i] = temp;
	}
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(num[j]<num[i]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		result = max(result,dp[i]);
	}
	cout << result;
	return 0;
}
