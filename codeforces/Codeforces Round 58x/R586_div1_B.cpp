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

int a[1005][1005];
ll v[1005];
int n;
void check(int x) {
  v[0] = x;
  for (int i = 1; i < n; i++)
    v[i] = a[0][i] / x;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j)
        continue;
      if ((ll)a[i][j] != v[i] * v[j])
        return;
    }
  }

  for (int i = 0; i < n; i++)
    cout << v[i] << " ";
  exit(0);
}
void solve() {

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> a[i][j];

  int g = a[0][0];
  for (int i = 1; i < n; i++)
    g = gcd(g, a[0][i]);

  for (int x = 1; x * x <= g; x++) {
    if (g % x)
      continue;
    int y = g / x;

    check(x);
    check(y);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
