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
  int n, m;
  cin >> n >> m;
  vector<vector<pi>> v(n);
  vi s(n);

  vector<vector<ll>> d(n, vector<ll>(1001, 1e18));

  for (int i = 0, x, y, z; i < m; i++) {
    cin >> x >> y >> z;
    x--, y--;
    v[x].pb({y, z});
    v[y].pb({x, z});
  }

  for (int &x : s)
    cin >> x;

  priority_queue<tuple<ll, int, int>> pq;
  pq.push({0, 0, s[0]});
  d[0][s[0]] = 0;

  while (!pq.empty()) {
    auto [cost, i, b] = pq.top();
    cost = -cost;
    pq.pop();
    if (cost > d[i][b])
      continue;
    if (i == n - 1) {
      cout << cost << endl;
      return;
    }

    for (auto [j, w] : v[i]) {
      ll val = cost + w * b;
      ll nb = min(b, s[j]);
      if (val < d[j][nb]) {
        d[j][nb] = val;
        pq.push({-val, j, nb});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
