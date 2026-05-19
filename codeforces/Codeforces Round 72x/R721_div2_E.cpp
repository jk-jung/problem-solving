#include <algorithm>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
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

class SegmentTree {
public:
  vector<int> vv, vp;
  int max_n;

  void init(int _max_n) {
    max_n = _max_n;
    int size = 1;
    for (; size < max_n; size *= 2)
      ;
    vv.clear(), vv.resize(size * 2 + 5);
    vp.clear(), vp.resize(size * 2 + 5);
  }

  void build(int *d) { build(d, 0, 1, max_n); }

  void build(int *d, int k, int l, int r) {
    if (r < l)
      return;
    if (l == r)
      vv[k] = *(d + l - 1);
    else {
      int m = (l + r) / 2;
      build(d, k * 2 + 1, l, m);
      build(d, k * 2 + 2, m + 1, r);
      update(k, l, r);
    }
  }

  void up(int s, int e, int v) { up(s, e, v, 0, 1, max_n); }

  void up(int s, int e, int v, int k, int l, int r) {
    push_down(k, l, r);
    if (r < l || r < s || e < l)
      return;
    if (s <= l && r <= e) {
      if (vv[k] == 1 << 30)
        vv[k] = 0;
      vv[k] += v;
      vp[k] += v;
    } else {
      int m = (l + r) / 2;
      up(s, e, v, k * 2 + 1, l, m);
      up(s, e, v, k * 2 + 2, m + 1, r);
      update(k, l, r);
    }
  }

  void update(int k, int l, int r) {
    if (l != r) {
      vv[k] = min(vv[k * 2 + 1], vv[k * 2 + 2]);
    }
  }

  void push_down(int k, int l, int r) {
    if (l != r) {
      int ll = k * 2 + 1, rr = k * 2 + 2;
      if (vv[ll] == 2000000000)
        vv[ll] = 0;
      if (vv[rr] == 2000000000)
        vv[rr] = 0;
      vv[ll] += vp[k];
      vv[rr] += vp[k];
      vp[ll] += vp[k];
      vp[rr] += vp[k];
    }
    vp[k] = 0;
  }

  int read(int s, int e) { return read(s, e, 0, 1, max_n); }

  int read(int s, int e, int k, int l, int r) {
    push_down(k, l, r);
    int rst = 2000000000;
    if (r < l || r < s || e < l)
      return rst;
    if (s <= l && r <= e)
      rst = vv[k];
    else {
      int m = (l + r) / 2;
      rst = min(rst, read(s, e, k * 2 + 1, l, m));
      rst = min(rst, read(s, e, k * 2 + 2, m + 1, r));
    }
    return rst;
  }
};

int n, k;
int v[35005];
int last[35005];
int ck[35005], CK = 1;
int d[102][35005];

void solve() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
    cin >> v[i];

  for (int i = 1; i <= n; i++) {
    d[1][i] = d[1][i - 1];
    if (ck[v[i]] == CK)
      d[1][i] += i - last[v[i]];
    last[v[i]] = i;
    ck[v[i]] = CK;
  }
  SegmentTree seg;
  seg.init(n + 1);
  for (int t = 2; t <= k; t++) {
    CK++;
    for (int i = 0; i < seg.vv.size(); i++) {
      seg.vv[i] = 2000000000;
      seg.vp[i] = 0;
    }
    seg.build(d[t - 1]);
    for (int i = t; i <= n; i++) {
      if (ck[v[i]] == CK)
        seg.up(t, last[v[i]], i - last[v[i]]);
      last[v[i]] = i;
      ck[v[i]] = CK;

      d[t][i] = seg.read(t, i);
    }
  }

  cout << d[k][n] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solve();
}
