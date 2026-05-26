#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
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
  vi v(n);
  for (int &x : v)
    cin >> x;

  vector<vi> r;
  r.pb(v);
  while (true) {
    vi cnt(n + 1), b(n);
    for (int x : r.back()) {
      cnt[x]++;
    }
    bool changed = false;
    for (int i = 0; i < n; i++) {
      int t = r.back()[i];
      if (t != cnt[t])
        changed = true;
      b[i] = cnt[t];
    }
    if (!changed)
      break;
    r.pb(b);
  }

  int q;
  cin >> q;
  while (q--) {
    int x, k;
    cin >> x >> k;
    x--;
    k = min(k, (int)r.size() - 1);
    cout << r[k][x] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
