#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 201
using namespace std;
int dp[200001];
int main(){
	int n,v_max;
	scanf("%d%d",&n,&v_max);
	int v[MAX],w[MAX],m[MAX];
	memset(dp,0,sizeof(int)*200001);
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&v[i],&w[i],&m[i]);
	}
	for(int i=1; i<=n; i++){
		if(m[i]==-1){					//完全背包 
			for(int j=0; j<=v_max; j++){
				if(j>=v[i]){
					dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
				}
			}
		}
		else{						//多重背包 
			for(int j=v_max; j>=v[i]; j--){
				for(int k=0; k<=m[i]; k++){
					if(j>=v[i]*k){
						dp[j] = max(dp[j],dp[j-v[i]*k]+w[i]*k);
					}
				}
			}
		}
	}
	printf("%d",dp[v_max]);
	return 0;
}
