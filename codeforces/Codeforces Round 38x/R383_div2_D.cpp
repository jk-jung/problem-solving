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

int n, m, w;
vi W, B;
vi v[1005];
bool ck[1005];
vector<pi> cur;
vector<vector<pi>> vv;
int d[1005];

void dfs(int x) {
  ck[x] = 1;
  cur[0].F += W[x];
  cur[0].S += B[x];
  cur.pb({W[x], B[x]});
  for (int y : v[x]) {
    if (ck[y])
      continue;
    dfs(y);
  }
}

void solve() {
  cin >> n >> m >> w;
  W.resize(n);
  B.resize(n);
  for (int &x : W)
    cin >> x;
  for (int &x : B)
    cin >> x;

  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    v[x - 1].pb(y - 1);
    v[y - 1].pb(x - 1);
  }

  for (int i = 0; i < n; i++) {
    if (ck[i])
      continue;
    cur.clear();
    cur.pb({0, 0});
    dfs(i);
    vv.pb(cur);
  }

  int r = 1;
  d[0] = 1;
  for (auto &vt : vv) {
    for (int i = w; i >= 0; i--) {
      for (auto [x, y] : vt) {
        if (i >= x && d[i - x]) {
          d[i] = max(d[i], d[i - x] + y);
          r = max(r, d[i]);
        }
      }
    }
  }
  cout << r - 1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
