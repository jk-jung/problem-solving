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

const int MOD = 1000000007;
void solve() {
  int n, k;
  cin >> n >> k;
  vi a(1 << 6), b(1 << 6);
  a[(1 << 6) - 1] = 1;
  for (int i = 0; i < n; i++) {
    b = a;
    int x;
    cin >> x;
    for (int p = 0; p < 1 << 6; p++) {
      b[p & x] = (b[p & x] + a[p]) % MOD;
    }
    a = b;
  }

  int r = 0;
  for (int i = 0; i < 1 << 6; i++) {
    int cnt = 0;
    for (int j = 0; j < 6; j++) {
      if (i >> j & 1)
        cnt++;
    }
    if (cnt == k)
      r = (r + a[i]) % MOD;
  }
  if (k == 6)
    r = (r + MOD - 1) % MOD;
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
