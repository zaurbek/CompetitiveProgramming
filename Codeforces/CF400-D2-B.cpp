#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n); ++i)
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	char c;
	set<int> se;
	int n,m;
	cin>>n>>m;
	REP(i,n) {
		int go, so;
			REP(j,m) {
			cin>>c;
			if(c=='G') go = j;
			if(c=='S') so = j;
		}
		if(go>so) {
			cout<<-1; return 0;
		}
		se.insert(so-go);
	}
	cout<<se.size();
}