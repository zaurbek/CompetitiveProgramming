#include <bits/stdc++.h>
using namespace std;
#define repn(i,n) for(int i=1; i<(int)(n); ++i)
typedef long long ll;


const ll mod = 1e9+7;

ll pow_(int base, int power) {
	ll res = base;
	repn(i, power) {
		res *= base;
		res%=mod;
	}
	return res%mod;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	ll ans = (pow_(3,3*n)-pow_(7,n))%mod;
	if(ans<0) ans += mod;
	cout<<ans;
}