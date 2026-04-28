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

int n;
int a[3333], b[3333], c[3333];
int d[3333][3];

int go(int x, int y) {
  if (x == n)
    return y == 0 ? -(1 << 30) : 0;

  int &r = d[x][y];
  if (r != -1)
    return r;

  if (y) {
    r = max(go(x + 1, 1) + b[x], go(x + 1, 0) + c[x]);
  } else {
    r = max(go(x + 1, 1) + a[x], go(x + 1, 0) + b[x]);
  }
  return r;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    cin >> c[i];

  memset(d, -1, sizeof(d));
  cout << go(0, 0) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
