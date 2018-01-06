#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n; cin>>n;
	int a[n];
	int beg = 0, last_unique = 0;
	int last = -1;
	pair<int,int> cur_par = {a[0], 0};
	int ans = -1;
	rep(i,n) {
		cin>>a[i];
		
		if(a[i] == cur_par.first || a[i] == cur_par.second) {
			if(a[i] != cur_par.first && cur_par.second == 0)
				cur_par.second = a[i];

			if(i && a[i]!=a[i-1]) {
				last_unique = i;
				last = a[i];
			}
		} else if (cur_par.second == 0) {
			last = a[i];
			last_unique = i;
			cur_par.second = a[i];
		} else 	{
			int res = i - beg;
			ans = max(res, ans);
			if(cur_par.first == last) 
				cur_par.second = a[i];
			else 
				cur_par.first = a[i];

			beg = last_unique;
			last_unique = i;
			last = a[i];
		}
	}
	ans = max(n - beg, ans);
	cout<<ans;
}