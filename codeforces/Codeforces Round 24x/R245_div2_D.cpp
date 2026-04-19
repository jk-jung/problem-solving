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

int n, m;
int a[1005][1005];
int d1[1005][1005];
int d2[1005][1005];
int d3[1005][1005];
int d4[1005][1005];

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++)
      cin >> a[i + 1][j + 1];
  }

  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      d1[i][j] = max(d1[i - 1][j], d1[i][j - 1]) + a[i][j];

  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      d2[i][j] = max(d2[i + 1][j], d2[i][j + 1]) + a[i][j];

  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= m; j++)
      d3[i][j] = max(d3[i + 1][j], d3[i][j - 1]) + a[i][j];

  for (int i = 1; i <= n; i++)
    for (int j = m; j >= 1; j--)
      d4[i][j] = max(d4[i - 1][j], d4[i][j + 1]) + a[i][j];

  int r = 0;
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 2; j <= m - 1; j++) {
      r = max(r, d1[i - 1][j] + d2[i + 1][j] + d3[i][j - 1] + d4[i][j + 1]);
      r = max(r, d1[i][j - 1] + d2[i][j + 1] + d3[i + 1][j] + d4[i - 1][j]);
    }
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
