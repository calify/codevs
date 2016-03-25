#include<cstdio>
using namespace std;
int powermod(int a, int b, int c){
	int ans = 1;
	a = a % c;
	while(b>0){
		if(b%2 == 1)
		ans = (ans*a)%c;
		b /= 2;
		a = (a*a)%c;
	}
	return ans;
}
int main(){
	int b,c;
	scanf("%d%d",&b,&c);
	printf("%d",powermod(2,b,c));
	return 0;
}
