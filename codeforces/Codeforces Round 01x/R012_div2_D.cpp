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
int r = 0;
map<int, vector<pi>> v;
set<pi> s;

void solve() {
  cin >> n;
  s.insert(mp(-1, 1 << 30));
  s.insert(mp(1 << 30, -1));

  vi X(n), Y(n), Z(n);
  for (int &x : X)
    cin >> x;
  for (int &y : Y)
    cin >> y;
  for (int &z : Z)
    cin >> z;

  for (int i = 0; i < n; i++) {
    v[-X[i]].pb({Y[i], Z[i]});
  }

  for (auto [x, points] : v) {
    sort(points.rbegin(), points.rend());

    for (auto [y, z] : points) {
      auto it = s.lower_bound({y + 1, 0});
      if (z < it->S)
        r++;
    }
    int max_z = -1;
    for (auto [y, z] : points) {
      if (z <= max_z)
        continue;
      max_z = z;
      auto it = s.lower_bound({y + 1, 0});
      if (z <= it->S)
        continue;

      while (it->F > y)
        it--;
      if ((*it) >= mp(y, z))
        continue;
      vector<pi> rm;
      while (it->S <= z) {
        rm.pb(*it);
        it--;
      }
      for (auto p : rm)
        s.erase(p);

      s.insert({y, z});
    }
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
