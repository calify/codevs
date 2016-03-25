#include<cstdio>
#include<cstring>
#define MAX 100
using namespace std;
int main(){
	int N;
	int a[MAX][MAX];
	memset(a,0,sizeof(int)*MAX*MAX);
	scanf("%d",&N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d",&a[i][j]);
		}
	}
	int num = 0;	//已经确定的节点数目 
	int total = 0;	//结果 
	bool visited[MAX];
	int dist[MAX];
	memset(visited,0,sizeof(bool)*MAX);
	memset(dist,0x3f,sizeof(int)*MAX);
	while(num<N){
		dist[0] = 0;
		int min = 0x3f3f3f3f, min_index;
		for(int i=0; i<N; i++){
			if(!visited[i]&&dist[i]<min){
					min = dist[i];
					min_index = i;
			}
		}
		total += min;
		visited[min_index] = 1;
		for(int i=0; i<N; i++){
			if(!visited[i]&&a[min_index][i]<dist[i]){
					dist[i] = a[min_index][i];
			}
		}
		num++;
	}
	printf("%d",total);
	return 0;
}
