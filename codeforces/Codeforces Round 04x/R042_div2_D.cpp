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

  vector<pi> v;
  bool sw = false;
  if (n == 1 && m == 2) {
    cout << "0\n1 1\n1 2\n 1 1\n";
    return;

  } else if (n == 2 && m == 1) {
    cout << "0\n1 1\n2 1\n 1 1\n";
    return;
  } else if ((n % 2 == 0 || m % 2 == 0) && n > 1 && m > 1) {
    if (n % 2) {
      sw = true;
      swap(n, m);
    }
    v.pb({1, 1});
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = i % 2 == 0 ? j + 1 : m - j;
        if (x == 1)
          continue;
        v.pb({i + 1, x});
      }
    }
    for (int i = n; i >= 1; i--)
      v.pb({i, 1});
    cout << 0 << endl;
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int x = i % 2 == 0 ? j + 1 : m - j;
        v.pb({i + 1, x});
      }
    }
    cout << 1 << endl;
    cout << v.back().F << " " << v.back().S << " 1 1\n";
    v.pb({1, 1});
  }
  if (sw)
    for (auto &x : v)
      swap(x.F, x.S);
  for (auto x : v)
    cout << x.F << " " << x.S << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
