#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int N = 5e4+7;

int g[N];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin>>n;
	while(n--) {
		int a;
		cin>>a;
		++g[a];
	}
	int mini = INT_MAX;
	rep(i, N) {
		if(g[i]==0) continue;
		int cnt = 0;
		rep(j, N) {
			if(j<i || j>2*i) {
				cnt+=g[j];
			}
		}
		mini = min(cnt, mini);
	}
	cout<<mini;
}