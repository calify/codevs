#include<iostream>
#include<cstring>
using namespace std;
int **p;
int n;
int ans=0;
int check(int index,int color[], int c){
	if(color[index]){				//已经染色 
		return 0;
	}
	for(int i=0; i<n; i++){
		if(p[index][i] && color[i]==c){	//相邻节点染了相同颜色 
			return 0;
		}
	}
	return 1;
}
void dfs(int index, int color[]){
	if(index == n){
		ans++;
	}
	else{
		for(int i=1; i<5; i++){
			if(check(index,color,i)){
				color[index] = i;
				dfs(index+1,color);
				color[index] = 0;
			}
		}
	}	
}
int main(){
	int *color;
	cin >> n;
	p = new int*[n];		//邻接矩阵 
	color = new int[n];
	memset(color,0,sizeof(int)*n);
	for(int i=0; i<n; i++){
		p[i] = new int[n];
		memset(p[i],0,sizeof(int)*n);
	}
	int temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> temp;
			p[i][j] = temp;
		}
	}
	dfs(0, color);
	cout << ans;
	for(int i=0; i<n; i++){
		delete p[i];
	}
	delete[] p;
	delete[] color;
	return 0;
}
