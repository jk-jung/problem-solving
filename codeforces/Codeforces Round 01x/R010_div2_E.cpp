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
  vector<ll> v(n);
  for (ll &x : v)
    cin >> x;

  ll r = 1ll << 60;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ll t = v[i] - 1;
      ll cnt = 1;
      for (int k = i + 1; k <= j; k++) {
        cnt += t / v[k];
        t %= v[k];
      }
      ll target = v[i] - 1 - t + v[j];
      t = target;
      ll cnt2 = 0;
      for (int k = 0; k < n; k++) {
        cnt2 += t / v[k];
        t %= v[k];
      }
      if (cnt < cnt2) {
        r = min(r, target);
      }
    }
  }
  if (r == 1ll << 60)
    cout << -1 << endl;
  else
    cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
