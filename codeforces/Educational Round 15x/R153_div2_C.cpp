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

template <typename Node> class IndexTree {
public:
  int n, size;
  vector<Node> d;

  IndexTree(int _n) { init(_n); }

  void init(int _n) {
    n = _n;
    size = 1 << (32 - __builtin_clz(n));
    d.resize(size * 2 + 5);
  }

  void up(int x, Node v) {
    x += size;
    while (x)
      d[x].up(v), x >>= 1;
  }

  Node read(int s, int e) {
    s += size, e += size;
    Node r;
    while (s <= e) {
      if ((s & 1) == 1)
        r.up(d[s++]);
      if ((e & 1) == 0)
        r.up(d[e--]);
      s >>= 1, e >>= 1;
    }
    return r;
  }
};

struct MaxNode {
  ll max_v;

  MaxNode(ll b = 0) { max_v = b; }

  void up(MaxNode &t) { max_v = max(max_v, t.max_v); }
};

void solve() {
  int n;
  cin >> n;

  vi v(n);
  for (int &x : v)
    cin >> x, x--;
  vi c(n);

  IndexTree<MaxNode> tr(n);
  int r = 0;
  for (int i = 0; i < n; i++) {
    c[i] = tr.read(0, v[i]).max_v + 1;
    tr.up(v[i], MaxNode(c[i]));
    if (c[i] == 2)
      r++;
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
