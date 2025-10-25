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

int n, m = 0;
int a[1000006];
ll calc2(vi &cur, bool same) {
  int t = -1;
  ll r = 0;
  set<int> S;
  for (int i = 0; i < cur.size(); i++) {
    int x = cur[i];
    if (x >= t) {
      t = x;
      r++;
      S.insert(i);
    }
  }
  t = -1;
  for (int i = cur.size() - 1; i >= 0; i--) {
    int x = cur[i];
    if (x >= t) {
      t = x;
      r++;
      S.insert(i);
    }
  }
  return same ? S.size() : r;
}

ll calc(vi &cur) {
  ll r = 0;

  r += calc2(cur, cur.size() + 1 == n);

  vector<pi> v;
  for (int x : cur) {
    while (!v.empty() && v.back().F < x) {
      r += v.back().S;
      v.pop_back();
    }

    if (v.empty())
      v.pb(mp(x, 1));
    else if (v.back().F == x) {
      r += v.back().S;
      if (v.size() > 1)
        r++;
      v.back().S++;

    } else if (v.back().F > x) {
      v.pb(mp(x, 1));
      r++;
    }
  }

  return r;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a[i], m = max(m, a[i]);

  vi top;
  for (int i = 0; i < n; i++) {
    if (a[i] == m)
      top.pb(i);
  }
  ll c = top.size();
  ll r = c * (c - 1) / 2;
  for (int i = 0; i < c; i++) {
    int s = top[i], e = top[(i + 1) % c];

    vi cur;
    s = (s + 1) % n;
    while (s != e) {
      cur.pb(a[s]);
      s = (s + 1) % n;
    }

    r += calc(cur);
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
