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

ll f(ll x) {
  // 2, 3, 5, 7

  ll r = x;
  for (int i = 1; i < (1 << 4); i++) {
    ll cnt = 0, t = 1;
    for (int k = 0; k < 4; k++) {
      if (i >> k & 1) {
        cnt++;
        t *= (k == 0 ? 2 : k == 1 ? 3 : k == 2 ? 5 : 7);
      }
    }
    if (cnt % 2 == 1)
      r -= x / t;
    else
      r += x / t;
  }
  return r;
}
void solve() {
  ll a, b;
  cin >> a >> b;
  cout << f(b) - f(a - 1) << endl;
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
