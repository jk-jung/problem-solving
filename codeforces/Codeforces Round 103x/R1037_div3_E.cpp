#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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
bool check(vector<ll> &a, vector<ll> &c) {
  ll g = 0;
  for (int i = 0; i < n; i++) {
    g = gcd(g, c[i]);
    if (g != a[i])
      return false;
  }
  return true;
}

void solve() {
  cin >> n;
  vector<ll> a(n), b(n), c(n);
  for (ll &x : a)
    cin >> x;
  for (ll &x : b)
    cin >> x;

  for (int i = 0; i < n; i++) {
    c[i] = a[i] * b[i] / gcd(a[i], b[i]);
  }

  bool r1 = check(a, c);
  reverse(b.begin(), b.end());
  reverse(c.begin(), c.end());
  bool r2 = check(b, c);

  cout << (r1 && r2 ? "YES" : "NO") << endl;
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
