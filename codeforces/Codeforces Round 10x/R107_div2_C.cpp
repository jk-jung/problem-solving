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
  ll m = n;
  vector<pair<ll, ll>> v;
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      v.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        v.back().S++;
      }
    }
  }
  if (n > 1 && n != m)
    v.pb({n, 1});

  if (v.empty()) {
    cout << "1\n0\n";
    return;
  }
  if (v.size() >= 2) {
    if (v[0].F * v[1].F == m) {
      cout << "2\n";
    } else {
      cout << "1\n";
      cout << v[0].F * v[1].F << endl;
    }
    return;
  }
  ll cnt = v[0].S;
  if (cnt >= 3) {
    cout << "1\n";
    cout << v[0].F * v[0].F << endl;
  } else
    cout << "2\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
