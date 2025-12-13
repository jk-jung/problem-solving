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

char a[555][555];
char b[5][5];
int n, k;

void go(int oy, int ox, int y, int x, char t, int d = 1) {
  if (d == k) {
    a[oy][ox] = t == '*' ? '*' : b[y][x];
    return;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      go(oy * n + i, ox * n + j, i, j, t == '*' ? '*' : b[i][j], d + 1);
    }
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      go(i, j, i, j, b[i][j]);

  for (int i = 0;; i++) {
    if (!a[i][0])
      break;
    cout << a[i] << endl;
  }
}

int main() {
  // freopen("input.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
