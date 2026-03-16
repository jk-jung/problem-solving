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

int n, m, k;
int s[1005][1005];
int f(int y, int x, int ny, int nx) {
  if (y > ny)
    swap(y, ny);
  if (x > nx)
    swap(x, nx);
  return s[ny + 1][nx + 1] - s[y][nx + 1] - s[ny + 1][x] + s[y][x];
}

bool ok(int y, int x, vector<string> &v, vector<pair<string, int>> &q) {
  for (auto &t : q) {
    auto [dir, len] = t;
    int ny = y, nx = x;
    if (dir == "N")
      ny -= len;
    if (dir == "S")
      ny += len;
    if (dir == "E")
      nx += len;
    if (dir == "W")
      nx -= len;
    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
      return false;
    if (f(y, x, ny, nx) > 0)
      return false;
    y = ny;
    x = nx;
  }
  return true;
}

void solve() {
  cin >> n >> m;
  vector<string> v(n);
  for (auto &x : v)
    cin >> x;

  cin >> k;
  vector<pair<string, int>> q(k);
  for (auto &x : q)
    cin >> x.first >> x.second;

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] +
                (v[i - 1][j - 1] == '#');

  string r;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if ('A' <= v[i][j] && v[i][j] <= 'Z' && ok(i, j, v, q)) {
        r += v[i][j];
      }
    }
  sort(r.begin(), r.end());
  if (r.empty())
    r = "no solution";
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
