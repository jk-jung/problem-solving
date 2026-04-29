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

ll s[100005];
ll d[100005];
void solve() {
  ll n, m;
  cin >> n >> m;
  vi a(n), b(m), c;

  for (int i = 0; i < n; i++)
    cin >> a[i], c.pb(a[i]);
  for (int i = 0; i < m; i++)
    cin >> b[i], c.pb(b[i]);

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  d[0] = a[0];
  for (int i = 1; i < n; i++)
    d[i] = d[i - 1] + a[i];
  for (int i = m - 1; i >= 0; i--)
    s[i] = s[i + 1] + b[i];

  sort(c.begin(), c.end());
  c.erase(unique(c.begin(), c.end()), c.end());

  ll i = 0, j = 0;
  ll tot = 0, r = 1ll << 60;
  for (int x : c) {
    while (i < n && a[i] < x)
      tot += a[i++];
    while (j < m && b[j] <= x)
      j++;

    ll v = x * i - tot + s[j] - x * (m - j);
    r = min(r, v);
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
