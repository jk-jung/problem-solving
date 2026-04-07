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
  ll m, L = 0, R = 0;
  cin >> m;
  vector<ll> n(m), l(m), r(m), tot(m);
  vector<vector<ll>> a(m);
  vector<map<ll, ll>> c(m);

  map<ll, vi> idx;
  for (int i = 0; i < m; i++) {
    cin >> n[i] >> l[i] >> r[i];
    L += l[i];
    R += r[i];
    a[i].resize(n[i]);
    for (ll &x : a[i])
      cin >> x, idx[x].pb(i);
    for (int j = 0; j < n[i]; j++) {
      ll cnt;
      cin >> cnt;
      c[i][a[i][j]] += cnt;
      tot[i] += cnt;
    }
  }

  for (ll i = L; i <= R; i++) {
    if (!idx.count(i)) {
      cout << 0 << endl;
      return;
    }
  }
  ll rst = 1ll << 60;
  for (auto &[x, y] : idx) {
    if (x < L || x > R)
      continue;
    ll base = R;
    ll need = 0;
    for (int i : y)
      base -= r[i];

    for (int i : y) {
      ll max_cnt = min(tot[i] - c[i][x], r[i]);
      if (max_cnt < l[i]) {
        need += l[i] - max_cnt;
        max_cnt = l[i];
      }
      base += max_cnt;
    }
    if (base <= x)
      need += x - base;
    rst = min(rst, need);
  }
  cout << rst << endl;
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
