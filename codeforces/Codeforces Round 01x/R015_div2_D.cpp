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

int v[1005][1005];
ll s[1005][1005];
int m1[1005][1005];
int m2[1005][1005];
bool used[1005][1005];
map<int, int> st;

ll get(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
}

void sub(int x) {
  if (--st[x] == 0)
    st.erase(x);
}
struct Item {
  int y, x;
  ll s;
  bool operator<(const Item &a) const {
    if (s == a.s) {
      if (y == a.y) {
        return x < a.x;
      }
      return y < a.y;
    }
    return s < a.s;
  }
};

void solve() {
  ll n, m, a, b;
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= n; i++) {
    st.clear();
    for (int j = 1, x; j <= m; j++) {
      cin >> v[i][j];
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + v[i][j];
      st[v[i][j]]++;
      if (j >= b) {
        if (j > b)
          sub(v[i][j - b]);
        m1[i][j - b + 1] = st.begin()->F;
      }
    }
  }
  for (int j = 1; j <= m - b + 1; j++) {
    st.clear();
    for (int i = 1; i <= n; i++) {
      st[m1[i][j]]++;
      if (i >= a) {
        if (i > a)
          sub(m1[i - a][j]);
        m2[i - a + 1][j] = st.begin()->F;
      }
    }
  }
  vector<Item> r, rr;
  for (int i = 1; i <= n - a + 1; i++) {
    for (int j = 1; j <= m - b + 1; j++) {
      ll ss = get(i, j, i + a - 1, j + b - 1);
      r.pb({i, j, ss - m2[i][j] * a * b});
    }
  }
  sort(r.begin(), r.end());

  for (auto [y, x, s] : r) {
    if (used[y][x] || used[y + a - 1][x + b - 1] || used[y + a - 1][x] ||
        used[y][x + b - 1])
      continue;
    for (int i = 0; i < a; i++)
      for (int j = 0; j < b; j++)
        used[y + i][x + j] = 1;
    rr.pb({y, x, s});
  }

  cout << rr.size() << endl;
  for (auto &x : rr) {
    cout << x.y << " " << x.x << " " << x.s << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
