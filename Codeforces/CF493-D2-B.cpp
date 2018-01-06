#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define X first
#define Y second
#define PB push_back
const int nax = 2e5 + 107;

ll mini(ll a, ll b) {
	if(a < b) return a;
	else return b;
}

ii g[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	ll n;
	cin>>n;
	ll last = 0;
	ll lexico = 0;
	ll cnt_a = 0, cnt_b =0;
	ll ttl_a = 0, ttl_b =0;
	while(n--) {
		ll x;
		cin>>x;
		if(x>0) {
			ttl_a += x;
			last = 1;
			++cnt_a;
			g[cnt_a].first = x;
		} else {
			x = -1*x;
			ttl_b += x;
			last = 2;
			++cnt_b;
			g[cnt_b].second = x;
		}

		if(lexico == 0 && cnt_a>0 && cnt_b > 0) {
			ll res = mini(cnt_a, cnt_b);
			if( g[res].first != 0 && g[res].second != 0) {
				if(g[res].first > g[res].second) lexico = 1;
				else if (g[res].first < g[res].second) lexico = 2;
			}	
		}
	}

	if(ttl_a > ttl_b) {
		cout<<"first";
	} else if(ttl_a < ttl_b) {
		cout<<"second";
	} else {
		if(lexico == 1) {
			cout<<"first";
		} else if(lexico == 2) {
			cout<<"second";
		} else {
			if(last==1) cout<<"first";
			else if(last==2) cout<<"second";
		}
	}
}