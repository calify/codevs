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
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	//2^10 mod 9=7
	printf("%d^%d mod %d=%d",a,b,c,powermod(a,b,c));
	return 0;
}
