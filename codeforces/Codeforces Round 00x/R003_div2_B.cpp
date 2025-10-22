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
  int n, k;
  vector<pi> a, b;
  cin >> n >> k;
  a.pb({0, 0});
  b.pb({0, 0});
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    if (x == 1)
      a.pb({y, i + 1});
    else
      b.pb({y, i + 1});
  }
  sort(a.begin(), a.end());
  reverse(a.begin() + 1, a.end());
  sort(b.begin(), b.end());
  reverse(b.begin() + 1, b.end());

  for (int i = 1; i < a.size(); i++)
    a[i].F += a[i - 1].F;
  for (int i = 1; i < b.size(); i++)
    b[i].F += b[i - 1].F;

  int r = 0, s = 0, ai = 0, bi = 0;
  for (int i = 0; i < b.size() && i * 2 <= k; i++) {
    int idx = min((int)a.size() - 1, k - i * 2);
    int s = b[i].F + a[idx].F;
    if (s > r) {
      r = s;
      bi = i;
      ai = idx;
    }
  }
  cout << r << endl;
  for (int i = 1; i <= bi; i++)
    cout << b[i].S << " ";
  for (int i = 1; i <= ai; i++)
    cout << a[i].S << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
