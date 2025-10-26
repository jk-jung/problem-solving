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

double a, v, l, d, w;

pair<double, double> calc(double s, double e) {
  double t = abs(e - s) / a;
  double dis = (s + e) * t / 2;
  return {t, dis};
}

pair<double, double> calc(double s, double e, double e2) {
  auto [t, dis] = calc(s, e);
  if (e2 == -1)
    return {t, dis};
  auto [t2, dis2] = calc(e, e2);
  return {t + t2, dis + dis2};
}
void solve() {
  cin >> a >> v >> l >> d >> w;
  auto [tt, dd] = calc(0, v);

  double s = 0, e = v, r = 0, rt = 0;
  for (int _ = 0; _ < 1000; _++) {
    double m = (s + e) / 2;
    bool ok = true;

    auto [t, dis] = calc(0, m, m <= w ? -1 : w);
    if (dis <= d) {
      ok = true;
      t += (d - dis) / m;
    } else
      ok = false;

    if (ok) {
      r = m;
      rt = t;
      s = m;
    } else {
      e = m;
    }
  }

  double cur = min(w, r);
  double remain = l - d;
  auto [t, dis] = calc(cur, v);

  if (dis <= remain) {
    rt += t + (remain - dis) / v;
  } else {
    double s = cur, e = v, rr = cur;
    for (int _ = 0; _ < 1000; _++) {
      double m = (s + e) / 2;
      auto [t, dis] = calc(cur, m);
      if (dis <= remain) {
        rr = m;
        s = m;
      } else {
        e = m;
      }
    }
    rt += calc(cur, rr).first;
  }

  cout << fixed << setprecision(10) << rt << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
