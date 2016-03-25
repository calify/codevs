#include<iostream>
using namespace std;
int main(){
	int n;
	int *p;
	cin >> n;
	p = new int[n];
	int temp;
	int total=0,average,ans=0;
	for(int i=0; i<n; i++){
		cin >> temp;
		p[i] = temp;
		total += temp;
	}
	average = total / n;
	for(int i=0; i<n; i++){
		if(p[i]<average){
			p[i+1] -= average - p[i];
			p[i] = average;
			ans++;
		}
		else if(p[i]>average){
			p[i+1] += p[i] - average;
			p[i] = average;
			ans++;
		}
	}
	cout << ans;
	delete[] p;
	return 0;
}
