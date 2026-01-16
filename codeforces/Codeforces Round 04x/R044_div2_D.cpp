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
set<int> cur;
vector<set<int>> comb;

void dfs(int x, int cnt) {
  if (x == n) {
    if (cnt == 0)
      comb.pb(cur);
    return;
  }

  if (cnt) {
    cur.insert(x);
    dfs(x + 1, cnt - 1);
    cur.erase(x);
  }
  dfs(x + 1, cnt);
}

void solve() {
  cin >> n >> m;
  vector<string> v(m);
  vi c(m);
  for (int i = 0; i < m; i++)
    cin >> v[i] >> c[i];

  dfs(0, c[0]);

  int r = 0;
  for (auto &x : comb) {
    bool ok = true;
    for (int k = 1; k < m; k++) {
      int cnt = 0;
      for (int i = 0; i < n; i++) {
        char t = x.count(i) ? v[0][i] : (v[0][i] ^ '0' ^ '1');
        if (t == v[k][i])
          cnt++;
      }
      if (cnt != c[k]) {
        ok = false;
        break;
      }
    }
    if (ok)
      r++;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
