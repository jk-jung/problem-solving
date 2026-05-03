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
  n *= 2;
  vi a(n);
  for (int &x : a)
    cin >> x;
  vi v;
  for (int i = 0; i < n;) {
    int cnt = 0, k = a[i];
    while (i < n && a[i] <= k) {
      i++, cnt++;
    }
    v.pb(cnt);
  }

  vi d(n + 1);
  d[0] = 1;
  for (int x : v) {
    for (int i = n; i >= 0; i--)
      if (d[i])
        d[i + x] = 1;
  }
  cout << (d[n / 2] ? "YES" : "NO") << endl;
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
