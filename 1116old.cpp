#include<iostream>
#include<cstring>
#include<vector>
#include<set>
using namespace std;
int max_num;
int *color;				//01234，0未染色 
class Table{
	private:
		int n;
		vector<int> *link_table;
	public:
		Table(int input_n){
			n = input_n;
			link_table = new vector<int>[n];
		}
		~Table(){
			delete[] link_table;
		}
		void insert(int a, int b){
			link_table[a].push_back(b);
		}
		void progress_color(int x, int color[], int num){
			set<int> hasColor;			//记录邻接已经染了的颜色 
			for(int i:link_table[x]){
					if(color[i]){
						hasColor.insert(color[i]);
					}
			}
			if(hasColor.size()!=4){
				for(int i=1; i<5; i++){
					bool flag = true;		//判断能否将当前颜色染到该点 
					if(!hasColor.empty()){
						for(int j: hasColor){
							if(j == i){
								flag = false;
								break;
							}
						}
					}
					if(flag){
						color[x] = i;
						num++;
						bool lian = false;
						for(int j:link_table[x]){
							if(!color[j]){
								lian = false;
								progress_color(j,color,num);
								break;					//每次只处理一个相邻的节点 
							}
							lian = true;
						}
						if(num == n){
							set<int> hasColor;
							for(int i=0; i<n; i++){			//判断是否使用四种颜色来染色 
								if(color[i]){
									hasColor.insert(color[i]);
								}
							}
							if(hasColor.size() == 4){
								max_num++;
							}
							lian = false;
						}
						if(lian){
							for(int i=0; i<n; i++){
								if(!color[i]){
									progress_color(i,color,num);
									break; 
								}
							}
						}
						//else{
						//	for(int i=0; i<n; i++){
						//		if(!color[i]){
						//		progress_color(i,color,num);
						//		break; 
						//		}
						//	}
						//}
						num--;
						color[x] = 0;	
					}							
				}
			}																
		}
		void print(){
			for(int i=0; i<n; i++){
				for(int j: link_table[i]){
					cout << j << " ";
				}
				cout << endl;
			}	
		}
};
int main(){
	int n;
	cin >> n;
	Table table(n);
	int temp;
	color = new int[n];
	memset(color,0,sizeof(int)*n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> temp;
			if(temp){
				table.insert(i,j);
			}
		}
	}
	max_num = 0;
	//int num =0;
	//bool flag = false;
	//while(!flag){
		//for(int i=0; i<n; i++){
			//if(!color[i]){
				table.progress_color(0,color,0);
				//break; 
			//}
			//if(i == n-1){
				//flag = true;
			//}
		//}
	//};
	cout << max_num;
	delete[] color;
	return 0;
}
