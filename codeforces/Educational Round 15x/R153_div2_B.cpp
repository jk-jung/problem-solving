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
  ll m, k, a, b;
  cin >> m >> k >> a >> b;
  m -= min(b, m / k) * k;
  if (m <= a) {
    cout << 0 << endl;
  } else {
    ll x = m / k;
    ll y = m % k;

    ll c1 = min(y, a);
    ll c2 = max(0ll, x - (a - c1) / k);

    cout << c2 + y - c1 << endl;
  }
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
