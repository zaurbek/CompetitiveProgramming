#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 30001;

double EPS = 1e-9;
long long dp[11][maxn];
int n = 11, coin[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};

long long ways(int type, int totalV) {
	if(totalV ==0) return 1;
	if(totalV<0) return 0;
	if(type==n) return 0;
	if(dp[type][totalV] != -1) return dp[type][totalV];
	return dp[type][totalV] = ways(type+1, totalV) + ways(type, totalV - coin[type]);
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	double tc;
	memset(dp, -1, sizeof dp);
	int cnt = 0;
	while(cin>>tc && tc>EPS) {
		int g = (int)(tc*100+0.5);
		printf("%6.2f%17lld",tc,ways(0, g));
		if(cnt++) printf("\n");
	}
}