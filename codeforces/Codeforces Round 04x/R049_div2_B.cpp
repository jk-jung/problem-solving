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
typedef pair<ll, ll> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

void check(pi &a, pi b) {
  ll sa = a.F * a.S;
  ll sb = b.F * b.S;
  if (sa == sb) {
    a = max(a, b);
  } else if (sa < sb) {
    a = b;
  }
}

void solve() {
  ll h, w;
  cin >> h >> w;

  pi r;

  // 8/10 <= h/w <= 125/100

  // 10/8 >= w/h >= 100/125
  // 100/125 <= w/h <= 10/8
  // h100/125 <= w <= h10/8
  for (ll i = 1; i <= h; i *= 2) {
    ll s = (i * 100 + 124) / 125;
    ll e = i * 10 / 8;

    ll w2 = min(w, e);
    cout << " h2: " << i << " s: " << s << " e: " << e << " w2: " << w2 << endl;
    if (w2 < s)
      continue;
    cout << " h: " << i << " w2: " << w2 << endl;
    check(r, mp(i, w2));
  }
  for (ll i = 1; i <= w; i *= 2) {
    ll s = (i * 8 + 9) / 10;
    ll e = i * 125 / 100;
    ll h2 = min(h, e);
    if (h2 < s)
      continue;
    check(r, mp(h2, i));
  }

  cout << r.F << " " << r.S << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
