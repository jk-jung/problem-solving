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
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;

  vector<ll> t;
  for (int i = n - 1; i >= 1; i--) {
    int x = v[i - 1];
    int y = v[i];

    if (y % x != 0)
      t.pb(x / gcd(x, y));
  }
  ll lcm = 0;
  for (ll x : t) {
    lcm = lcm == 0 ? x : lcm * x / gcd(lcm, x);
  }
  if (lcm == 0)
    lcm = 1;
  cout << lcm << endl;
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
