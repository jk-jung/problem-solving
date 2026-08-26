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
  ll n, c, d;
  cin >> n >> c >> d;
  vector<ll> v(n);
  for (ll &x : v)
    cin >> x;
  sort(v.rbegin(), v.rend());

  if (v[0] * d < c) {
    cout << "Impossible\n";
    return;
  }

  ll tot = 0;
  for (ll i = 0; i < min(n, d); i++)
    tot += v[i];
  if (tot >= c) {
    cout << "Infinity\n";
    return;
  }

  ll r = 0, s = 0;
  while (n < d) {
    n++;
    v.pb(0);
  }
  vector<ll> pre(n + 1);
  for (ll i = 0; i < n; i++) {
    s += v[i];
    pre[i + 1] = s;
    ll value = (d / (i + 1)) * s + pre[d % (i + 1)];
    if (value < c)
      break;
    r = i;
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
