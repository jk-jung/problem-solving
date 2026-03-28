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

vector<ll> v;
ll f(ll x) {
  ll r = 0, last = 0;
  for (ll y : v) {
    bool end = false;
    ll z = y;
    if (z >= x)
      end = true, z = x;
    r += (z - last) * y;

    if (end)
      break;

    last = y;
  }
  return r;
}
void solve() {

  queue<ll> q;
  q.push(0);
  while (!q.empty()) {
    ll x = q.front();
    q.pop();
    if (x)
      v.pb(x);
    if (x > 1e9)
      break;
    q.push(x * 10 + 4);
    q.push(x * 10 + 7);
  }
  sort(v.begin(), v.end());

  ll a, b;
  cin >> a >> b;
  cout << f(b) - f(a - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
