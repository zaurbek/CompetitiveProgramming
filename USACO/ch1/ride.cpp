/*
ID: zoollhu1
LANG: C++11
TASK: ride
*/
#include <iostream>
#define rep(i, n) for(int i=0; i<(int)(n); ++i)
using namespace std;

int f(string &x) {
	int res = 1;
	for(int i=0; i<x.size(); ++i) {
		res *= ((x[i]-'A') + 1);
	}
	return res;
}

int main() {
	freopen("ride.in", "r", stdin);
	// freopen("o.txt", "w", stdout);
	freopen("ride.out", "w", stdout);
	string a,b;
	cin>>a>>b;
	if(f(a)%47==f(b)%47) {
		cout<<"GO";
	} else cout<<"STAY";
	cout<<'\n';
}