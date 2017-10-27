#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(int)(n); ++i)

const int maxn = 100;

int dp[maxn][3]= {};
int a[maxn] = {};

int calc_max(int i, int id) {
	if(id==0) 
		return max(max(dp[i-1][0],dp[i-1][1]),dp[i-1][2]);
	else if (id==1) 
		return max(dp[i-1][0],dp[i-1][2]);
	else 
		return max(dp[i-1][0],dp[i-1][1]);
}

int solve(int i, int n) {
	dp[i][0] = calc_max(i, 0);
	if(a[i]==1||a[i]==3) 
		dp[i][1] = 1+calc_max(i, 1);
	if(a[i]==2||a[i]==3) 
		dp[i][2] = 1+calc_max(i, 2);
	if(i==n) 
		return n-calc_max(i, 0);
	return solve(i+1, n);
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
	REP(i, n) cin>>a[i];
	if(a[0]==1||a[0]==3) dp[0][1] = 1;
	if(a[0]==2||a[0]==3) dp[0][2] = 1;
	cout<<solve(1, n);
}