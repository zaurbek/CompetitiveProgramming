#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	char c = getchar();
	deque<int> g;
	int cnt = 1;
	while(c!=EOF && c!='\n') {
		if(c=='l') g.push_back(cnt++);
		else g.push_front(cnt++);
		c=getchar();
	}
	for(auto it = g.begin(); it!=g.end(); ++it) cout<<*it<<'\n';
}
