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
  int n;
  cin >> n;

  vector<pi> v;
  for (int i = 1, s, e; i <= n; i++) {
    cin >> s >> e;
    if (s > e)
      swap(s, e);
    v.pb(mp(s, -i));
    v.pb(mp(e, +i));
  }
  sort(v.begin(), v.end());
  vi r;

  set<int> s;
  set<int> covered;
  for (int i = 0; i < v.size();) {
    int j = i;
    int x = v[i].F;
    while (j < v.size() && v[j].F == x && v[j].S < 0)
      s.insert(-v[j++].S);

    bool need = false;
    while (j < v.size() && v[j].F == x && v[j].S > 0) {
      int idx = v[j++].S;
      if (!covered.count(idx))
        need = true;
    }
    if (need) {
      r.pb(x);
      for (int k : s)
        covered.insert(k);
      s.clear();
    }
    i = j;
  }
  cout << r.size() << endl;
  for (int x : r)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
