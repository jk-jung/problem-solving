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

int a, b, c, d;
char r[105][105];

int dx[] = {0, 0, 1};
int dy[] = {1, -1, 0};

void solve() {
  int a, b, c, d, n;
  cin >> a >> b >> c >> d >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;

  memset(r, '.', sizeof(r));
  for (int i = 0; i < b; i++)
    for (int j = 0; j < a; j++)
      r[i][j] = 0;
  for (int i = 0; i < d; i++)
    for (int j = 0; j < c; j++)
      r[i][j + a] = 0;
  for (int i = 0; i < 105; i++)
    r[i][a + c] = 0;

  int x = 0, y = a % 2 ? b - 1 : 0;
  r[y][x] = 'a', v[0]--;
  for (int i = 0; i < n; i++) {
    char c = 'a' + i;
    while (v[i] > 0) {
      for (int j = 0; j < 3; j++) {
        int nx = x + dx[j];
        int ny = y + dy[j];
        if (ny < 0 || r[ny][nx])
          continue;

        r[ny][nx] = c;
        x = nx;
        y = ny;
        v[i]--;
        break;
      }
    }
  }

  cout << "YES" << endl;
  for (int i = 0; i < max(b, d); i++)
    cout << r[i] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
