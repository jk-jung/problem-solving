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
int L[555], R[555];
void solve() {
  int n, m;
  cin >> n >> m;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    L[i] = 1 << 30;
    R[i] = -1;
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'W') {
        cnt++;
        L[i] = min(L[i], j);
        R[i] = j;
      }
    }
  }

  int x = 0;
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i][x] == 'W')
      cnt--;

    if (i % 2 == 0) {
      int pos = R[i];
      if (i + 1 < n)
        pos = max(pos, R[i + 1]);
      if (pos != -1) {
        while (x < pos) {
          r++;
          if (a[i][++x] == 'W')
            cnt--;
        }
      }
    } else {
      int pos = L[i];
      if (i + 1 < n)
        pos = min(pos, L[i + 1]);
      if (pos < m + 1) {
        while (x > pos) {
          r++;
          if (a[i][--x] == 'W')
            cnt--;
        }
      }
    }

    if (cnt == 0)
      break;
    r++;
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
