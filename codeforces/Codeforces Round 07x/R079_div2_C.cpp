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

void solve() {
  string s;
  int n;
  cin >> s >> n;
  n = min(n, (int)s.size());
  map<int, int> m;
  for (char x : s)
    m[x]++;
  vector<pi> v(m.begin(), m.end());
  sort(v.begin(), v.end(), [](pi a, pi b) { return a.S < b.S; });

  set<char> del;
  int r = 0;
  for (auto [x, y] : v) {
    if (y <= n) {
      del.insert(x);
      n -= y;
    } else
      r++;
  }
  cout << r << endl;
  for (char x : s) {
    if (!del.count(x))
      cout << x;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
