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

void solve() {
  int n;
  cin >> n;
  vector<pi> v(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  double s = 0, e = 1e10, r = 1e10;

  for (int _ = 0; _ < 1000; _++) {
    double m = (s + e) / 2;

    double max_dis = -1e30;
    bool ok = true;
    for (auto [x, y] : v) {
      double val = x + y * m;
      if (y > 0) {
        max_dis = max(max_dis, val);
      } else if (val <= max_dis) {
        ok = false;
        break;
      }
    }
    if (ok) {
      r = m;
      s = m;
    } else {
      e = m;
    }
  }
  if (r == 1e10)
    cout << -1 << endl;
  else
    cout << fixed << setprecision(10) << r << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
