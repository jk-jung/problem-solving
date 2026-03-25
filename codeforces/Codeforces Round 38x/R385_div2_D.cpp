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

int a[20][1005];
int q[20][1005];
int n;

vi get_target(int k, int val) {
  vi r;
  for (int i = 0; i < n; i += k) {
    if (val)
      for (int j = 0; j < k && i + j < n; j++)
        r.pb(i + j);
    val ^= 1;
  }
  return r;
}

void out(int j, vi v) {
  if (v.empty())
    return;
  cout << v.size() << endl;
  for (int x : v) {
    cout << x + 1 << " ";
    q[j][x] = 1;
  }
  cout << endl;

  for (int i = 0; i < n; i++)
    cin >> a[j][i];
}

void solve() {
  memset(a, 63, sizeof(a));
  cin >> n;

  for (int i = 0; i < 10; i++) {
    int k = 1 << i;
    out(i * 2, get_target(k, 0));
    out(i * 2 + 1, get_target(k, 1));
  }

  cout << -1 << endl;
  for (int i = 0; i < n; i++) {
    int r = 1 << 30;
    for (int k = 0; k < 20; k++)
      if (!q[k][i])
        r = min(r, a[k][i]);
    cout << r << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
