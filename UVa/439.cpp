#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

const int S = 8; //board

queue<pair<int, ii>> q;
bool visited[S][S] = {};

ii d[8] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};

bool valid(int i, int j) {
	return i>=0&&j>=0&&i<8&&j<8;
}

int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	string s1,s2;
	while(cin>>s1>>s2) {
		int j1 = s1[0]-'a', i1 = s1[1]-'0';
		int j2 = s2[0]-'a', i2 = s2[1]-'0';
		q = {};
		for(int i=0; i<S; ++i) for(int j=0; j<S; ++j) visited[i][j] = false;
		i1 = S - i1; i2 = S - i2;
		if(i1==i2&&j1==j2) {
			cout<<"To get from "<<s1<<" to "<<s2<<" takes 0 knight moves.\n";
			continue;
		}
		int mn = INT_MAX;
		for(int i=0; i<S; ++i) {
			int dI = d[i].first + i1, dJ = d[i].second + j1;
			if(valid(dI, dJ) && !visited[dI][dJ]) {
				visited[dI][dJ] = true;
				q.push({1, {dI, dJ}});
			}
		}
		while(!q.empty()) {
			pair<int, ii> s = q.front(); q.pop();
			//node
			if(s.second.first==i2&&s.second.second==j2) {
				mn = min(mn, s.first);
			} else {
			for(int i=0; i<S; ++i) {
				int dI = d[i].first + s.second.first, dJ = d[i].second + s.second.second;
				if(valid(dI, dJ) && !visited[dI][dJ]) {
					visited[dI][dJ] = true;
					q.push({s.first+1, {dI, dJ}});
				}
			}
			}
		}
		cout<<"To get from "<<s1<<" to "<<s2<<" takes "<<mn<<" knight moves.\n";	
	}
}