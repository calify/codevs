#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int max_num;
string *s;
int n;
void search(int total[], string dragon){
	string temp_dragon = dragon;
	int d_length = dragon.length();
	for(int i=d_length-1; i>=0; i--){					//从后往前截取 
		string buf = dragon.substr(i,d_length-i);		//截取出来的字符串 
		for(int j=0; j<n; j++){							//遍历字符串 				
			string other_s = s[j];
			int o_length = other_s.length();
			if(buf.length()<=o_length){				//如果截取的字符串长度大于当前字符串的长度，不进行判断 
				string other_buf = other_s.substr(0,d_length-i);
				if(other_buf==buf&&total[j]<2){
					total[j]++;
					dragon += other_s.substr(d_length-i,other_s.length()-(d_length-i));
					//cout << dragon << endl;
					if(max_num < (int)dragon.length()){
						max_num = dragon.length();
					}
					search(total,dragon);
					total[j]--;
					dragon = temp_dragon;
				}
			}	
		}	
	}
}
int main(){
	string temp;
	int *total;
	cin >> n;
	s = new string[n];
	total = new int[n];
	memset(total,0,sizeof(int)*n);
	for(int i=0; i<n; i++){
		cin >> temp;
		s[i] = temp;
	}
	cin >> temp;
	max_num = -1;
	search(total, temp);
	cout << max_num;
	return 0;
}
