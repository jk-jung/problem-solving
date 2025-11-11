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

char a[1005][1005];
int n, m;

vector<pi> v;

vi ddy = {0, 1, 0, -1, -1, 1, 1, -1};
vi ddx = {1, 0, -1, 0, 1, 1, -1, -1};

vector<pi> case1 = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pi> case2 = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};

void dfs(int y, int x) {
  a[y][x] = '0';
  v.pb({y, x});
  for (int k = 0; k < 8; k++) {
    int dy = ddy[k];
    int dx = ddx[k];
    int ny = y + dy;
    int nx = x + dx;

    if (ny < 0 || ny >= n || nx < 0 || nx >= m || a[ny][nx] != '1')
      continue;
    dfs(ny, nx);
  }
}

bool ck(vector<pi> &dd, int idx = 0) {
  int q = v.size() / 4;

  for (auto &[dy, dx] : dd) {
    for (int _ = 0; _ < q; _++) {
      int ndx = (idx + 1) % v.size();
      if (v[idx].F + dy != v[ndx].F || v[idx].S + dx != v[ndx].S)
        return false;
      idx = ndx;
    }
  }
  return true;
}

bool check() {
  int k = v.size();
  if (k % 4 != 0)
    return false;

  return ck(case1) || ck(case2);
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> a[i];

  int r = 0;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (a[i][j] == '1') {
        v.clear();
        dfs(i, j);
        r += check();
      }
  cout << r << endl;
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
