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
  ll n, k;
  cin >> n >> k;
  vi a(n), b(n);

  vector<pi> v(n);
  for (int &x : b)
    cin >> x;
  for (int &x : a)
    cin >> x;

  for (int i = 0; i < n; i++) {
    v.pb({ab(a[i]), b[i]});
  }
  sort(v.begin(), v.end());

  ll tot = 0, last = 0;
  for (auto [pos, health] : v) {
    tot += (pos - last) * k;
    last = pos;
    if (tot < health) {
      cout << "NO\n";
      return;
    }
    tot -= health;
  }

  cout << "YES\n";
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
