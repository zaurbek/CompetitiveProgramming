#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef long long ll;
typedef pair<ll,ll> pll;

pll lastL = {0,1}, lastR = {1,0};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	ll a,b;
	while(cin>>a>>b) {
		if(a==1&&b==1) break;
		string str = "";
		pll cur = {1,1}, tar = {a,b};
		lastL = {0,1}, lastR = {1,0};
		while(cur!=tar) {
			bool to_left = (cur.X*tar.Y) > (cur.Y*tar.X);
			pll temp = cur;
			if(to_left) {
				str+="L";
				cur.X += lastL.X;
				cur.Y += lastL.Y;
				lastR = temp;
			} else {
				str+="R";
				cur.X += lastR.X;
				cur.Y += lastR.Y;
				lastL = temp;
			}
		}
		cout<<str<<'\n';
	}
}