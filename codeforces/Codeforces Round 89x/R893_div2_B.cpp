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
  int n, m, d;
  cin >> n >> m >> d;
  vi v(m), r(m), pre(m);
  for (int &x : v)
    cin >> x;

  int min_r = 1 << 30;

  pre[m - 1] = (n - v[m - 1]) / d + 1;
  for (int i = m - 2; i >= 0; i--)
    pre[i] = pre[i + 1] + 1 + (v[i + 1] - v[i] - 1) / d;

  int rst = 0;
  for (int i = 0; i < m; i++) {
    if (i == 0) {
      r[i] = rst + pre[i + 1] + (v[1] + d - 2) / d;
    } else if (i == m - 1) {
      r[i] = rst + (n - v[i - 1]) / d;
    } else {
      r[i] = rst + pre[i + 1] + (v[i + 1] - v[i - 1] - 1) / d;
    }

    if (i == 0) {
      rst += (v[0] + d - 2) / d + 1;
    } else {
      rst += (v[i] - v[i - 1] - 1) / d + 1;
    }
    min_r = min(min_r, r[i]);
  }
  int cnt = 0;
  int tt = 0;
  for (int x : r) {
    cnt += x == min_r;
  }

  cout << min_r << " " << cnt << endl;
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
