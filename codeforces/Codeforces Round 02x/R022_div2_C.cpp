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

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<pi> v;
  int x = 1;
  if (k == 1)
    x = 2;

  for (int i = 1; i <= n; i++) {
    if (i != k)
      v.pb(mp(k, i));
  }

  if (v.size() > m) {
    cout << -1 << endl;
    return;
  }

  for (int i = 1; i <= n; i++) {
    if (i == k || i == x)
      continue;
    for (int j = i + 1; j <= n; j++) {
      if (j == k || j == x)
        continue;
      if (v.size() < m) {
        v.pb(mp(i, j));
      }
      if (v.size() == m) {
        for (auto x : v) {
          cout << x.F << " " << x.S << endl;
        }
        return;
      }
    }
  }
  cout << -1 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
