#include <bits/stdc++.h>
using namespace std;

const int maxn = 20005;

int a[maxn];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, cnt = 0;
	cin>>n;
	while(n--) {
		int n2;
		cin>>n2;
		--n2;
		for(int i=0; i<n2; ++i) cin>>a[i];
		int ml = 0, mr = 0, l = 0, r = 0, ans = 0, sum = 0;
		for(int i=0; i<n2; ++i) {
			sum += a[i];
			if(sum>=ans) {
				r = i + 1;
				int length = mr - ml;	
				if(sum> ans || (sum == ans && r - l > length) || (sum == ans && r - l == length && l < ml)) {
					mr = i + 2;
					ml = l + 1;
				}
				ans = sum;
			}
			if(sum<0) {
				sum = 0;
				l = i + 1;
			}
		}
		if(ans>0) cout<<"The nicest part of route "<<++cnt<<" is between stops "<<ml<<" and "<<mr<<"\n";
		else cout<<"Route "<<++cnt<<" has no nice parts\n";
	}
}