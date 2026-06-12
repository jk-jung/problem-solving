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

char a[11][11][11];
int n, m, h;
int r;

void dfs(int i, int j, int k) {
  if (i < 1 || i > n || j < 1 || j > m || k < 1 || k > h || a[i][j][k] == '#')
    return;
  a[i][j][k] = '#';
  r++;
  dfs(i + 1, j, k);
  dfs(i - 1, j, k);
  dfs(i, j + 1, k);
  dfs(i, j - 1, k);
  dfs(i, j, k + 1);
  dfs(i, j, k - 1);
}

void solve() {
  cin >> n >> m >> h;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      for (int k = 1; k <= h; k++) {
        cin >> a[i + 1][j + 1][k];
      }
    }
  }
  int x, y;
  cin >> x >> y;
  dfs(1, x, y);
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
