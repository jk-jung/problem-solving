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

int T, I;

const double PI = acos(-1);

typedef pair<double, double> pd;
typedef pair<pd, pd> line;

double dot(pd a, pd b) { return a.F * b.F + a.S * b.S; }
double norm(pd a) { return sqrt(dot(a, a)); }
double cos(pd a, pd b) { return dot(a, b) / norm(a) / norm(b); }
double angle(pd a, pd b) { return acos(cos(a, b)) * 180 / PI; }
double distance(pd a, pd b) {
  return sqrt((a.F - b.F) * (a.F - b.F) + (a.S - b.S) * (a.S - b.S));
}

bool check2(line a, pd p) {
  double d = distance(a.F, a.S);
  double d1 = distance(a.F, p);
  double d2 = distance(a.S, p);

  double dx = a.F.F - a.S.F;
  double dy = a.F.S - a.S.S;
  if (dx == 0) {
    if (abs(p.F - a.F.F) > 1e-8)
      return false;
  } else {
    double k = dy / dx;
    double t = a.F.S - k * a.F.F;
    double val = k * p.F + t;
    if (abs(val - p.S) > 1e-8)
      return false;
  }

  return max(d1, d2) <= min(d1, d2) * 4 && abs(d - d1 - d2) < 1e-7;
}
bool check(line a, line b, line c) {
  if (a.F == b.S)
    swap(b.F, b.S);
  else if (a.S == b.F)
    swap(a.F, a.S);
  else if (a.S == b.S) {
    swap(b.F, b.S);
    swap(a.F, a.S);
  }
  if (a.F != b.F)
    return false;

  pd x = {a.S.F - a.F.F, a.S.S - a.F.S};
  pd y = {b.S.F - b.F.F, b.S.S - b.F.S};
  double ang = angle(x, y);
  if (ang < 1e-8 || ang > 90)
    return false;

  return (check2(a, c.F) && check2(b, c.S)) ||
         (check2(a, c.S) && check2(b, c.F));
}

void solve() {
  line a, b, c;
  cin >> a.F.F >> a.F.S >> a.S.F >> a.S.S;
  cin >> b.F.F >> b.F.S >> b.S.F >> b.S.S;
  cin >> c.F.F >> c.F.S >> c.S.F >> c.S.S;

  bool ok = check(a, b, c) || check(b, c, a) || check(c, a, b);

  cout << (ok ? "YES" : "NO") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  cin >> T;
  for (I = 1; I <= T; I++) {
    solve();
  }
}
