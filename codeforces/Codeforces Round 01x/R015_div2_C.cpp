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

ll xo(ll t) {
  if (t < 0)
    return 0;
  if (t % 4 == 0)
    return t;
  if (t % 4 == 3)
    return 0;
  if (t % 4 == 1)
    return 1;
  return t + 1;
}
ll xo(ll a, ll b) { return xo(b) ^ xo(a - 1); }
void solve() {
  int n;
  cin >> n;
  vi v(n);

  ll r = 0;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    r ^= xo(a, a + b - 1);
  }
  cout << (r ? "tolik" : "bolik") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
