#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

ii d[8] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int ki,kj,di,dj,n;
	cin>>ki>>kj>>di>>dj>>n;
	set<ii> k;
	while(n--) {
		int a,b,c;
		cin>>a>>b>>c;
		for(int i=b; i<=c; ++i) k.insert({a,i});
	}
	queue<pair<int, ii>> q;
	set<ii> visited;
	q.push({1, {ki, kj}});
	visited.insert({ki, kj});
	while(!q.empty()) {
		pair<int, ii> s = q.front(); q.pop();
		for(int i=0; i<8; ++i) {
			int dX = d[i].first + s.second.first, dY = d[i].second + s.second.second;
			if(dX==di&&dY==dj) {
				cout<<s.first;
				return 0;
			}
			if(k.count({dX,dY}) && !visited.count({dX,dY})) {
				visited.insert({dX, dY});
				q.push({s.first+1,{dX,dY}});
			}
		}
	}
	cout<<-1;
}