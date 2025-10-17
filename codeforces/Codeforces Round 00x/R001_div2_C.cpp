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

const double PI = acos(-1.0);

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

double angle(double x1, double y1, double x2, double y2, double x3, double y3) {
  double c = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
  double b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
  double a = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
  double cos_a = (b * b + c * c - a * a) / (2 * b * c);
  return acos(cos_a);
}

bool is_multiple(double a, double b) {
  return abs(a - b * round(a / b)) < 1e-6;
}

void solve() {
  double x1, x2, x3, y1, y2, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  double t = x1 * x1 + y1 * y1 - x2 * x2 - y2 * y2;
  double u = x1 * x1 + y1 * y1 - x3 * x3 - y3 * y3;
  double J = (x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2);

  double x = (-(y1 - y2) * u + (y1 - y3) * t) / J / 2;
  double y = ((x1 - x2) * u - (x1 - x3) * t) / J / 2;

  double a1 = angle(x, y, x1, y1, x2, y2);
  double a2 = angle(x, y, x1, y1, x3, y3);
  double a3 = angle(x, y, x2, y2, x3, y3);

  double r = sqrt((x - x1) * (x - x1) + (y - y1) * (y - y1));

  for (int i = 3; i <= 100; i++) {
    double a = 2 * PI / i;
    if (is_multiple(a1, a) && is_multiple(a2, a) && is_multiple(a3, a)) {
      double area = i * r * r * sin(a) / 2;
      cout << fixed << setprecision(10) << area << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
