#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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
  vector<ll> v(n);
  vector<int> c(n);
  for (int i = 0; i < n; i++) {
    ll &x = v[i];
    cin >> x;
    while (x <= k) {
      x *= 2;
      c[i]++;
    }
  }
  sort(c.begin(), c.end());
  int r = n;
  for (int i = 1, j = 0; i <= n; i++) {
    while (j < n && c[j] < i)
      j++;
    if (j == n)
      break;
    j++;
    r--;
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
