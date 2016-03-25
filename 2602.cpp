#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define MAX 101
using namespace std;
const double INF = 1061109567;
double dist[MAX][MAX];
int n;
typedef struct Point{
	double x;
	double y;
}point;
void floyd(){
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}
double dijkstra(int p,int t){
	bool visited[MAX];
	memset(visited,0,sizeof(bool)*MAX);
	double d[MAX];
	for(int i=1; i<MAX; i++){
		d[i] = INF;
	}
	d[p] = 0;
	for(int i=1; i<=n; i++){
		double min_dist = INF;
		int index;
		for(int j=1; j<=n; j++){
			if(!visited[j]&&d[j]<min_dist){
				min_dist = d[j];
				index = j;
			}
		}
		visited[index] = 1;
		for(int j=1; j<=n; j++){
			if(!visited[j]&&dist[index][j]+min_dist<d[j]){
				d[j] = dist[index][j]+min_dist;
			}
		}
	}
	return d[t];
}
int main(){
	point p[MAX];
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		double x,y;
		scanf("%lf%lf",&x,&y);
		p[i].x = x;
		p[i].y = y;
	}
	int m;
	scanf("%d",&m);
	for(int i=0; i<MAX; i++){		//初始化为无穷大 
		for(int j=0; j<MAX; j++){
			if(i == j){
				dist[i][j] = 0;
			}
			dist[i][j] = INF;
		}
	}
	for(int i=0; i<m; i++){
		int p1,p2;
		scanf("%d%d",&p1,&p2);
		dist[p1][p2] = sqrt(pow(p[p1].x-p[p2].x,2)+pow(p[p1].y-p[p2].y,2));
		dist[p2][p1] = dist[p1][p2];
	}
	int s,t;
	scanf("%d%d",&s,&t);
	//floyd();
	printf("%.2f",dijkstra(s,t));
	return 0;
}
