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

int a[555][555];
int n, m, k;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int go(int y, int x) {
  if (x < 0 || y < 0 || x >= m * 2 || y >= n * 2 || a[y][x])
    return 0;
  a[y][x] = 2;
  int r = 1;
  for (int k = 0; k < 4; k++) {
    int ny = y + dy[k];
    int nx = x + dx[k];
    if (ny >= 0 && nx >= 0 && ny < n * 2 && nx < m * 2 && a[ny][nx] == 1)
      continue;
    r += go(y + dy[k] * 2, x + dx[k] * 2);
  }

  return r;
}

void solve() {

  cin >> n >> m >> k;
  while (k--) {
    int x0, y0, x1, y1;
    cin >> y0 >> x0 >> y1 >> x1;

    if (x0 == x1) {
      for (int i = y0 * 2; i <= y1 * 2; i++) {
        int x = x0 * 2;
        a[i][x] = 1;
      }
    } else {
      for (int i = x0 * 2; i <= x1 * 2; i++) {
        int y = y0 * 2;
        a[y][i] = 1;
      }
    }
  }

  vi r;
  for (int i = 1; i < n * 2; i += 2) {
    for (int j = 1; j < m * 2; j += 2) {
      if (a[i][j] == 0) {
        r.pb(go(i, j));
      }
    }
  }
  sort(r.begin(), r.end());
  for (int x : r)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
