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
  ll t = 0;
  vector<ll> v(n), a(5), r(5);
  for (ll &x : v)
    cin >> x;
  for (ll &x : a)
    cin >> x;

  for (ll x : v) {
    t += x;
    for (int i = 4; i >= 0; i--) {
      r[i] += t / a[i];
      t %= a[i];
    }
  }
  for (ll x : r)
    cout << x << " ";
  cout << endl;
  cout << t << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
