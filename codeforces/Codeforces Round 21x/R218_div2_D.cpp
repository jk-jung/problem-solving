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

void solve() {
  int n, m;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;
  cin >> m;
  map<int, int> remain;
  for (int i = 0; i < n; i++)
    remain[i] = v[i];

  while (m--) {
    int o, x, y;
    cin >> o >> x;
    x--;
    if (o == 1) {
      cin >> y;

      vi rm;
      auto it = remain.lower_bound(x);
      while (it != remain.end() && y) {
        int t = min(it->second, y);
        it->second -= t;
        y -= t;
        if (!it->second)
          rm.pb(it->first);
        it++;
      }
      for (int x : rm)
        remain.erase(x);
    } else {
      if (remain.count(x)) {
        cout << v[x] - remain[x] << endl;
      } else {
        cout << v[x] << endl;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
