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
int d[26][26][500];
pi from[26][26][500];
vector<tuple<int, int, int>> t;

int get_count(int i, int j, string &s) {
  int v = 0;
  for (int k = 0; k < m; k++) {
    char x = k % 2 == 0 ? i + 'a' : j + 'a';
    v += s[k] != x;
  }
  return v;
}

void trace(int y, int x, int r) {
  if (r == -1)
    return;

  auto [y2, x2] = from[y][x][r];
  trace(y2, x2, r - 1);
  for (int i = 0; i < m; i++) {
    cout << (i % 2 == 0 ? char(y + 'a') : char(x + 'a'));
  }
  cout << endl;
}

void solve() {

  cin >> n >> m;
  string s;
  memset(d, 63, sizeof(d));
  cin >> s;
  for (int i = 0; i < 26; i++) {
    for (int j = 0; j < 26; j++) {
      if (i == j)
        continue;

      d[i][j][0] = get_count(i, j, s);
      t.pb({d[i][j][0], i, j});
    }
  }
  sort(t.begin(), t.end());
  if (n == 1) {
    cout << get<0>(t[0]) << endl;
    int x = get<1>(t[0]);
    int y = get<2>(t[0]);
    for (int i = 0; i < m; i++) {
      cout << (i % 2 == 0 ? char(x + 'a') : char(y + 'a'));
    }
    cout << endl;
    return;
  }

  int R = 1 << 30;
  int sx, sy;
  for (int r = 1; r < n; r++) {
    cin >> s;
    sort(t.begin(), t.end());
    vector<tuple<int, int, int>> t2;
    for (int i = 0; i < 26; i++) {
      for (int j = 0; j < 26; j++) {
        if (i == j)
          continue;
        int v = get_count(i, j, s);

        for (auto &[x, y, z] : t) {
          if (i != y && j != z) {
            d[i][j][r] = v + x;
            from[i][j][r] = {y, z};
            t2.pb({d[i][j][r], i, j});
            if (r == n - 1 && d[i][j][r] < R) {
              sx = j;
              sy = i;
              R = min(R, d[i][j][r]);
            }
            break;
          }
        }
      }
    }
    t = t2;
  }
  cout << R << endl;
  trace(sy, sx, n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
