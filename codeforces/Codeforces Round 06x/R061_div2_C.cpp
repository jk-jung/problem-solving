#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

map<string, set<string>> dirs;
map<string, int> files;

int r1 = 0, r2 = 0;
void parse(string s) {
  string cur;
  string root;
  int i = 0;
  for (i = 0; i < s.size(); i++) {
    cur += s[i];
    if (s[i] == '\\' and s[i - 1] != ':')
      break;
  }
  root = cur;
  r1 = max(r1, ++files[root]);

  for (i = i + 1; i < s.size(); i++) {
    cur += s[i];
    if (s[i] == '\\')
      dirs[root].insert(cur);
  }
  r2 = max(r2, (int)dirs[root].size());
}

void solve() {
  string s;
  while (cin >> s) {
    parse(s);
  }
  cout << r2 << " " << r1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
