#include <bits/stdc++.h>
using namespace std;
typedef pair<long, long> ii;
typedef long long ll;
#define rep(i,n) for(ll i=0; i<(ll)(n); ++i)
#define X first
#define Y second
#define PB push_back

ll gcd(ll a, ll b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

ii simplify(ll a, ll b) {
	ll c = gcd(a,b);
	while(c != 1) {
		a/=c; b/=c;
		c = gcd(a,b);
	}
	return {a,b};
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	ll a,b,c,d;
	cin>>a>>b>>c>>d;

	ii a_b = simplify(a,b);
	ii c_d = simplify(c,d);
	ll r = c_d.Y;
	ll l = a_b.Y;
	ii a_b2 = {a_b.X * r, a_b.Y * r};
	ii c_d2 = {c_d.X * l, c_d.Y * l};
	

	if(a_b2.X < c_d2.X) {
		ll top = a_b.Y * c_d.X - a_b.X * c_d.Y;
		ll bot = a_b.Y * c_d.X;
		ii ans = simplify(top, bot);
		cout<<ans.X<<'/'<<ans.Y;
	} else if(a_b2.X > c_d2.X) {
		ll top = a_b.X*c_d.Y - a_b.Y*c_d.X;
		ll bot = a_b.X * c_d.Y;
		ii ans = simplify(top, bot);
		cout<<ans.X<<'/'<<ans.Y;
	} else cout<<"0/1";

}