#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int total = 0;

void dfs(int n, int num, int j, int a[]){		//j���� 
	if(num != n){
		int i=1;
		while(i<=n){
			bool flag = true;
			if(a[i]){							//�� 
				flag = false;

			}
			if(flag){
				int ii=i,jj=j;
				while(ii-1>=1&&jj-1>=1){		//���� 
					ii--;
					jj--;
					if(a[ii]==jj){
						flag = false;
						break;
					}
				}
				if(flag){
					ii=i;
					jj=j;
					while(ii+1<=n&&jj-1>=1){	//���� 
						ii++;
						jj--;
						if(a[ii]==jj){
							flag = false;
							break;
						}
					}
				}	
			}
			if(flag){
				a[i] = j;
				dfs(n,num+1,j+1,a);
				a[i] = 0;
				i++;
			}
			else{
				i++;
			}
		};
	}
	else{
		total++;
	}
}
int main(){
	int n;
	cin >> n;
	int *a = new int[n+1];		//�м�¼ 
	memset(a,0,sizeof(int)*(n+1));
	dfs(n,0,1,a);
	cout << total;
	return 0;
}
