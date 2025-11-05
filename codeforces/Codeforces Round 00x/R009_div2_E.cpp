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
vi v[100005];
int vis[100005];

vi leaf;

void dfs(int x, int y = -1) {
  if (vis[x]) {
    cout << "NO\n";
    exit(0);
  }
  vis[x] = 1;

  if (v[x].size() >= 3) {
    cout << "NO\n";
    exit(0);
  }
  if (v[x].size() <= 1)
    leaf.pb(x);

  for (int z : v[x]) {
    if (z == y)
      continue;
    if (!vis[z])
      dfs(z, x);
  }
}

void solve() {
  cin >> n >> m;

  int self = 0;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
    if (x == y)
      self++;
  }

  if (n == 1) {
    if (m == 0)
      cout << "YES\n1\n1 1";
    else if (self == 1)
      cout << "YES\n0";
    else
      cout << "NO\n";
    return;
  }
  if (self) {
    cout << "NO\n";
    return;
  }

  vector<vi> t;

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      sort(leaf.begin(), leaf.end());
      if (leaf.size() == 1)
        leaf.pb(leaf[0]);
      t.pb(leaf);
      leaf.clear();
    }
  }
  sort(t.begin(), t.end());

  if (t.size() == 1) {
    cout << "YES\n";
    if (t[0].size() == 0)
      cout << "0";
    else
      cout << "1\n" << t[0][0] << " " << t[0][1];
  } else {
    if (t[0].size() == 0) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    cout << t.size() << endl;
    while (!t.empty()) {
      if (t.size() == 1) {
        cout << t[0][0] << " " << t[0][1] << endl;
        break;
      }
      cout << t[0][0] << " " << t[1][0] << endl;
      vi k = {t[0][1], t[1][1]};
      sort(k.begin(), k.end());
      t.pb(k);
      t.erase(t.begin());
      t.erase(t.begin());
      sort(t.begin(), t.end());
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
