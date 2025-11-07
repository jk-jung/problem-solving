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

int n, p1, p2, p3, t2, t3;
int f(int d) {
  if (d < 0)
    return 0;
  int r = 0;
  r += min(d, t2) * p1;
  d -= min(d, t2);
  r += min(d, t3) * p2;
  d -= min(d, t3);
  r += d * p3;
  return r;
}
void solve() {
  cin >> n >> p1 >> p2 >> p3 >> t2 >> t3;

  int x, y = 1 << 30, r = 0;
  for (int i = 0, s, e; i < n; i++) {
    cin >> s >> e;
    r += (e - s) * p1 + f(s - y);
    x = s;
    y = e;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
