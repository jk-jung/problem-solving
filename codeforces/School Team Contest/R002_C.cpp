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
  int n, m;
  cin >> n >> m;
  vi a(n + 5);
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    for (int j = x; j <= y; j++)
      a[j]++;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != 1) {
      cout << i << " " << a[i] << endl;
      return;
    }
  }
  cout << "OK" << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
