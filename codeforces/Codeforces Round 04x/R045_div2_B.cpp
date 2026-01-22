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

int n, m;
int a[55][55];

int f(int x, int y) {
  int r = 1 << 30;
  for (int i = 0; i < n - x + 1; i++)
    for (int j = 0; j < m - y + 1; j++) {
      int c = 0;
      for (int p = i; p < i + x; p++)
        for (int q = j; q < j + y; q++)
          c += a[p][q];
      r = min(r, c);
    }
  return r;
}
void solve() {
  int x, y;
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  cin >> x >> y;

  cout << min(f(x, y), f(y, x)) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
