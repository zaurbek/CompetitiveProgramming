#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
#define X first
#define Y second
const int nax = 1e5+107;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
typedef long long ll;

bool f(ii &a, ii &b) {
	return a.X < b.X;
}

inline int read() {
    int ret=0,c,f=1;
    for(c=getchar(); !(isdigit(c)||c=='-'); c=getchar());
    if(c=='-') f=-1,c=getchar();
    for(; isdigit(c); c=getchar()) ret=ret*10+c-'0';
    if(f<0) ret=-ret;
    return ret;
}

int main() {
	int n = read(), d = read();
	vector<ii> a(n);
	rep(i,n) {
		int m = read(), f = read();
		a[i] = {m,f};
	} 
	sort(a.begin(), a.end(), f);
	ll sum = 0;
	ll maxi = 0;
	int q = a.size();
	int j = 0;
	rep(i,q) {
		sum += a[i].Y;
		if(a[i].X - a[j].X >= d) {
			while(a[i].X-a[j].X >=d) {
				sum-=a[j].Y;
				++j;
			}
		}
		if(sum > maxi) maxi = sum;
	}
	cout<<maxi;
}