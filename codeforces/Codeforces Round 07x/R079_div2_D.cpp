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

ll mod = 1000000007;

bool sf(pi &a, pi &b) {
  if (b.S == a.S)
    return a.F < b.F;
  return a.S < b.S;
}

map<ll, ll> d, s;

ll get_count(ll x, ll y) {
  auto a = s.lower_bound(x);
  auto e = s.upper_bound(y);
  a--;
  e--;

  return (e->S - a->S + mod) % mod;
}
void solve() {
  int n, m;
  cin >> n >> m;
  vector<pi> v(m);
  for (auto &[x, y] : v)
    cin >> x >> y;
  sort(v.begin(), v.end(), sf);

  s[-1] = 0;
  s[0] = 1;
  d[0] = 1;
  for (auto [x, y] : v) {
    ll cnt = get_count(x, y - 1);

    d[y] = (d[y] + cnt) % mod;
    if (!s.count(y))
      s[y] = s.rbegin()->second;
    s[y] = (s[y] + cnt) % mod;
  }
  cout << d[n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
