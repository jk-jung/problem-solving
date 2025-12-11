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
  int n, m, k;
  cin >> n >> m >> k;

  map<int, int> c;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    if (c.count(a))
      c[a] = min(c[a], b);
    else
      c[a] = b;
  }
  int r = 0;
  for (auto [x, y] : c)
    r += y;
  cout << min(r, k) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
