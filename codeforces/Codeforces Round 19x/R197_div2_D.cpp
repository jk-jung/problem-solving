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
int d[1 << 20];

void solve() {
  cin >> n >> m;
  n = 1 << n;
  for (int i = n; i < n + n; i++)
    cin >> d[i];
  int flag = 1;
  for (int i = n - 1; i >= 1; i--) {
    if (flag)
      d[i] = d[i * 2] | d[i * 2 + 1];
    else
      d[i] = d[i * 2] ^ d[i * 2 + 1];

    if ((i & (i - 1)) == 0)
      flag ^= 1;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    int x = n + a - 1;
    d[x] = b;
    x /= 2;
    flag = 1;
    while (x >= 1) {
      if (flag)
        d[x] = d[x * 2] | d[x * 2 + 1];
      else
        d[x] = d[x * 2] ^ d[x * 2 + 1];
      flag ^= 1;
      x /= 2;
    }
    cout << d[1] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
