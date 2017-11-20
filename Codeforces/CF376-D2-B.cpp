#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define X first
#define Y second
typedef pair<int,int> ii;

ii ar[110];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n, m;
	cin>>n>>m;
	int sum = 0;
	while(m--) {
		int a,b,c;
		cin>>a>>b>>c;
		sum+=c;
		ar[a].X += c;
		ar[b].Y += c;
	}
	rep(i, n+1)	sum-= (ar[i].X+ar[i].Y-abs(ar[i].X-ar[i].Y))/2;
	cout<<sum;
}