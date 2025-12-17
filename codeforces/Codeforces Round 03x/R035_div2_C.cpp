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
  int n, m, k;
  cin >> n >> m >> k;
  vector<pi> v(k);
  for (auto &[x, y] : v)
    cin >> x >> y, x--, y--;
  int r = -1, rx, ry;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      int d = 1 << 30;
      for (int t = 0; t < k; t++)
        d = min(d, abs(i - v[t].F) + abs(j - v[t].S));
      if (d > r) {
        r = d;
        rx = i;
        ry = j;
      }
    }
  cout << rx + 1 << " " << ry + 1 << endl;
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
