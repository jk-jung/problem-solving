#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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
int a[200005];
int b[200005];
int c[200005];
int d[200005];

void solve() {
  int n;
  ll x = 0, y = 0, r = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    x += abs(a[i] - c[i]);
    y += abs(b[i] - d[i]);
    if (c[i] > 0 && a[i] > 0 && b[i] > d[i])
      r += min(a[i], c[i]);
  }
  cout << x / 2 + y / 2 + r << endl;
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
