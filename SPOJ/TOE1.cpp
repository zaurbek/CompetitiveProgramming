#include <bits/stdc++.h>
using namespace std;
#define FOR(i) for(int i=0; i<3; ++i)
#define x first
#define y second
typedef vector<int> vi;
typedef vector<vi> vvi;
bool no_turns(const vvi &a) {
	FOR(i) {
		int sum = 0;
		FOR(j) {
			sum+=a[i][j];
		}
		if(sum==3||sum==-3) return 1;
	}
	FOR(j) {
		int sum = 0;
		FOR(i) {
			sum+=a[i][j];
		}
		if(sum==3||sum==-3) return 1;
	}
	int sum = 0;
	FOR(i) FOR(j) {
		if(i==j) sum+=a[i][j];
	}
	if(sum==3||sum==-3) return 1;
	sum=0;
	FOR(i) FOR(j) {
		if(i==2-j) sum+=a[i][2-j];
	}
	if(sum==3||sum==-3) return 1;
	return 0;
}

string glue(const vvi &a) {
	string str = "";
	FOR(i) FOR(j) {
		str+=to_string(a[i][j]);
	}
	return str;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif	
	int n; cin>>n;
	while(n--) {
		vvi asd;
		FOR(i) FOR(j) {
			char c;
			cin>>c;
			if(c=='X') asd[i][j]=1;
			else if (c=='O') asd[i][j]=-1;
			else asd[i][j] = 0;
		}
		string res = glue(asd);
		set<vvi> visited;
		queue<pair<int, vvi>> q;
		vvi qwe = {{0,0,0},{0,0,0},{0,0,0}};
		FOR(i) FOR(j) {
			qwe[i][j] = 1;
			q.push({1,qwe});
			visited.insert(qwe);
			qwe[i][j] = 0;
		}
		bool ans = 0;
		while(!q.empty()) {
			pair<int, vvi> s = q.front(); q.pop();
			if(res == glue(s.y)) {
				ans = 1;
				break;
			}
			FOR(i) FOR(j) if(s.y[i][j]==0) {
				if(!visited.count(s.y)) {
					if(!no_turns(s.y)) q.push({1^s.x, s.y});
					visited.insert(s.y);
				}
			}
		}
		cout<<(ans?"yes\n":"no\n");
	}
}