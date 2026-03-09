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

class IndexTree {
public:
  int n, size;
  vector<ll> d;

  IndexTree(int _n) { init(_n); }

  void init(int _n) {
    if (_n <= 0)
      return;
    n = _n;
    size = 1 << (32 - __builtin_clz(n));
    d.resize(size * 2 + 5);
  }

  void up(int x, ll v) {
    x += size;
    while (x)
      d[x] += v, x >>= 1;
  }

  ll read(int s, int e) {
    s += size, e += size;
    ll r = 0;
    while (s <= e) {
      if ((s & 1) == 1)
        r += d[s++];
      if ((e & 1) == 0)
        r += d[e--];
      s >>= 1, e >>= 1;
    }
    return r;
  }

  int kth(ll k) {
    int x = 1;
    while (x < size) {
      if (d[x * 2] < k)
        k -= d[x * 2], x = x * 2 + 1;
      else
        x *= 2;
    }
    return min(x - size, n - 1);
  }
};

void solve() {
  int n, c;
  cin >> n >> c;
  vi a(n), L(n), R(n);
  vector<pi> C(n), LL(n);
  for (int &x : a)
    cin >> x;
  for (int i = 0; i < n; i++) {
    L[i] = a[i] + i + 1;
    R[i] = a[i] + n - i;
    C[i] = {min(L[i], R[i]), i};
    LL[i] = {L[i], i};
  }
  IndexTree tre(n);
  map<int, int> mp;
  sort(C.begin(), C.end());
  for (int i = 0; i < n; i++) {
    auto [cost, idx] = C[i];
    tre.up(i, cost);
    mp[idx] = i;
  }

  sort(LL.begin(), LL.end());
  int r = 0;
  for (auto [cost, idx] : LL) {
    ll remain = c - cost;
    if (remain < 0)
      break;

    int tre_idx = mp[idx];

    ll current = tre.read(tre_idx, tre_idx);
    tre.up(tre_idx, -current);

    int k = tre.kth(remain);
    if (tre.read(0, k) > remain)
      k--;
    if (tre_idx <= k)
      k--;

    r = max(r, 1 + k + 1);

    tre.up(tre_idx, current);
  }

  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
