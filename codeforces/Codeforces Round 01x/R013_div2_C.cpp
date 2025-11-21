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

int n;
vi v, t;

ll d[5005][5005];

ll go(int idx, int last) {
  if (idx == n)
    return 0;
  ll &r = d[idx][last];
  if (r != -1)
    return r;

  r = 1ll << 60;

  for (int i = last; i < t.size(); i++) {
    r = min(r, go(idx + 1, i) + abs(t[v[idx]] - t[i]));
  }

  return r;
}
void solve() {
  cin >> n;
  v.resize(n);
  for (int &x : v)
    cin >> x;

  t = v;
  sort(t.begin(), t.end());
  t.erase(unique(t.begin(), t.end()), t.end());
  for (int &x : v)
    x = lower_bound(t.begin(), t.end(), x) - t.begin();

  int m = t.size();
  for (int i = 0; i < m; i++)
    d[0][i] = abs(t[i] - t[v[0]]);

  int x = 1, y = 0;
  for (int i = 1; i < n; i++) {
    swap(x, y);
    ll val = d[x][0];
    for (int j = 0; j < m; j++) {
      val = min(val, d[x][j]);
      d[y][j] = val + abs(t[j] - t[v[i]]);
    }
  }
  ll r = 1ll << 60;
  for (int i = 0; i < m; i++)
    r = min(r, d[y][i]);
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
