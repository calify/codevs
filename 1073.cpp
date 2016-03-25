#include<iostream>
#include<cstdio>
#define MAX 5001
using namespace std;
int father[MAX], num[MAX];
void DisjointSet(int size){
	for(int i=1; i<=size; i++){
		father[i] = i;
		num[i] = 0;
	}
}

int find_father(int node){
	if(father[node]!=node){
		father[node] = find_father(father[node]);
	}
	return father[node];
}
bool merge(int a,int b){
	int a_father = find_father(a);
	int b_father = find_father(b);
	if(a_father!=b_father){
		if(num[a_father]>num[b_father]){
			swap(a_father,b_father);
		}
		father[a_father] = b_father;
		num[b_father] = max(num[b_father],num[a_father]+1);
		return true;
	}
	return false;
}

int main(){
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p);
	DisjointSet(n);
	for(int i=0; i<m; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		merge(a,b);
	}
	string result[MAX];
	for(int i=0; i<p; i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(find_father(a) == find_father(b)){
			result[i] = "Yes";
		}
		else{
			result[i] = "No";
		}
	}
	for(int i=0; i<p; i++){
		//printf("%s\n",result[i]);
		cout << result[i] << endl;
	}
	return 0;
}
