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

double d[18][1 << 18];
bool ck[18][1 << 18];
int n;
double a[22][22];

double go(int i, int mask) {
  if (mask == (1 << i))
    return 1;

  double &r = d[i][mask];
  if (ck[i][mask])
    return r;

  ck[i][mask] = true;

  r = 0;
  double cnt = 0;
  for (int x = 0; x < n; x++) {
    if (!(mask >> x & 1))
      continue;
    cnt += 1;
    for (int y = x + 1; y < n; y++) {
      if (!(mask >> y & 1))
        continue;
      if (x == i) {
        r += go(i, mask ^ (1 << y)) * a[x][y];
      } else if (y == i) {
        r += go(i, mask ^ (1 << x)) * a[y][x];
      } else {
        r += go(i, mask ^ (1 << y)) * a[x][y];
        r += go(i, mask ^ (1 << x)) * a[y][x];
      }
    }
  }
  r /= (cnt * (cnt - 1) / 2);
  return r;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    cout << fixed << setprecision(10) << go(i, (1 << n) - 1) << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
