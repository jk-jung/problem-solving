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

const double EPS = 1e-9;

bool is_in(double x, double a, double b) {
  return x >= a - EPS && x <= b + EPS;
}

double a[105], b[105], c[105], d[105];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    if (a[i] > c[i])
      swap(a[i], c[i]);
    if (b[i] > d[i])
      swap(b[i], d[i]);
  }

  for (int i = 1; i < n; i++) {
    double sw = 0, sx = 0, sy = 0;

    bool ok = true;
    for (int j = i; j >= 1; j--) {
      double l = c[j] - a[j];
      double w = l * l * l;

      double x = (c[j] + a[j]) / 2;
      double y = (d[j] + b[j]) / 2;

      sw += w;
      sx += x * w;
      sy += y * w;

      double cx = sx / sw;
      double cy = sy / sw;

      if (is_in(cx, max(a[j], a[j - 1]), min(c[j], c[j - 1])) &&
          is_in(cy, max(b[j], b[j - 1]), min(d[j], d[j - 1]))) {
      } else
        ok = false;
    }
    if (!ok) {
      cout << i << endl;
      return;
    }
  }
  cout << n << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
