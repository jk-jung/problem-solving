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
#include <valarray>
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

ll mod_inv(ll a, ll m) {
  ll m0 = m;
  ll y = 0;
  ll x = 1;
  if (m == 1)
    return 0;

  while (a > 1) {
    ll q = a / m;
    ll t = m;
    m = a % m;
    a = t;
    t = y;
    y = x - q * y;
    x = t;
  }

  if (x < 0)
    x += m0;
  return x;
}

void solve() {
  ll A, B, C;
  cin >> A >> B >> C;
  C = -C;
  ll a = A, b = B, c = C;

  if (b == 0) {
    if (C % A != 0) {
      cout << -1 << endl;
      return;
    }
    cout << C / A << " 0" << endl;
    return;
  }

  bool neg_a = false;
  bool neg_b = false;
  if (a < 0) {
    neg_a = true;
    a = -a;
  }
  if (b < 0) {
    neg_b = true;
    b = -b;
  }

  ll g = gcd(a, b);

  if (c % g != 0) {
    cout << -1 << endl;
    return;
  }

  a /= g;
  b /= g;
  c /= g;

  ll inv = mod_inv(a, b);
  ll x = (c * inv) % b;
  ll y = (c - a * x) / b;
  x = x * (neg_a ? -1 : 1);
  y = y * (neg_b ? -1 : 1);

  cout << x << " " << y << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
