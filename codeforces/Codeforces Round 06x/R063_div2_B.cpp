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
int s[1005];
int e[1005];
int t[1005];
int c[1005];
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
    cin >> s[i] >> e[i] >> t[i] >> c[i];
  int r = 0;
  for (int i = 1; i <= n; i++) {
    int max_c = 0, max_t = 1 << 30;
    for (int j = 0; j < m; j++) {
      if (s[j] <= i && e[j] >= i) {
        if (t[j] < max_t) {
          max_c = c[j];
          max_t = t[j];
        }
      }
    }
    r += max_c;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
