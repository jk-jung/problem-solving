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

string a, b;
int n;
char t[55][5];
int d[55][55];

bool can1[26][55][55];
bool can2[26][55][55];

void calc(string &s, bool can[26][55][55]) {
  int m = s.size();
  for (int len = 1; len <= m; len++) {
    for (int i = 0; i <= m - len; i++) {
      for (int c = 0; c <= 26; c++) {

        if (len == 1) {
          can[c][i][i] = s[i] - 'a' == c;
        } else {
          int k = i + len - 1;
          for (int j = i; j < k; j++) {
            for (int q = 0; q < n; q++) {
              int x = t[q][0] - 'a';
              int y = t[q][1] - 'a';
              int z = t[q][2] - 'a';
              if (x != c)
                continue;

              can[x][i][k] |= can[y][i][j] && can[z][j + 1][k];
            }
          }
        }
      }
    }
  }
}

int go(int x, int y) {
  if (x == a.size() && y == b.size())
    return 0;

  int &r = d[x][y];
  if (r != -1)
    return r;

  r = 1 << 30;

  for (int i = x; i < a.size(); i++) {
    for (int j = y; j < b.size(); j++) {
      for (int c = 0; c < 26; c++) {
        if (can1[c][x][i] && can2[c][y][j]) {
          r = min(r, go(i + 1, j + 1) + 1);
        }
      }
    }
  }
  return r;
}

void solve() {
  cin >> a >> b >> n;
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    t[i][0] = x[0];
    t[i][1] = x[3];
    t[i][2] = x[4];
  }

  calc(a, can1);
  calc(b, can2);

  memset(d, -1, sizeof(d));
  int r = go(0, 0);
  if (r >= (1 << 30))
    r = -1;
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
