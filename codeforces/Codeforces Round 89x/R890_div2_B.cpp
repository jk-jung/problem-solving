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
  ll n;
  cin >> n;
  vector<ll> v(n);
  vector<ll> r(n);
  for (ll &x : v)
    cin >> x;

  if (n == 1) {
    cout << "NO\n";
    return;
  }
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    ll x = v[i];
    if (x != 1) {
      cnt += x - 1;
      r[i] = x - 1;
    }
  }

  for (int i = 0; i < n; i++) {
    ll x = v[i];
    if (x == 1) {
      if (cnt == 0) {
        cout << "NO\n";
        return;
      }
      r[i] = 2;
      cnt--;
    }
  }
  for (int i = 0; i < n; i++)
    if (r[i] == v[i]) {
      cout << "NO\n";
      return;
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
