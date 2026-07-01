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

void solve() {
  ll n, m, k, x, y;
  cin >> n >> m >> x >> y >> k;
  ll r = 0;
  while (k--) {
    ll dx, dy;
    cin >> dx >> dy;
    ll steps = 1ll << 60;
    if (dx > 0)
      steps = min(steps, (n - x) / dx);
    if (dx < 0)
      steps = min(steps, (x - 1) / -dx);
    if (dy > 0)
      steps = min(steps, (m - y) / dy);
    if (dy < 0)
      steps = min(steps, (y - 1) / -dy);
    r += steps;
    x += steps * dx;
    y += steps * dy;
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
