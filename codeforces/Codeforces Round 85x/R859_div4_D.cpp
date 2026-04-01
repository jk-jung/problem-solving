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
  int n, m;
  cin >> n >> m;
  vector<ll> v(n + 1);
  for (int i = 1; i <= n; i++) {
    ll x;
    cin >> x;
    v[i] = v[i - 1] + x;
  }
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll t = v.back() - v[b] + v[a - 1] + (b - a + 1) * c;
    cout << (t % 2 == 1 ? "YES" : "NO") << endl;
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
