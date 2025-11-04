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

int x, y, n;
int d[1 << 24];
int f[1 << 24];
pi v[555];

int dis(int a, int b) {
  return (v[a].F - v[b].F) * (v[a].F - v[b].F) +
         (v[a].S - v[b].S) * (v[a].S - v[b].S);
}

int go(int mask) {
  if (mask == 0)
    return 0;

  int &r = d[mask];
  if (r != -1)
    return r;
  r = 1 << 30;

  vi q;
  for (int i = 0; i < n; i++)
    if (mask >> i & 1)
      q.pb(i);

  for (int x = 0; x < q.size(); x++) {
    int i = q[x];

    int nxt = mask ^ (1 << i);
    int c = dis(n, i) * 2;
    if (r > go(nxt) + c) {
      r = go(nxt) + c;
      f[mask] = i + 1;
    }
    for (int y = x + 1; y < q.size(); y++) {
      int j = q[y];
      int nxt = mask ^ (1 << j) ^ (1 << i);
      int c = dis(n, i) + dis(i, j) + dis(j, n);
      if (r > go(nxt) + c) {
        r = go(nxt) + c;
        f[mask] = (j + 1) * 100 + i + 1;
      }
    }
    break;
  }

  return r;
}
void solve() {
  memset(d, -1, sizeof(d));
  cin >> x >> y >> n;
  for (int i = 0; i < n; i++)
    cin >> v[i].F >> v[i].S;
  v[n] = {x, y};

  int st = (1 << n) - 1;
  cout << go(st) << endl;
  cout << "0 ";
  while (st) {
    int nxt = st;
    vi t;
    t.pb(f[st] % 100);
    if (f[st] >= 100)
      t.pb(f[st] / 100);
    for (int i : t) {
      cout << i << " ";
      nxt ^= (1 << (i - 1));
    }
    cout << "0 ";
    st = nxt;
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
