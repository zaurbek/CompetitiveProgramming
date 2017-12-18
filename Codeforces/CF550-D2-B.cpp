#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define rep(i,n) for(long long i=0; i<(long long)(n); ++i)
#define repi(i, k, n) for(long long i=(long long)(k); i<(long long)(n); ++i)

bool at_position(long long num,long long pos)
{
	return num &= (1<<pos);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	long long n,l,r,x;
	cin>>n>>l>>r>>x;
	vector<long long> v;
	while(n--) {
		long long a; cin>>a;
		v.PB(a);
	}
	sort(v.begin(), v.end());
	long long m = -1;
	long long cnt = 0;
	rep(i,v.size()) {
		m = -1;
		repi(j, i+1, v.size())
			if(v[j]-v[i]>=x) {
				m=j;
				break;
			}
		if(m==-1) continue;
		long long size = 1<<((long long)v.size()-i-1);
		long long init = 1<<(m-i-1);
		for(long long j=init; j<size; ++j) {
			long long sum = v[i];
			rep(k, 20) {
				if( at_position(j, k)) {
					assert(i+k+1 < (long long)v.size());
					sum+=v[i+k+1];
				}
			}
			if((long long)l<=sum && sum<=(long long)r) ++cnt;
		}
	}
	cout<<cnt;
}