#include <bits/stdc++.h>
using namespace std;
int top_zero = INT_MAX;

bool f(const pair<int,string> &a, const pair<int,string> &b) {
	if(a.first>0) top_zero = min(a.first, top_zero);
	if(b.first>0) top_zero = min(b.first, top_zero);
	if(a.first==b.first) {
		int res = a.second.compare(b.second);
		if(res<0) {
			return true;
		} else {
			return false;
		}
	}
	return a.first>b.first;
}
 
vector<pair<int, string>> pQ;
 
struct Node {
	string name;
	Node *parent;
	vector<Node*> kids;
	Node(const string &s, Node *ptr) {
		name = s;
		parent = ptr;
	}
};
 
 
int nth_kids(Node *ptr, int d) {
	int sum = 0;
	queue<pair<int, Node*>> q;
	q.push({0,ptr});
	bool go = false;
	while(!q.empty()) {
		pair<int,Node*> s = q.front(); q.pop();
		for(int i=0; i<s.second->kids.size(); ++i) {
			if(s.first+1==d) ++sum;
			if(s.first+1>d) {
				go = true;
				break;
			}
			q.push({s.first+1, s.second->kids[i]});
		}
		if(go) break;
	}
	return sum;
}
 
 
void all(Node *ptr, int d) {
	for(auto it: ptr->kids) {
		all(it, d);
	}
	int res = nth_kids(ptr, d);
	pQ.push_back({res, ptr->name});
}
 
Node *check(Node *ptr, const string &s) {
	if(ptr->name == s) return ptr;
	else {
		for(auto it = ptr->kids.begin(); it!=ptr->kids.end(); ++it) {
			Node *res = check((*it), s);
			if(res != nullptr) {
				return res;
			}
		}
		return nullptr;
	}
}
 
int main() {
	#ifndef ONLINE_JUDGE
	freopen("i.txt", "r", stdin);
	freopen("o.txt", "w", stdout);
	#endif
	int n;
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int cnt = 0;
	while(n--) {
		int a,b;
		cin>>a>>b;
		vector<Node *> qwe;
		while(a--) {
			string s1,tempS;
			int c;
			cin>>s1>>c;
			Node *newParent = new Node(s1, nullptr);
			vector<Node *> tempKids;
			while(c--) {
				cin>>tempS;
				Node *newNode = new Node(tempS, newParent);
				tempKids.push_back(newNode);
			}
			newParent->kids = tempKids;
			qwe.push_back(newParent);
		}
		while(qwe.size()!=1) {
			for(int i=0; i<qwe.size(); ++i) {
				for(int j=0; j<qwe.size(); ++j) {
					if(qwe[i]->name!=qwe[j]->name) {
						Node *res = check(qwe[j],qwe[i]->name);
						if(res != nullptr) {
							res->kids.insert(res->kids.begin(), qwe[i]->kids.begin(), qwe[i]->kids.end());
							qwe.erase(qwe.begin()+i);
							if(i) --i;
							break;
						}
					}
				}
			}
		}
		cout<<"Tree "<<++cnt<<":\n";
		top_zero=INT_MAX;
	  	pQ.clear();
		all(qwe[0], b);
		sort(pQ.begin(), pQ.end(), f);
		int change = 0;
		bool go = false;
		for(int i=0; i<pQ.size(); ++i) {
			if(pQ[i].first==0) break;
			if(i && pQ[i].first!=pQ[i-1].first) ++change;
			if(i<3&&change<=2&&pQ[i].first==top_zero) {
		    	cout<<pQ[i].second<<' '<<pQ[i].first<<'\n';
		    	go = true;
		    	continue;
		  	}
		  	if(go&&change<=2&&pQ[i].first==top_zero) {
		    	cout<<pQ[i].second<<' '<<pQ[i].first<<'\n';
		    	continue;
		  	}
			if(i && pQ[i].first!=pQ[i-1].first && i == 3 ) break;
			if(change==3) break;
			cout<<pQ[i].second<<' '<<pQ[i].first<<'\n';
		}
		cout<<'\n';
	}
}
