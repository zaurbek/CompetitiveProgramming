#include <bits/stdc++.h>
using namespace std;

long long n,m, x,y,c;

long long step (long long a, long long b) {
	long long shagA, shagB;
	if(a<0) shagA = (x-1)/abs(a);
	else if(a>0) shagA = (n-x)/a;
	if(b<0) shagB = (y-1)/abs(b);
	else if(b>0) shagB = (m-y)/b;

	if(a==0) return shagB;
	else if(b==0) return shagA;
	else if(shagA>shagB) return shagB;
	else return shagA;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	long long ans = 0;
	cin>>n>>m;
	cin>>x>>y>>c;
	while(c--) {
		long long a,b, res;
		cin>>a>>b;
		res = step(a,b);
		x += res*a;
		y += res*b;
		ans+=res;
	}	
	cout<<ans;
}