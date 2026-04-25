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
  ll n, m, k;
  cin >> n >> m >> k;
  ll r = 1, s = 1, e = n * m;
  while (s <= e) {
    ll M = (s + e) / 2;
    ll cnt = 0;
    for (ll i = 1; i <= n; i++)
      cnt += min(m, M / i);

    if (cnt < k)
      s = M + 1;
    else
      e = M - 1, r = M;
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
