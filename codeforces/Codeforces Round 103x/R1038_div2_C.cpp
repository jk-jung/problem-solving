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

void solve() {
  int n;
  cin >> n;

  vi x(n), y(n);
  vector<pi> xx, yy;
  vi a, b, c, d;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    xx.pb({x[i], i});
    yy.pb({y[i], i});
  }
  sort(xx.begin(), xx.end());
  sort(yy.begin(), yy.end());

  set<int> ax, bx;
  for (int i = 0; i < n / 2; i++) {
    ax.insert(xx[i].S);
  }
  // a b
  // c d
  for (int i = 0; i < n; i++) {
    int k = yy[i].S;
    if (i < n / 2) {
      if (ax.count(k))
        c.pb(k);
      else
        d.pb(k);
    } else {
      if (ax.count(k))
        a.pb(k);
      else
        b.pb(k);
    }
  }
  for (int i = 0; i < a.size(); i++) {
    cout << a[i] + 1 << " " << d[i] + 1 << endl;
  }
  for (int i = 0; i < b.size(); i++) {
    cout << b[i] + 1 << " " << c[i] + 1 << endl;
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
