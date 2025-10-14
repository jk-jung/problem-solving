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

bool ck(double x, double y, double rx, double ry, double r) {
  return (x - rx) * (x - rx) + (y - ry) * (y - ry) <= r * r;
}

void solve() {
  double px, py, ax, ay, bx, by;
  cin >> px >> py >> ax >> ay >> bx >> by;
  double s = 0, e = 1e4;

  for (int _ = 0; _ < 300; _++) {
    double m = (s + e) / 2;

    bool a0 = ck(0, 0, ax, ay, m);
    bool a1 = ck(px, py, ax, ay, m);
    bool b0 = ck(0, 0, bx, by, m);
    bool b1 = ck(px, py, bx, by, m);
    bool adj = ck(ax, ay, bx, by, m * 2);

    if ((a0 && a1) || (b0 && b1) || (a0 && b1 && adj) || (a1 && b0 && adj))
      e = m;
    else
      s = m;
  }
  cout << fixed << setprecision(10) << s << endl;
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
