#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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

ll s1, e1, s2, e2, k;

ll calc(ll a, ll b, ll c, ll d) {
  ll r = 0;
  // a < s <= b
  // c <= e < d

  // Case 1: s from 1
  ll s3 = min(e1, b) - max(a + 1, s1) + 1;
  ll e3 = min(e2, d - 1) - max(c, s2) + 1;
  if (s3 > 0 && e3 > 0)
    r += s3 * e3;

  // Case 2: s from 2
  ll s4 = min(e2, b) - max(a + 1, s2) + 1;
  ll e4 = min(e1, d - 1) - max(c, s1) + 1;
  if (s4 > 0 && e4 > 0) {
    r += s4 * e4;
    if (b == c)
      r--;
  }

  return r;
}
void solve() {
  cin >> s1 >> e1 >> s2 >> e2 >> k;

  vector<ll> v;
  ll cnt = 0;
  v.pb(1);
  for (ll len = 0; len <= 10; len++) {
    for (ll i = 0; i < (1 << len); i++) {
      ll t = 0;
      for (ll j = 0, b = 1; j < len; j++, b *= 10) {
        t += ((i >> j & 1) ? 7 : 4) * b;
      }
      v.pb(t);
    }
  }

  for (int i = 1; i < v.size() - k - 2; i++) {
    cnt += calc(v[i - 1], v[i], v[i + k - 1], v[i + k]);
  }
  ll tot = (e1 - s1 + 1) * (e2 - s2 + 1);
  cout << fixed << setprecision(10) << (double)cnt / tot << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
