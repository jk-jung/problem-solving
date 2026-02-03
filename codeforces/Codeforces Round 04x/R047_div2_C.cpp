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
  vector<pi> v(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  vi a, b;
  for (auto [x, y] : v) {
    a.pb(x + y);
    b.pb(x - y);
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  int r = a[n - 1] - a[0] + b[n - 1] - b[0];
  cout << r + 4 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
