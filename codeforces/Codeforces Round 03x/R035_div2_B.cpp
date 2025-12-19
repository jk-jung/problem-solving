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

int n, m, q;
map<string, pi> t;
bool st[55][55];

void solve() {
  cin >> n >> m >> q;
  while (q--) {
    string op, id;
    cin >> op;
    if (op == "+1") {
      int x, y;
      cin >> y >> x >> id;
      for (int i = y; i <= n; i++) {
        for (int j = i == y ? x : 1; j <= m; j++) {
          if (st[i][j])
            continue;
          st[i][j] = true;
          t[id] = {i, j};
          goto end;
        }
      }
    end:;
    } else {
      cin >> id;
      if (t.find(id) == t.end()) {
        cout << "-1 -1" << endl;
      } else {
        auto [y, x] = t[id];
        st[y][x] = false;
        t.erase(id);
        cout << y << " " << x << endl;
      }
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
