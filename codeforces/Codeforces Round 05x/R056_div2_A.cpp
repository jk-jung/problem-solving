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

int a[1005];
void solve() {
  int n, m;
  cin >> n >> m;

  for (int k = 0; k < m; k++) {
    string t, b;
    int c;
    cin >> b >> b >> t >> b >> c;
    if (t == "left") {
      for (int i = 1; i < c; i++)
        a[i]++;
    } else {
      for (int i = c + 1; i <= n; i++)
        a[i]++;
    }
  }
  int r = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] == m)
      r++;
  cout << (r == 0 ? -1 : r) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
