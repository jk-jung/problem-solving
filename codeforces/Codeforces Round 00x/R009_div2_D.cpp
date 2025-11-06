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

ll d[55][55];

ll go(int n, int h) {
  if (n == 1 && h == 1)
    return 1;
  if (n <= 1 || h <= 1)
    return 0;

  ll &r = d[n][h];
  if (r != -1)
    return r;

  r = go(n - 1, h - 1) * 2;
  int m = n - 1;
  for (int n1 = 1; n1 < m; n1++) {
    int n2 = m - n1;
    for (int h1 = 0; h1 <= h - 1; h1++) {
      for (int h2 = 0; h2 <= h - 1; h2++) {
        if (h1 == h - 1 || h2 == h - 1)
          r += go(n1, h1) * go(n2, h2);
      }
    }
  }
  return r;
}

void solve() {
  memset(d, -1, sizeof(d));
  int n, h;
  cin >> n >> h;

  ll r = 0;
  for (int i = h; i <= n; i++)
    r += go(n, i);
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
