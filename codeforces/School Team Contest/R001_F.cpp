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
  int n, m, k;
  cin >> n >> m >> k;
  vi a(m), b(k);
  map<int, vi> r;
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  for (int i = 0; i < m; i++) {
    int f = a[i], c = 0;
    for (int x : b) {
      c += x % f == 0;
    }
    r[c].pb(i + 1);
  }
  for (auto [f, v] : r) {
    cout << v.size() << endl;
    for (int x : v)
      cout << x << " ";
    cout << endl;
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
