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

int D;
vector<pi> v;

map<vi, bool> d;

bool go(int x, int y, int tx = 0, int ty = 0) {

  vi key = {x, y, tx, ty};
  if (d.count(key))
    return d[key];

  bool ok = false;
  if (tx == 0)
    ok = go(x, y, ty, 1);
  for (auto [dx, dy] : v) {
    int nx = x + dx;
    int ny = y + dy;
    if (D * D < nx * nx + ny * ny)
      continue;
    if (!go(nx, ny, ty, tx)) {
      ok = true;
      break;
    }
  }

  return d[key] = ok;
}
void solve() {
  int x, y, n;
  cin >> x >> y >> n >> D;
  v.resize(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  cout << (go(x, y) ? "Anton" : "Dasha") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
