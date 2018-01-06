#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	long long n,b,c;
	cin>>n>>b>>c;
	long long a[n];
	for(long long i=0; i<n; ++i) cin>>a[i];
	for(long long i=0; i<n; ++i) {
		long long full = (a[i]*b)/c;
		long long mini = ceil((full*c)/(double)b);
		if(i) cout<<' ';
		cout<<a[i]-mini;
	}
}