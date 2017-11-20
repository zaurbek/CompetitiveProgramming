#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif

	int n,k, x, minx = INT_MAX;
	scanf("%d %d",&n,&k);
	long long sum = 0;
	rep(i,n) {
		scanf("%d",&x);
		minx = min(minx, abs(x));
		if(k) {
			if(x<0) {
				x=-1*x;
				--k;
			} else if (x>=0) {
				if(k%2) {
					sum-=2*minx;
					k=0;
				}
			}
		}
		sum+=x;
	}
	if(k%2) sum-=2*minx;
	cout<<sum;
}