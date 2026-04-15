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

int n, m, k;
vi v[100005];
int idx[100005];
vi cur;

void dfs(int x, int dep) {
  cur.pb(x);
  idx[x] = dep;
  for (int y : v[x]) {
    if (idx[y] == 0)
      dfs(y, dep + 1);
    else if (dep - idx[y] >= k) {
      cout << dep - idx[y] + 1 << endl;
      while (cur.back() != y)
        cout << cur.back() << " ", cur.pop_back();
      cout << y << endl;
      exit(0);
    }
  }
  cur.pop_back();
}

void solve() {
  cin >> n >> m >> k;
  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y;
    v[x].pb(y);
    v[y].pb(x);
  }
  dfs(1, 0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
