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

int n, k, a, b;
vector<pair<ll, ll>> v;
void solve() {
  cin >> n >> k >> a >> b;
  a--, b--;
  v.resize(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  ll r = abs(v[a].F - v[b].F) + abs(v[a].S - v[b].S);
  ll r2 = 0;
  if (a >= k) {
    ll d = 1ll << 60;
    for (int i = 0; i < k; i++) {
      d = min(d, abs(v[a].F - v[i].F) + abs(v[a].S - v[i].S));
    }
    r2 += d;
  }
  if (b >= k) {
    ll d = 1ll << 60;
    for (int i = 0; i < k; i++) {
      d = min(d, abs(v[b].F - v[i].F) + abs(v[b].S - v[i].S));
    }
    r2 += d;
  }
  cout << min(r, r2) << endl;
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
