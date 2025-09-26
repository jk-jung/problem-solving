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
  int n, m, k;
  cin >> n >> m >> k;
  bool ok = false;
  if (n < m)
    swap(n, m), ok = true;
  vector<vi> v(n, vi(m));
  int cnt = n * m / k;
  int idx = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 0)
        v[i][j] = idx++ / cnt;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if ((i + j) % 2 == 1)
        v[i][j] = idx++ / cnt;
    }
  }
  if (ok) {
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << v[j][i] + 1 << " ";
      }
      cout << endl;
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << v[i][j] + 1 << " ";
      }
      cout << endl;
    }
  }
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
