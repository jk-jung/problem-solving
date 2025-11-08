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

int a[555][555];
int n, m, c;
int cc[555];

int f(vi x) {
  int s = 0;
  for (int i = x[1]; i <= x[2]; i++)
    s += ab(i - c) + ab(x[0] - c);
  return s;
}

bool sf(vi a, vi b) {
  if (f(a) == f(b))
    return a < b;
  return f(a) < f(b);
}
void solve() {
  cin >> n >> m;
  vi t;
  c = m / 2;
  for (int i = 0; i < m; i++)
    cc[i] = m;

  for (int _ = 0, x; _ < n; _++) {
    cin >> x;

    vector<vi> k;
    for (int i = 0; i < m; i++) {
      if (cc[i] < x)
        continue;
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j])
          cnt = 0;
        else
          cnt++;
        if (cnt >= x)
          k.pb({f({i, j - x + 1, j}), i, j - x + 1, j});
      }
    }

    if (k.empty()) {
      cout << "-1\n";
    } else {
      sort(k.begin(), k.end());
      int y = k[0][1];
      int s = k[0][2];
      int e = k[0][3];
      for (int i = s; i <= e; i++) {
        a[y][i] = 1;
        cc[y]--;
      }

      cout << y + 1 << " " << s + 1 << " " << e + 1 << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
