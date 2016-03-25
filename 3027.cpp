#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 1000
using namespace std;
struct Line{
	int left;
	int right;
	int value;
}l[MAX];
int comp(const void *a, const void *b){
	struct Line *aa = (Line*) a;
	struct Line *bb = (Line*) b;
	return aa->left - bb->left;
}
int main(){
	int n,dp[MAX];
	memset(dp,0,sizeof(int)*MAX);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		if(a>b){
			swap(a,b);
		}
		l[i].left = a;
		l[i].right = b;
		l[i].value = c;
	}
	qsort(&l[0],n,sizeof(Line),comp);
	int max_value = -1;
	for(int i=0; i<n; i++){
		dp[i] = l[i].value;
		for(int j=i-1; j>=0; j--){
			if( l[i].left>=l[j].right ){
				dp[i] = max(dp[i],dp[j]+l[i].value);
			}
		}
		max_value = max(max_value,dp[i]);
	}
	printf("%d",max_value);
	//dp[0] = value[0];
	return 0;
}
