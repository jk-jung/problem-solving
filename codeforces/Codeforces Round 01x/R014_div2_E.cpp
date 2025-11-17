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

int n, t;

ll d[22][4][4][11][11];

ll go(int idx, int z, int y, int up, int down) {
  if (idx == n)
    return up == t && down == t - 1;
  ll &r = d[idx][z][y][up][down];
  if (r != -1)
    return r;

  r = 0;
  for (int x = 0; x < 4; x++) {
    if (x == y)
      continue;
    int up2 = up;
    int down2 = down;
    if (z < y && y > x)
      up2++;
    if (z > y && y < x)
      down2++;
    r += go(idx + 1, y, x, up2, down2);
  }
  return r;
}

void solve() {
  memset(d, -1, sizeof(d));
  cin >> n >> t;

  ll r = 0;

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if (i != j)
        r += go(2, i, j, 0, 0);
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
