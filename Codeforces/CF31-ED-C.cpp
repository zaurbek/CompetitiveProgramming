#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef long long ll;
#define F first
#define S second
const int maxn = 100000;

bool visited[maxn+1]={};
int g[maxn+1]={};
int gB[maxn+1]={};
bool row = false;

pair<ii, int> graph(int i) {
	int length = 1;
	int init = i;
	int end = i;
	visited[i] = true;
	i = g[i];
	while(!visited[i]) {
		visited[i] = true;
		i = g[i];
		++length;
	}
	if(i==g[i]) {
		init = i;
		i = gB[i];
		while(!visited[i]) {
			visited[i] = true;
			i=gB[i];
			++length;
		}
		end = i;
		row = true;
	} else {
		end = gB[i];
	}
	return {{init, end},length};
}

bool f(const pair<ii,int> &a, const pair<ii,int> &b) {
	return a.S>b.S;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	cin>>n;
	REP(i,n) {
		int a;
		cin>>a;
		g[i+1]=a;
		gB[a]=i+1;
	};
	vector<pair<ii,int>> v2;
	REP(i,n) {
		int localI = i+1;
		pair<ii, int> v1;
		if(!visited[localI]) {
			v1 = graph(localI);
		}
		v2.push_back(v1);
	}
	sort(v2.begin(), v2.end(), f);
	ll sum = 0;
	if(v2.size()>=2) {
		ll res = (v2[0].S+v2[1].S);
		sum+= res*res;
		REP(i, v2.size()) {
			if(i>1) {
				sum+=v2[i].S*v2[i].S;
			}	
		}
	} else {
		if(row) sum+= (v2.size()*(v2.size()) )/2;
		else sum+= v2[0].S*v2[0].S;
	}
	cout<<sum;
}