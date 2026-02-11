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
  int n;
  cin >> n;
  vi a(n), b(n), c(30);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 30; j++) {
      if (a[i] >> j & 1)
        c[j] ^= 1;
      if (b[i] >> j & 1)
        c[j] ^= 1;
    }
  }

  int idx = -1;
  for (int j = 29; j >= 0; j--) {
    if (c[j]) {
      idx = j;
      break;
    }
  }
  if (idx == -1) {
    cout << "Tie\n";
    return;
  }
  int last = -1;
  for (int i = 0; i < n; i++) {
    int x = a[i] >> idx & 1;
    int y = b[i] >> idx & 1;
    if (x + y == 1)
      last = i;
  }
  cout << (last % 2 ? "Mai" : "Ajisai") << endl;
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
