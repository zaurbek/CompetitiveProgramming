#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;

int dp[N][3], x[N], h[N];

int main() {
	// ios_base::sync_with_stdio(0);
	// cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; ++i) scanf("%d %d",&x[i],&h[i]);
	dp[0][0] = 1;
	dp[0][1] = 0;
	if(n==1) dp[0][2] = 1;
	else if(x[0]+h[0]<x[1]) dp[0][2] = 1;
	else dp[0][2] = -1;

	for(int i=1; i<n; ++i) {
		if(x[i]-h[i]>x[i-1]+h[i-1]) dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + 1;
		else if(x[i]-h[i]>x[i-1]) dp[i][0] = max(dp[i-1][0],dp[i-1][1]) + 1;
		else dp[i][0] = -1;

		dp[i][1] = *max_element(dp[i-1],dp[i-1]+3);

		if(i==n-1 || x[i]+h[i]<x[i+1]) dp[i][2] = *max_element(dp[i-1],dp[i-1]+3) + 1;
		else dp[i][2] = -1;
	}

	// for(int i=0; i<n; ++i) for(int j=0; j<3; ++j) {
		// cout<<dp[i][j]<<' ';
		// if(j==2) cout<<'\n';
	// }
	printf("%d",dp[n-1][2]);
}