#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

const int nax = 1e5;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

inline int nxt() {
	int x;
	cin>>x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n = nxt();
	vi a(n);
	rep(i,n) {
		a[i] = nxt();
	}

	
}