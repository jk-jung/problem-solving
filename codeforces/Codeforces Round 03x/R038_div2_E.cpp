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

ll d[3005][3005];
void solve() {
  int n;
  cin >> n;

  vector<pi> v(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  sort(v.begin(), v.end());

  memset(d, 63, sizeof(d));
  d[0][0] = v[0].S;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < i; j++) {
      // i: index
      // j: last pinned
      d[i][j] = min(d[i][j], d[i - 1][j] + v[i].F - v[j].F);
      d[i][i] = min(d[i][i], d[i - 1][j] + v[i].S);
    }
  }
  ll r = 1ll << 60;
  for (int i = 0; i < n; i++)
    r = min(r, d[n - 1][i]);

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
