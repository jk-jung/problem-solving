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
  ll n, m, k;
  cin >> n >> m >> k;
  DisjointSetUnion d(n);

  for (int i = 0; i <= n - k; i++) {
    for (int a = i, b = i + k - 1; a < b; a++, b--)
      d.unite(a, b);
  }

  ll r = 1;
  for (int i = 0; i < n; i++) {
    if (d.find(i) == i)
      r = (r * m) % 1000000007;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
