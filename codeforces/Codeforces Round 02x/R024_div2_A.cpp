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

int a[111][111];
int n, s = 0;

void dfs(int x, int y) {

  for (int i = 1; i <= n; i++) {
    if (i == y)
      continue;
    if (a[x][i] || a[i][x]) {
      if (a[x][i])
        s += a[x][i];
      if (i == 1)
        return;
      return dfs(i, x);
    }
  }
}
void solve() {

  cin >> n;
  int r = 0;
  for (int i = 0; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    a[x][y] = z;
    r += z;
  }

  dfs(1, 0);
  cout << min(s, r - s) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
