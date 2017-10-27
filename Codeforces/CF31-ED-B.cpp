#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<n; ++i)
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n,x;
	cin>>n>>x;
	ll sumX = 0;
	REP(i,n) {
		int c;
		cin>>c;
		sumX+=c;
	}
	if(x-sumX==n-1) cout<<"YES";
	else cout<<"NO";
}