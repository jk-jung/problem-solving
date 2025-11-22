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

typedef pair<ll, ll> pl;
int d[555][555];

bool cw(pl a, pl b, pl c) {
  return (b.F - a.F) * (c.S - a.S) - (b.S - a.S) * (c.F - a.F) >= 0;
}
int check(pl a, pl b, pl c, pl k) {
  return cw(a, b, k) && cw(b, c, k) && cw(c, a, k);
}

int calc(pl a, pl b, vector<pl> &t) {
  int r = 0;
  pl c = {1000000001LL, 1000000001LL};

  for (auto k : t) {
    r += check(a, b, c, k);
    r -= check(b, a, c, k);
  }

  return r;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pl> a(n), b(m);
  for (auto &[x, y] : a)
    cin >> x >> y;
  for (auto &[x, y] : b)
    cin >> x >> y;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      d[i][j] = calc(a[i], a[j], b);
      d[j][i] = -d[i][j];
    }
  }
  int r = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        if (d[i][j] + d[j][k] + d[k][i] == 0)
          r++;
      }
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