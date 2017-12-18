#include <bits/stdc++.h>
using namespace std;
string s;

bool is_valid(int i) {
  set<char> se;
  int q = 0;
  for(int j=0; j<26; ++j) {
    if(s[i+j]=='?') ++q;
    else se.insert(s[i+j]);
  }
  if(se.size()+q==26) {
    queue<char> q;
    for(char a='A'; a<='Z'; ++a) {
      if(!se.count(a)) {
        q.push(a);
      }
    }
    for(int j=0; j<26; ++j) {
      if(s[i+j]=='?') {
        s[i+j]=q.front(); q.pop();
      }
    }
    return true;
  }
  return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	for(int i=0; i<(int)s.size()-25; ++i) {
		if(is_valid(i)) {
		  for(int j=0; j<s.size(); ++j) {
		    if(s[j]=='?') cout<<'A';
		    else cout<<s[j];
		  }
		  return 0;
		}
	}
	cout<<-1;
}