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

int n, m;
vector<pi> v[100005];
vector<pi> t[100005];
ll d[100005];

int find_cost(int cost, int x) {
  int idx = lower_bound(t[x].begin(), t[x].end(), make_pair(cost, cost)) -
            t[x].begin();
  for (int i = max(0, idx - 5); i < min(idx + 5, (int)t[x].size()); i++) {
    if (t[x][i].F <= cost && cost <= t[x][i].S)
      return t[x][i].S + 1;
  }
  return cost;
}

void solve() {
  cin >> n >> m;
  for (int i = 0, x, y, z; i < m; i++) {
    cin >> x >> y >> z;
    v[x].pb({y, z});
    v[y].pb({x, z});
  }

  for (int i = 1, k; i <= n; i++) {
    cin >> k;

    while (k--) {
      int x;
      cin >> x;
      if (t[i].empty() || t[i].back().S + 1 < x) {
        t[i].pb({x, x});
      } else
        t[i].back().S = x;
    }
  }

  priority_queue<pi> pq;
  pq.push({0, 1});
  d[1] = 0;
  memset(d, 63, sizeof(d));
  while (!pq.empty()) {
    auto [cost, x] = pq.top();
    cost = -cost;
    pq.pop();
    if (cost > d[x])
      continue;
    cost = find_cost(cost, x);
    for (auto [y, w] : v[x]) {
      if (cost + w < d[y]) {
        d[y] = cost + w;
        pq.push({-d[y], y});
      }
    }
  }
  if (d[n] == d[0])
    d[n] = -1;
  cout << d[n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
