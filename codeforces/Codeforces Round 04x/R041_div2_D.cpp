#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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

int r[55][55];
void solve() {
  int n;
  cin >> n;
  vi a;
  set<int> edges;
  a.pb(1);
  for (int i = 1; i < n; i++) {
    for (int x = a.back() + 1;; x++) {
      bool ok = true;
      for (int y : a) {
        if (edges.count(y + x))
          ok = false;
      }
      if (ok) {
        a.pb(x);
        for (int j = 0; j < i; j++) {
          int e = a[j] + x;
          r[i][j] = r[j][i] = e;
          edges.insert(e);
        }
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << r[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
