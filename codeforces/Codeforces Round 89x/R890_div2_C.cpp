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

int n, t;
int calc(vi &v, int k, int i) {
  ll s = 0, e = 1 << 30, r = -1;
  while (s <= e) {
    ll m = (s + e) / 2;

    ll need = 0;
    for (int j = i, cnt = 0; j < n; j++, cnt++) {
      ll x = m - cnt - v[j];
      if (x <= 0)
        break;
      if (j == n - 1)
        need = 1ll << 50;
      need += x;
    }
    if (need <= k) {
      r = m;
      s = m + 1;
    } else {
      e = m - 1;
    }
  }
  return r;
}

void solve() {
  cin >> n >> t;
  vi v(n);
  for (int &x : v)
    cin >> x;
  int r = 0;
  for (int i = 0; i < n; i++)
    r = max(r, calc(v, t, i));
  cout << r << endl;
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
