#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	int n;
	int **num;
	scanf("%d",&n);
	num = new int*[n];
	for(int i=0; i<n; i++){
		num[i] = new int[n];
		memset(num[i],0,sizeof(int)*n);
	}
	int k = n*n;
	int i,j;
	if(n%2==0){
		i = 0;
		j = 0;
	}
	else{
		i = n-1;
		j = n-1;
	}
	num[i][j] = k--;
	while(k>0){	//四个方向的布尔值，1表示可以在这个方向前进，0表示不能在这个方向前进 
		bool left = !( i-1<0 || num[i-1][j] );
		bool right = !( i+1>=n || num[i+1][j]);
		bool up = !( j-1<0 || num[i][j-1]);
		bool down = !( j+1>=n || num[i][j+1]);
		if(!left&&!up&&right){
			i++;
		}
		else if(!right&&!up&&down){
			j++;
		}
		else if(!right&&!down&&left){
			i--;
		}
		else if(!left&&!down&&up){
			j--;
		}
		num[i][j]=k--;
	}
	int sum = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ",num[j][i]);
			if(i==j || i+j == n-1){
				sum += num[j][i];
			}
		}
		printf("\n");
	}
	//if(n%2!=0){
	//	sum--;
	//}
	printf("%d",sum);
	for(int i=0; i<n; i++){
		delete[] num[i];
	}
	delete num;
	return 0;
}
