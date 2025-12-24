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

map<int, int> st;
void add(int x) {
  if (x < 0) {
    if (--st[-x] == 0)
      st.erase(-x);
  } else {
    st[x]++;
  }
}

int get() {
  if (st.empty())
    return 0;
  return st.rbegin()->F;
}
void solve() {
  int n;
  cin >> n;

  vector<pi> v;
  for (int i = 0, h, x, y; i < n; i++) {
    cin >> h >> x >> y;
    v.pb({x, h});
    v.pb({y, -h});
  }
  sort(v.begin(), v.end());

  vector<pi> r;

  int m = v.size();
  for (int i = 0; i < m;) {
    int x = v[i].F;
    while (i < m && v[i].F == x) {
      add(v[i++].S);
    }
    int y = get();
    if (r.empty() || r.back().S != y)
      r.pb({x, y});
  }

  cout << r.size() * 2 << endl;
  int z = 0;
  for (auto [x, y] : r) {
    cout << x << " " << z << endl;
    cout << x << " " << y << endl;
    z = y;
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
