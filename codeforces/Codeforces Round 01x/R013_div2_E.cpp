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

int n, m, sz = 320;
int nxt[100005];
int cnt[100005];
int lst[100005];
int a[100005];

int get_i(int x) {
  if (x >= n)
    return 100000000;
  return x / sz;
}

void build(int idx) {
  int s = idx * sz;
  int e = min(n, s + sz) - 1;
  for (int i = e; i >= s; i--) {
    int nt = i + a[i];
    if (get_i(nt) != idx) {
      cnt[i] = 1;
      nxt[i] = nt;
      lst[i] = i;
    } else {
      cnt[i] = cnt[nt] + 1;
      nxt[i] = nxt[nt];
      lst[i] = lst[nt];
    }
  }
}

void build() {
  for (int i = 0; i < n; i += sz) {
    build(get_i(i));
  }
}

void update(int x, int y) {
  a[x] = y;
  build(get_i(x));
}

pi query(int x) {
  int r = 0, pos = x;
  while (x < n) {
    r += cnt[x];
    pos = lst[x];
    x = nxt[x];
  }
  return {pos + 1, r};
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++)
    cin >> a[i];

  build();

  while (m--) {
    int op, x, y;
    cin >> op >> x;
    x--;
    if (op == 0) {
      cin >> y;
      update(x, y);
    } else {
      auto [pos, c] = query(x);
      cout << pos << " " << c << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}