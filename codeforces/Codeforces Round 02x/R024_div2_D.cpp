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

int n, m, sy, sx;
double d[1005][1005];

void solve() {
  cin >> n >> m >> sy >> sx;

  if (m == 1) {
    cout << 2 * (n - sy) << endl;
    return;
  }

  for (int i = n - 1; i >= 1; i--) {
    vector<double> a(m + 1), b(m + 1), c(m + 1), t(m + 1);

    a[1] = 0.0;
    b[1] = -2.0 / 3.0;
    c[1] = 1.0 / 3.0;
    t[1] = -1.0 - (1.0 / 3.0) * d[i + 1][1];

    a[m] = 1.0 / 3.0;
    b[m] = -2.0 / 3.0;
    c[m] = 0.0;
    t[m] = -1.0 - (1.0 / 3.0) * d[i + 1][m];

    for (int j = 2; j < m; j++) {
      a[j] = 1.0 / 4.0;
      b[j] = -3.0 / 4.0;
      c[j] = 1.0 / 4.0;
      t[j] = -1.0 - (1.0 / 4.0) * d[i + 1][j];
    }

    for (int j = 2; j <= m; j++) {
      double factor = a[j] / b[j - 1];
      a[j] = 0.0;
      b[j] = b[j] - factor * c[j - 1];
      t[j] = t[j] - factor * t[j - 1];
    }

    d[i][m] = t[m] / b[m];
    for (int j = m - 1; j >= 1; j--) {
      d[i][j] = (t[j] - c[j] * d[i][j + 1]) / b[j];
    }
  }
  cout << fixed << setprecision(10) << d[sy][sx] << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
