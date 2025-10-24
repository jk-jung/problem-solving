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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

char a[1005][1005];
void solve() {
  int n, m;
  char k;
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    string x;
    cin >> x;
    for (int j = 1; j <= m; j++)
      a[i][j] = x[j - 1];
  }

  set<char> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] != k)
        continue;
      for (int t = 0; t < 4; t++) {
        int y = i + dy[t];
        int x = j + dx[t];
        if (a[y][x] && a[y][x] != k && a[y][x] != '.')
          s.insert(a[y][x]);
      }
    }
  }
  cout << s.size() << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
