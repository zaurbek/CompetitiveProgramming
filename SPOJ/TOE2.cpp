#include <iostream>
#include <cmath>
//use c++14 on web
using namespace std;
#define FOR(i) for(int i=0; i<3; ++i)
char s[3][3];
 
bool perp(char w) {
  FOR(i) {
    bool fl = true;
    FOR(j) {
      if(s[i][j]!=w) fl = false;
    }
    if(fl) return fl;
  }
  FOR(i) {
    bool fl = true;
    FOR(j) {
      if(s[j][i]!=w) fl = false;
    }
    if(fl) return fl;
  }
  return false;
}

bool d(char w) {
  bool fl = 1;
  FOR(i) if(s[i][i]!=w) fl = 0;
  if(fl) return fl;
  fl = 1;
  FOR(i) if(s[i][2-i]!=w) fl = 0;
  return fl;
}
 
bool win(char w) {
  return d(w)||perp(w);
}
 
int cnt(char w) {
  int res = 0;
  FOR(i) FOR(j) if(s[i][j]==w) ++res;
  return res;
}
int main() {
  #ifndef ONLINE_JUDGE
  freopen("i.txt", "r", stdin);
  freopen("o.txt", "w", stdout);
  #endif
  string str;
  while(cin>>str&&str!="end") {
    
    s[0][0] = str[0];
    s[0][1] = str[1];
    s[0][2] = str[2];
    s[1][0] = str[3];
    s[1][1] = str[4];
    s[1][2] = str[5];
    s[2][0] = str[6];
    s[2][1] = str[7];
    s[2][2] = str[8];

    int X = cnt('X'), O = cnt('O'), tch = cnt('.');
    bool winX = win('X'), winO = win('O');
    if(winX && X==O+1 && !winO) {
      cout<<"valid\n";
    } else if (winO && !winX && O == X) {
      cout<<"valid\n";  
    } else if (!winO && !winX && O+X==9 && X>O) {
      cout<<"valid\n";
    } else {
      cout<<"invalid\n"; 
    }
  }
}