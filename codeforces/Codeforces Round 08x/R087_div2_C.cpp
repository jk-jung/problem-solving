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

int n;
vi v[200005];

int dfs(int x) {
  int r = 0;
  for (int y : v[x])
    r = max(r, dfs(y));
  return r + 1;
}
void solve() {
  cin >> n;
  vi root;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    if (x != -1)
      v[x - 1].pb(i);
    else
      root.pb(i);
  }
  int r = 0;
  for (int x : root)
    r = max(r, dfs(x));
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
