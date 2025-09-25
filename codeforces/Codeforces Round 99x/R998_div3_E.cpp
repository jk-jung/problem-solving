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

class DisjointSetUnion {
public:
  vector<int> p, size;

  DisjointSetUnion(int _n = 0) { init(_n); }

  void init(int _n) {
    p.resize(_n), iota(p.begin(), p.end(), 0);
    size.resize(_n), fill(size.begin(), size.end(), 1);
  }

  int find(int x) { return p[x] != x ? p[x] = find(p[x]) : x; }

  void unite(int x, int y) {
    if (is_same_set(x, y))
      return;
    x = find(x), y = find(y);
    if (size[x] > size[y])
      swap(x, y);
    p[x] = p[y], size[y] += size[x];
  }

  int get_size(int x) { return size[find(x)]; }

  bool is_same_set(int x, int y) { return find(x) == find(y); }
};

void solve() {
  int n, m1, m2;
  cin >> n >> m1 >> m2;
  vector<pi> e1(m1), e2(m2);
  DisjointSetUnion d1(n), d2(n);
  for (auto &[x, y] : e1) {
    cin >> x >> y;
    x--, y--;
  }
  for (auto &[x, y] : e2) {
    cin >> x >> y;
    x--, y--;
    d2.unite(x, y);
  }

  int r = 0;
  for (auto [x, y] : e1) {
    if (!d2.is_same_set(x, y))
      r++;
    else
      d1.unite(x, y);
  }
  for (auto [x, y] : e2) {
    if (!d1.is_same_set(x, y)) {
      d1.unite(x, y);
      r++;
    }
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
