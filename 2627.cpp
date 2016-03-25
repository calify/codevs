#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define MAX 100
using namespace std;
typedef struct{
	int x,y,weight;
}data;
bool cmp(data a, data b){
	return a.weight<b.weight;
}
int main(){
	bool visited[MAX];
	memset(visited,0,sizeof(bool)*MAX);
	int n;
	int a[MAX][MAX];
	data d[MAX*(MAX-1)/2];
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&a[i][j]);
		}
	}
	int index = 0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			d[index].weight = a[i][j];
			d[index].x = i;
			d[index].y = j;
			index++;
		}
	}
	sort(d,d+n*(n-1)/2,cmp);
	int sum = 0;
	for(int i=0; i<n*(n-1)/2; i++){
		if(!visited[d[i].x]||!visited[d[i].y]){
			sum += d[i].weight;
			visited[d[i].x] = 1;
			visited[d[i].y] = 1;
		}
	}
	printf("%d",sum);
	return 0;
}
