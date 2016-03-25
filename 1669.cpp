#include<cstdio>
#include<cstring>
#include<algorithm>
#define MAX 1001
using namespace std;
int dp[MAX][MAX];
int main(){
	int v_max,g_max;
	int n;
	scanf("%d%d",&v_max,&g_max);
	scanf("%d",&n);
	int t[MAX],v[MAX],g[MAX];
	for(int i=1; i<=n; i++){
		scanf("%d%d%d",&t[i],&v[i],&g[i]);
	}
	memset(dp,0,sizeof(int)*MAX*MAX);
	for(int i=1; i<=n; i++){
		for(int j=v_max; j>=v[i]; j--){
			for(int k=g_max; k>=g[i]; k--){
				//if(j>=v[i]&&k>=g[i]){
					dp[j][k] = max(dp[j][k],dp[j-v[i]][k-g[i]]+t[i]);
				//}
			}
		}
	}
	printf("%d",dp[v_max][g_max]);
	return 0;
}
