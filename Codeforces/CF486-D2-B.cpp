#include <bits/stdc++.h>
using namespace std;
typedef pair<bool, bool> bb;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
const int nax = 1e2 +7;

int g[nax][nax];
bb qq[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int m,n;
	cin>>m>>n;
	int cnt = 0;
	rep(i,m) {
		bool all = 1;
		rep(j,n){ 
			int t;
			cin>>t;
			g[i][j] = t;
			if(t==0) all = 0;
		}
		// {x, y} = {all are 1s horizontally, all are 1s vertically}
		if(all) ++cnt;
		qq[i].first = all;
	}
	rep(j,n) {
		bool all = 1;
		rep(i,m) { 
			if(g[i][j]==0) all = 0;
		}
		// {x, y} = {all are 1s horizontally, all are 1s vertically}
		if(all) ++cnt;
		qq[j].second = all;
	}

	int res[m][n] = {};
	rep(i,m) rep(j,n) {
		if(g[i][j]==1) {
			bool flag1, flag2;
			flag1 = qq[i].first; //are all horizontal 1
			flag2 = qq[j].second; //are all vertical 1
			if(flag1 && flag2) {
				res[i][j] = 1;
				cnt-=2;
			}
			else if(!flag1 && !flag2) {
				cout<<"NO"; return 0;
			} 			
		}				
	}		
	if(cnt>0) {
		cout<<"NO"; return 0;	
	}
	cout<<"YES\n";
	rep(i,m) {
		rep(j,n) {
			if(j) cout<<' ';
			cout<<res[i][j];
		}
		cout<<'\n';
	}
}