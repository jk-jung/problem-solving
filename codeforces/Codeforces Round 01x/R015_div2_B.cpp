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
  ll n, m, x0, y0, x3, y3;
  cin >> n >> m >> x0 >> y0 >> x3 >> y3;
  ll x = ab(x3 - x0);
  ll y = ab(y3 - y0);
  ll nn = n - x;
  ll mm = m - y;

  ll tot = n * m;
  tot -= nn * mm * 2;
  tot += max(0ll, nn * 2 - n) * (max(0ll, mm * 2 - m));
  cout << tot << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int t;
  cin >> t;
  while (t--)
    solve();
}
