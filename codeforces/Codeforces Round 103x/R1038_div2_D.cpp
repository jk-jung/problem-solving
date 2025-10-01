#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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

int n, m;
vi v[5555];
void solve() {
  cin >> n >> m;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }

  vi d0(n + 1, 1 << 20);
  d0[1] = 0;
  for (int i = 0; i <= 3 * n; i++) {
    vi d1(n + 1, 1 << 20);
    for (int j = 1; j <= n; j++) {
      if (d0[j] == 1 << 20)
        continue;

      if (j == n) {
        cout << i << " " << d0[j] << endl;
        for (int i = 1; i <= n; i++)
          v[i].clear();
        return;
      }
      int k = v[j][i % v[j].size()];

      d1[k] = min(d1[k], d0[j]);
      d1[j] = min(d1[j], d0[j] + 1);
    }
    d0 = d1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
