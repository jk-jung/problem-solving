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
  ll n, j;
  cin >> n >> j;
  vector<pair<ll, ll>> v(n);
  ll rx, ry;
  cin >> rx >> ry;
  ll a = 0, b = 0;
  for (auto &[x, y] : v)
    cin >> x >> y;

  ll cnt = j / n;
  j = (j % n) + (cnt % 2 == 0 ? 0 : n);
  for (int i = 0; i < j; i++) {
    // r1 = 2x0 - r1
    // r2 = 2x1 - 2x0 + r1
    // r3 = 2x2 - 2x1 + 2x0 - r1
    // r4 = 2x2 + 2x1 + r1
    // r5 = 2x2 - r1
    // r6 = r1

    rx = v[i % n].F + v[i % n].F - rx;
    ry = v[i % n].S + v[i % n].S - ry;
  }

  cout << rx << " " << ry << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
