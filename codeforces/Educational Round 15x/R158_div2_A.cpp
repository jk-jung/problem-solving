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
  int n, t;
  cin >> n >> t;
  vi v(n);
  for (int &x : v)
    cin >> x;
  for (int k = 1;; k++) {
    int pos = 0, fuel = k, dis;
    for (int x : v) {
      dis = x - pos;
      if (dis > fuel)
        goto NO;
      pos = x;
      fuel = k;
    }
    dis = t - pos;
    if (dis > fuel)
      goto NO;
    fuel -= dis;
    pos = t;
    for (int i = n - 1; i >= 0; i--) {
      dis = pos - v[i];
      if (dis > fuel)
        goto NO;
      fuel = k;
      pos = v[i];
    }
    if (pos > fuel)
      goto NO;

    cout << k << endl;
    return;
  NO:;
  }
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
