#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int N,M;
	int a[350],b[5],dp[350];
	memset(b,0,sizeof(int));
	scanf("%d%d",&N,&M);
	for(int i=0; i<N; i++){
		scanf("%d",&a[i]);
	}
	for(int i=0; i<M; i++){
		int temp;
		scanf("%d",&temp);
		b[temp]++;
	}
	for(int i=0; i<N; i++){
		dp[i] = a[0];
	}
	for(int i=1; i<N; i++){
		for(int j=1; j<=b[1]; j++){
			if(i>=j*1){
				dp[i] = max(dp[i],dp[i-j*1]+a[i]);
			}
			for(int k=1; k<=b[2]; k++){
				if(i>=k*2){
					dp[i] = max(dp[i],dp[i-k*2]+a[i]);
				}
				for(int t=1; t<=b[3]; t++){
					if(i>=t*3){
						dp[i] = max(dp[i],dp[i-t*3]+a[i]);
					}
					for(int l=1; l<=b[4]; l++){
						if(i>=l*4){
							dp[i] = max(dp[i],dp[i-l*4]+a[i]);
						}
					}
				}
			}
		}
	}
	printf("%d",dp[N-1]);
	return 0;
}
