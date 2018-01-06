#include <bits/stdc++.h>
using namespace std;
const int nax = 1e5;
int g[nax];

string get_place(const string &a) {
	int c = a.find(',');
	string b = a.substr(c+1, -1);
	b = b.substr(0, b.size()-1);
	return b;
}

string get_n(const string &a) {
	int c = a.find(',');
	return a.substr(1,c-1);
}

bool f(string &a, string &b) {
	string s1 = get_place(a);
	string s2 = get_place(b);
	int size1 = s1.size();
	int size2 = s2.size();
	if(size1==size2) {
		return lexicographical_compare(s1.begin(), s1.end(), s2.begin(), s2.end());
	} else {
		return size1<size2;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);    
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	string s;
	while(cin>>s) {
		map<string, string> mp;
		mp[get_place(s)] = get_n(s);		
		vector<string> vs;
		vs.push_back(s);
		bool go = 0;
		while(cin>>s && s!="()") {
			if(mp.find(get_place(s))!=mp.end()) {
				go = 1;
			}
			vs.push_back(s);
			mp[get_place(s)] = get_n(s);
		}
		if(go) {
			cout<<"not complete\n";
			continue;
		} else {
			for(int i=0; i<vs.size(); ++i) {
				string to = get_place(vs[i]);
				while(to.size()>0) {
					to = to.substr(0, to.size()-1);
					if(mp.find(to)==mp.end()) {
						cout<<"not complete\n";
						go = 1;
						break;
					}
				}
				if(go) break;
			}
			if(go) continue;
			sort(vs.begin(), vs.end(), f);
			for(int i=0; i<vs.size(); ++i) {
				if(i) cout<<' ';
				cout<<get_n(vs[i]);
			}
			cout<<'\n';
		}
	}	
}