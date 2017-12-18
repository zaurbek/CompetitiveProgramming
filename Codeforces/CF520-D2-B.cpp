#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+7;

bool visited[N];

int solve(int n, int m) {
	queue<pair<int,int>> q;
	q.push({n,0});
	while(!q.empty()) {
		pair<int,int> s = q.front(); q.pop();
		if(visited[s.first]) continue;
		visited[s.first] = true;
		if(s.first==m) return s.second;	
		if(s.first==1) q.push({2,s.second+1});
		else if(s.first*2>10000) q.push({s.first-1,s.second+1});
		else {
			q.push({s.first*2,s.second+1});
			q.push({s.first-1,s.second+1});
		}
	}
}



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n,m;
	cin>>n>>m;
	int res = solve(n,m);
	cout<<res;
}