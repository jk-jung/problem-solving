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
vi e[5555];

bool check(int x) {
  for (int i = 0; i < n; i++) {
    if (i == x || e[i].empty())
      continue;

    if (e[i].size() > 1 || e[i][0] != x)
      return false;
  }
  return true;
}
void solve() {

  cin >> n;

  vector<pi> v(n);
  for (auto &[x, y] : v)
    cin >> x >> y;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (max(v[i].F, v[j].F) < min(v[i].S, v[j].S)) {
        cnt++;
        e[i].pb(j);
        e[j].pb(i);
      }
    }
  }

  vi r;
  for (int i = 0; i < n; i++) {
    if (check(i))
      r.pb(i);
  }

  cout << r.size() << endl;
  for (int x : r)
    cout << x + 1 << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
