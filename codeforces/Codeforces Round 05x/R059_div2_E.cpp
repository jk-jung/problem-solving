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

int d[1 << 20];
vi len = {3, 4, 5, 4, 3};
vi pre = {0, 0, 0, 1, 2};

int dx[] = {1, 0, 1};
int dy[] = {0, 1, 1};

int go(int st) {
  if (st == 0)
    return 0;

  int &r = d[st];
  if (r != -1)
    return r;

  int a[5][5];
  int b[5][5];

  memset(a, 0, sizeof(a));
  for (int i = 0, idx = 0; i < 5; i++) {
    for (int j = 0; j < len[i]; j++, idx++) {
      a[i][pre[i] + j] = (st >> idx & 1);
      b[i][pre[i] + j] = 1 << idx;
    }
  }

  int ok = 0;
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (a[i][j]) {
        int nxt = st ^ b[i][j];

        if (go(nxt) == 0)
          ok = 1;
        for (int k = 0; k < 3; k++) {
          int nxt2 = nxt;
          int y = i;
          int x = j;
          while (true) {
            y += dy[k];
            x += dx[k];

            if (y >= 5 || x >= 5 || a[y][x] == 0)
              break;

            nxt2 ^= b[y][x];
            if (go(nxt2) == 0)
              ok = 1;
          }
        }
      }
    }
  }

  return r = ok;
}

void solve() {
  memset(d, -1, sizeof(d));
  int st = 0;
  for (int i = 0; i < 19; i++) {
    char x;
    cin >> x;
    if (x == 'O')
      st |= (1 << i);
  }
  cout << (go(st) ? "Karlsson" : "Lillebror") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
