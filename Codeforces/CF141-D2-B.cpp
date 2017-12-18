#include <bits/stdc++.h>
using namespace std;


int main() {
	int a,x,y;
	cin>>a>>x>>y;
	if(y%a==0 || y<0) {cout<<-1; return 0;}
	int lev = y/a;
	if(lev==0||lev%2==1) {
		int bound = (a+1)/2;
		if(-1*bound<x && x<bound) {
			//inside 1
			int cnt = 0, lvl_cnt = 0;
			++lev;
			while(cnt<lev) {
				++cnt;
				++lvl_cnt;
				if(cnt!=1&&cnt%2==1) ++lvl_cnt;
			}
			cout<<lvl_cnt;
		} else cout<<-1;
	} else {
		if(x==0) {cout<<-1; return 0;}
		if( (x>-1*a &&x<0) || (x>0 && x<a)  ) {
			//inside needed
			++lev;
			int cnt = 0, lvl_cnt = 0;
			while(cnt<lev) {
				++cnt;
				++lvl_cnt;
				if(cnt!=1&&cnt%2==1) ++lvl_cnt;
			}
			if(x>0) cout<<lvl_cnt;
			else cout<<lvl_cnt-1;
		} else {cout<<-1;}
	}
}