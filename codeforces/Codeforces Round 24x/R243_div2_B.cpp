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

vector<vi> v, t;
void solve() {
  int n, m;
  cin >> n >> m;

  v.resize(n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      v[i].pb(x);
    }
  }

  int r = n;
  for (int i = 1; i <= n; i *= 2) {
    if (n % i)
      continue;
    int q = n / i;
    vector<vi> a;
    for (int j = 0; j < q; j++)
      a.pb(v[j]);
    while (q < n) {
      for (int i = q - 1; i >= 0; i--)
        a.pb(a[i]);
      q *= 2;
    }

    if (v == a) {
      r = min(r, n / i);
    }
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
