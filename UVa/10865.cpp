#include <iostream>
using namespace std;

#define repk(i,k,n) for(int i=(k); i<(n); ++i) 
#define rep(i,n) for(int i=0; i<(n); ++i) 
#define repn(i,k,n) for(int i=(k); i<=(n); ++i) 

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	while(cin>>n, n!=0) {
		int k = n/2;
		int a[n][2];
		rep(i, k) cin>>a[i][0]>>a[i][1];
		int x,y;
		cin>>x>>y;
		int tRbL = 0, tLbR = 0;
		rep(i,k) {
			if( (a[i][0]<x&&a[i][1]<y) || (a[i][0]>x&&a[i][1]>y) ) ++tRbL;
			else if( (a[i][0]<x&&a[i][1]>y) || (a[i][0]>x&&a[i][1]<y) ) ++tLbR;	
		}
		repk(i, k+1, n) {
			int q,b;
			cin>>q>>b;
			if( (q<x&&b<y) || (q>x&&b>y) ) ++tRbL;
			else if( (q<x&&b>y) || (q>x&&b<y) ) ++tLbR;	
		}
		cout<<tRbL<<' '<<tLbR<<'\n';
	}
}