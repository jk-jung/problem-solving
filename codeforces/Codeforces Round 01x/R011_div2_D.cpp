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

ll d[1 << 20][19];
int n, m;
vi v[22];
int vv[55][55];

void solve() {
  cin >> n >> m;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    x--, y--;
    v[x].pb(y);
    v[y].pb(x);
    vv[x][y] = vv[y][x] = 1;
  }
  for (int i = 0; i < n; i++) {
    d[1 << i][i] = 1;
  }

  int tot = (1 << (n + 1));
  ll r = 0;
  for (int st = 0; st < tot; st++) {
    int start = -1;
    for (int i = 0; i < n; i++) {
      if (start == -1 && (st >> i & 1))
        start = i;
      if (!d[st][i])
        continue;

      if (vv[start][i]) {
        r += d[st][i];
      }

      for (int y : v[i]) {
        if (!(st >> y & 1) && y > start) {
          d[st | (1 << y)][y] += d[st][i];
        }
      }
    }
  }

  cout << (r - m) / 2 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
