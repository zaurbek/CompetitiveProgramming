/*
ID: zoollhu1
LANG: C++11
TASK: beads
*/
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	// freopen("beads.in", "r", stdin);
	// freopen("beads.out", "w", stdout);
	int n;
	cin>>n;
	string s;
	cin>>s;
	s += s;
	bool a[n] = {};
	rep(i, 2*n) {
		//left
		int l = i;
		if(i>0) {
			char c = s[i-1];
			while(l--) {
				if(s[l] != c && s[l] != 'w') break;
			}
		}
		//right
	}
}