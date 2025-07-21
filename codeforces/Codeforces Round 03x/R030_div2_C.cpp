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

int x[1005];
int y[1005];
int t[1005];
double p[1005];
double d[1005];
void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> t[i] >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n; j++) {
      if (t[j] > t[j + 1]) {
        swap(t[j], t[j + 1]);
        swap(x[j], x[j + 1]);
        swap(y[j], y[j + 1]);
        swap(p[j], p[j + 1]);
      }
    }
  }
  t[0] = -1e9;
  double r = 0;
  for (int i = 1; i <= n; i++) {
    d[i] = p[i];
    for (int j = 0; j < i; j++) {
      double dis =
          sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
      if (t[i] - t[j] >= dis) {
        d[i] = max(d[i], d[j] + p[i]);
      }
    }
    r = max(r, d[i]);
  }
  cout << fixed << setprecision(10) << r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
