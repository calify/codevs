#include<iostream>
#include<cstdio>
#include<cstring> 
//#include<vector>
#include<algorithm>
#define MAX 101
using namespace std;
int main(){	
	int n,k;		//�˵���Ŀ����ѡ��Ŀ 
	int x;			//������Ǯ 
	int v[MAX];	//�۸�*10 
	int w[MAX];	//��ζ��ֵ
	int food_num[MAX];//�˵ı�� 
	int num[MAX];	//��ѡ���
	int dp[MAX*10];
	bool isOK[MAX];
	memset(isOK,1,sizeof(bool)*MAX);
	memset(food_num,0,sizeof(int)*MAX);
	double temp;
	scanf("%d%d%lf",&n,&k,&temp);
	x = temp*10;
	for(int i=1;i<=n;i++) {
		double temp;
		scanf("%lf",&temp);
		v[i] = temp*10;
	}
	for(int i=1;i<=n;i++) {
		scanf("%d",&w[i]);
	}
	//int total = 0;//ʵ���ϲ˵����� 
	for(int i=1;i<=n;i++){
		int temp;
		scanf("%d",&temp);
		if(!food_num[temp]){
			food_num[temp] = i;
			//total++;
		}
		else{
			isOK[i] = 0;
		}
	}
	for(int i=0;i<k;i++) {
		scanf("%d",&num[i]);
	}
	int init_w = 0;//��ʼ��ζֵ
	//û�н���isOK��� 
	for(int i=0;i<k;i++) {
		x -= v[food_num[num[i]]];
		init_w += w[food_num[num[i]]];
		isOK[food_num[num[i]]] = 0;
	}
	for(int i=0;i<=x;i++){
		dp[i] = init_w;
	}
	for(int i=1;i<=n;i++){
		if(!isOK[i]){
			continue;
		}
		for(int j=x; j>=0; j--){
			if(j>=v[i]){
				dp[j] = max(dp[j],dp[j-v[i]]+w[i]);
			}
		}
	}
	printf("%d",dp[x]);
	return 0;
}
