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

pi nt[111111], st[111111];
int SZ = 0, SZ2 = 0;

void solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;

  map<int, vi> idx;
  int r = 0;
  for (int i = 0; i < n; i++) {
    int k = v[i];

    SZ = 0;
    set<int> used;
    for (int j = 0; j < SZ2; j++) {
      auto [x, y] = st[j];
      if (k == v[y]) {
        nt[SZ++] = {x, y + 1};
        used.insert(y);
      }
    }

    for (auto x : idx[v[i]]) {
      if (x >= r && !used.count(x))
        nt[SZ++] = {i, x + 1};
    }

    bool ck = false;
    for (int j = 0; j < SZ; j++) {
      auto [x, y] = nt[j];
      if (x == y) {
        r = max(r, x);
        ck = true;
      }
    }
    if (ck)
      SZ = 0;
    for (int j = 0; j < SZ; j++)
      st[j] = nt[j];
    SZ2 = SZ;
    idx[k].pb(i);
  }
  cout << n - r << endl;
  for (int i = r; i < n; i++)
    cout << v[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
