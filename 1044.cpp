#include<iostream>
#include<cstring>
#include<stack>
#define MAX 5000
using namespace std;
int num[MAX],n=0;
int setDp(int *dp){
	int result = 0;
	for(int i=0; i<n; i++){
		dp[i] = 1;
		for(int j=0; j<i; j++){
			if(num[j]>=num[i]){
				dp[i] = max(dp[i], dp[j]+1);
			}
		}
		result = max(result,dp[i]);	
	}
	return result;	
}
bool search(){
	stack<int> s;
	int num_index[MAX],index = 0;			//��¼ջ����num��������� 
	memset(num_index,0xff,sizeof(int)*MAX);
	for(int i=0; i<n; i++){
		if(num[i]!=-1){ 
			while(!s.empty()&&s.top()<num[i]){	//����ջ�����ջ����ֵ�ȼ�����ջ��ֵҪС���͵����ص�ԭ����num������ 
				num[num_index[--index]] = s.top();
				s.pop();
			}
			if(s.empty()||s.top()>=num[i]){
				s.push(num[i]);
				num[i] = -1;
				num_index[index++] = i;		//��¼ջ������ 
			}
		}
	}
	if(!s.empty()){
		return 1;
	}
	return 0;
}

int main(){
	int dp[MAX];
	memset(num,0xff,sizeof(int)*MAX);		//-1��ʾ���λ��û������ 
	while(cin >> num[n]){
		n++;
	}
	int result = setDp(dp);
	int total = 0;
	while(search()){
		total++;
	};
	cout << result << endl << total;
	return 0;
}
