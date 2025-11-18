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

int n;
vi v[222];

pi dfs(int x, int y = -1) {
  vi t;
  int r0 = 0, r1 = 0;
  for (int z : v[x]) {
    if (z == y)
      continue;
    auto [best, dep] = dfs(z, x);
    r0 = max(r0, best);
    r1 = max(r1, dep + 1);
    t.pb(dep + 1);
  }
  sort(t.rbegin(), t.rend());
  if (t.size() >= 2)
    r0 = max(r0, t[0] + t[1]);
  return mp(max(r0, r1), r1);
}

void solve() {
  int n;
  cin >> n;
  vector<pi> t;
  for (int i = 1, x, y; i < n; i++) {
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);

    t.pb({x, y});
  }
  int r = 0;

  for (auto [x, y] : t)
    r = max(r, dfs(x, y).F * dfs(y, x).F);
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
