#include<iostream>
#include<cstring>
using namespace std;
int total;
int dfs(int n){
	int total = 1;
	if(n==1){
		return 1;
	}
	else{
		for(int i=1; i<=n/2; i++){
			total += dfs(i);
		}
	}
	return total;
}
int main(){
	int n;
	int total;
	cin >> n; 
	cout << dfs(n);
	return 0;
}
