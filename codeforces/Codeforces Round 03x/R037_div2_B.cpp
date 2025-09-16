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
  int n, m, k;
  cin >> n >> m >> k;
  vector<pi> v(n), r;
  for (auto &[x, y] : v)
    cin >> x >> y;

  vi used(n);
  int cur = m, t = 0, damage = 0;

  while (cur > 0) {
    int best = -1;
    cur -= damage;
    cur = min(m, cur + k);
    if (cur <= 0)
      break;

    for (int i = 0; i < n; i++) {
      if (used[i])
        continue;
      if (cur * 100 > v[i].F * m)
        continue;
      if (best == -1 || v[i].S > v[best].S)
        best = i;
    }
    if (best == -1 && damage <= k) {
      cout << "NO\n";
      return;
    } else if (best != -1) {
      used[best] = 1;
      damage += v[best].S;
      r.pb({t, best + 1});
    }

    t++;
  }
  cout << "YES\n";
  cout << t << " " << r.size() << endl;
  for (auto [x, y] : r)
    cout << x << " " << y << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
