#include <bits/stdc++.h>
using namespace std;

int gcd (int a, int b) {
	while (b) {
		a %= b;
		swap (a, b);
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n,pX,pY;
	cin>>n>>pX>>pY;
	set<pair<int,int> > se;
	while(n--) {
		int x,y;
		cin>>x>>y;
		int top = pY-y;
		int bot = pX-x;
		int g = gcd(top,bot);
		while(g!=1) {
			top/=g;
			bot/=g;
			g = gcd(top,bot);
		}
		if(bot==0) top = INT_MAX;
		else if(top==0) bot = 0;
		se.insert({top,bot});
	}
	cout<<se.size();
}