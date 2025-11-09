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

map<int, vi> t;
int d[555][555];
int fi[555][555];
int fj[555][555];
int n, m;
vi a, b;

void dfs(int i, int j) {
  if (fi[i][j] == -1)
    return;
  dfs(fi[i][j], fj[i][j]);
  cout << a[i - 1] << " ";
}

void solve() {
  memset(fi, -1, sizeof(fi));
  memset(fj, -1, sizeof(fj));
  cin >> n;
  a.resize(n);
  for (int &x : a)
    cin >> x;
  cin >> m;
  b.resize(m);
  for (int &x : b)
    cin >> x;
  for (int i = 0; i < m; i++)
    t[b[i]].pb(i);

  d[0][0] = 1;
  int r = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!d[i][j])
        continue;
      int x = i == 0 ? -1 : a[i - 1];

      for (int k = i; k < n; k++) {
        if (a[k] <= x)
          continue;
        int y = a[k];
        int p = lower_bound(t[y].begin(), t[y].end(), j) - t[y].begin();
        if (p == t[y].size())
          continue;
        int nj = t[y][p];
        if (d[k + 1][nj] < d[i][j] + 1) {
          d[k + 1][nj] = d[i][j] + 1;
          fi[k + 1][nj] = i;
          fj[k + 1][nj] = j;
          r = max(r, d[i][j] + 1);
        }
      }
    }
  }
  cout << r - 1 << endl;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j < m; j++) {
      if (d[i][j] == r) {
        dfs(i, j);
        cout << endl;
        return;
      }
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
