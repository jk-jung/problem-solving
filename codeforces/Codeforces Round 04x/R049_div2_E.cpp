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

int n, m, k;
int a[11][11];
int d[1 << 10][1 << 10];

void solve() {
  cin >> n >> m >> k;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    x--, y--;
    a[x][y] = a[y][x] = 1;
    d[(1 << x) | (1 << y)][(1 << x) | (1 << y)] = 2;
  }

  for (int s0 = 0; s0 < (1 << n); s0++) {
    for (int s1 = 0; s1 <= s0; s1++) {
      int c = __builtin_popcount(s1);
      if (c < 2)
        continue;
      d[s0][s1] /= c;

      // connect j -> i(new)
      for (int i = 0; i < n; i++) {
        if (s0 >> i & 1)
          continue;

        for (int j = 0; j < n; j++) {
          if (!(s0 >> j & 1))
            continue;
          if (!a[j][i])
            continue;

          int n0 = s0 | (1 << i);
          int n1 = s1 | (1 << i);
          if (n1 >> j & 1)
            n1 ^= (1 << j);
          d[n0][n1] += d[s0][s1];
        }
      }
    }
  }

  int r = 0;
  for (int i = 0; i < (1 << n); i++) {
    if (__builtin_popcount(i) == k) {
      r += d[(1 << n) - 1][i];
    }
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
