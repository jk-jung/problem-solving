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

int a[1005], b[1005];
int v[1005][1005];
void solve() {
  int n, m, t;
  cin >> n >> m >> t;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      cin >> v[i][j];
  for (int i = 1; i <= 1000; i++)
    a[i] = b[i] = i;
  while (t--) {
    char op;
    int x, y;
    cin >> op >> x >> y;
    if (op == 'c')
      swap(a[x], a[y]);
    if (op == 'r')
      swap(b[x], b[y]);
    if (op == 'g')
      cout << v[a[x]][b[y]] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
