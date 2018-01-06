#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef vector<int> vi;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define X first
#define Y second
#define PB push_back

const int nax = 2e5+7;

ii f[nax];
ii f2[nax];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	string s1, s2;
	cin>>s1>>s2;
	ii cnt = {0,0};
	
	int m = s2.size();
	int s = s1.size();
	rep(i, s) {
		if(s1[i]=='0') ++cnt.X;
		else ++cnt.Y;

		f[i] = cnt;
	}
	cnt={0,0};
	ll ans = 0;
	rep(i, m) {
		ii q;
		int t = i-m+s-1;
		if(i<s-1) {
			if(t<0)
				q = f[i];
			else 
				q = {f[i].X - f[t].X, f[i].Y - f[t].Y}; 
		} else if(i>m-s) {
			if(t<0)
				q = f[s-1];
			else
				q = {f[s-1].X - f[t].X, f[s-1].Y - f[t].Y};
		} else {
			q = f[s-1];
		}
		int q2 = s2[i] - '0';
		if(q2==0) {
			ans += q.Y;
		} else {
			ans += q.X;
		}
	}
	cout<<ans;
}