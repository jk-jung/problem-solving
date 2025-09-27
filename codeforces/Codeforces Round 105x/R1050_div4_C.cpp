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
  vector<pi> v(n);
  for (auto &[x, y] : v)
    cin >> x >> y;
  int r = 0, t = 0, pos = 0;
  for (auto [x, y] : v) {
    int dif = x - t;
    if (pos != y)
      dif--, r++;
    r += (dif / 2) * 2;

    pos = y;
    t = x;
  }
  r += (m - t);
  cout << r << endl;
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
