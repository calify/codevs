#include<cstdio>
using namespace std;
int total = 0;
int n;
void dfs(int l, int num, int k){
	if(l==n){
		total++;
		//printf("\n");
	}
	else{
		for(int i=0; i<=1; i++){
			if(num==i&&k==2){
				k=0;
				continue;
			}
			else if(num!=i){
				dfs(l+1,i,1);
				//k=0;
			}
			else{
				dfs(l+1,i,k+1);
			}
			//printf("%d",i);
			//dfs(l+1,i,k+1);
		}
	}
}
int main(){
	scanf("%d",&n);
	dfs(0,-1,0);
	printf("%d",total);
	return 0;
}
