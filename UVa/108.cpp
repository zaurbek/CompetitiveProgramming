#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i) 
#define repi(i, l, n) for(int i=(l); i<(int)(n); ++i)

const int maxn = 101;

long long a[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	while(cin>>n) {
		rep(i,n) rep(j,n) {
			cin>>a[i][j];
			if(j) a[i][j]+=a[i][j-1];
		}
		int max_s = -127*100*100;
		rep(l,n) repi(r,l,n) {
			int sub = 0;
			rep(row,n) {
				sub+=a[row][r];
				if(l) sub-=a[row][l-1];
				max_s = max(max_s, sub);
				if(sub<0) sub= 0;
			}
		}
		cout<<max_s<<'\n';
	}
}