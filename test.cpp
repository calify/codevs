#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int main(){
	priority_queue<int> q;
	q.push(0);
	q.push(1);
	q.push(2);
	q.push(0);
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	q.pop();
	printf("%d",q.size());
	return 0;
}
