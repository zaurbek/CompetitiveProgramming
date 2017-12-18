#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(int)(n); ++i)

int main() {
	int n,k,l,r,s_all, s_k;
	cin>>n>>k>>l>>r>>s_all>>s_k;
	int s_all_k = s_all-s_k;
	int low = n - k ;
	vector<int> v1, v2;
	rep(i, low) v1.push_back(l);
	int sum_low = l*low;
	int maxi = l;
	int cnt = 0;
	while(sum_low<s_all_k) {
		if(cnt==low) cnt=0;
		++v1[cnt++];
		maxi = max(v1[cnt-1],maxi );
		++sum_low;
	}
	if(low!=0) rep(i, k) v2.push_back(maxi);
	else rep(i, n) v2.push_back(l);
	int sum_top=  maxi*k;
	cnt = 0;
	while(sum_top<s_k) {
		if(cnt==k) cnt=0;
		++v2[cnt++];
		++sum_top;
	}
	rep(i,v2.size() ) cout<<v2[i]<<' ';
	rep(i,v1.size() ) cout<<v1[i]<<' ';
}