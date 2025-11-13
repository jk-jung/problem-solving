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
typedef pair<double, double> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

double t1, t2;
pi a, b, c;
vector<pi> inf = {{0, 0}, {0, 0}, {0, 0}};
const double EPS = 1e-9;

double dis(pi a, pi b) {
  return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

vector<pi> find_two_points(double r0, pi a, double r1, pi b) {
  double x0 = a.first;
  double y0 = a.second;
  double x1 = b.first;
  double y1 = b.second;

  double dx = x1 - x0;
  double dy = y1 - y0;
  double d = dis(a, b);

  double a_len = (r0 * r0 - r1 * r1 + d * d) / (2.0 * d);

  double h2 = r0 * r0 - a_len * a_len;
  if (h2 < 0)
    h2 = 0;
  double h = std::sqrt(h2);

  double xm = x0 + a_len * dx / d;
  double ym = y0 + a_len * dy / d;

  double rx = -dy * (h / d);
  double ry = dx * (h / d);

  return {{xm + rx, ym + ry}, {xm - rx, ym - ry}};
}

vector<pi> find_points(double ra, pi a, double rb, pi b) {
  if (ra < rb) {
    swap(a, b);
    swap(ra, rb);
  }

  double d = dis(a, b);

  // No intersection
  if (d > ra + rb)
    return {};
  // Include
  if (d + rb <= ra)
    return inf;
  // One intersection point
  if (dis(a, b) == ra + rb) {
    double x = a.F + (b.F - a.F) * ra / (ra + rb);
    double y = a.S + (b.S - a.S) * ra / (ra + rb);
    return {{x, y}};
  }
  // Two intersection points
  return find_two_points(ra, a, rb, b);
}

bool is_in(pi p, double r, pi c) { return dis(p, c) <= r; }

bool check(double ra, pi a, double rb, pi b, double rc, pi c) {
  vector<pi> ps = find_points(ra, a, rb, b);
  if (ps.empty())
    return false;
  if (ps == inf) {
    if (ra < rb)
      return !find_points(ra, a, rc, c).empty();
    else
      return !find_points(rb, b, rc, c).empty();
  }

  for (pi p : ps)
    if (is_in(p, rc, c))
      return true;
  return false;
}

bool can(double x) {
  double ra = x;
  double rb = dis(a, b) + t1 - x;
  double rc = dis(a, c) + t2 - x;

  if (rb < 0 || rc < 0)
    return false;

  return check(ra, a, rb, b, rc, c) || check(rb, b, rc, c, ra, a) ||
         check(ra, a, rc, c, rb, b);
}

void solve() {
  cin >> t2 >> t1;
  cin >> a.F >> a.S >> b.F >> b.S >> c.F >> c.S;

  // t1: a ------> b
  // t2: a -> c -> b

  double db = dis(a, c) + dis(c, b);
  double da = dis(a, b);

  if (db <= da + t1) {
    cout << fixed << setprecision(10) << min(da + t1, db + t2) << endl;
    return;
  }

  double s = 0, e = 1000;
  for (int _ = 0; _ < 10000; _++) {
    double m = (s + e) / 2;
    if (can(m))
      s = m;
    else
      e = m;
  }
  cout << fixed << setprecision(10) << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
