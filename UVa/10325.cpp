#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
#define rer(i, q, n) for(int i=(int)(q); i<(int)(n); ++i)

int n, k;

ll gcd (ll a, ll b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

ll lcm (ll a, ll b) {
	return a / gcd (a, b) * b;
}

//2k formula
void solve(ll &rem, vector<int> &g) {	
	int t = (1<<k)-1;
	for(int i=1; i<=t; ++i) {
		ll q = 1;
		int cnt = 0;
		for(int j=0; j<k; ++j) {
			if(i&(1<<j)) {
				++cnt;
				q = lcm(q, g[j]);
			}
		}
		if(cnt%2!=0) rem -= (n/q);
		else rem += (n/q);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	while(cin>>n>>k) {
		vector<int> g;
		rep(i, k) {
			int t;
			cin>>t;
			g.push_back(t);
		}
		ll rem = n;
		solve(rem, g);
		cout<<rem<<'\n';
	}
	
}