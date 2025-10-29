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

map<int, int> cnt;

void add(int x) { cnt[x]++; }
void remove(int x) {
  if (--cnt[x] == 0)
    cnt.erase(x);
}
int diff(int x) {
  if (cnt.empty())
    return 0;
  int m = min(x, cnt.begin()->F);
  int M = max(x, cnt.rbegin()->F);
  return M - m;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vi v(n);
  for (int &x : v)
    cin >> x;

  int r = 0;
  vector<pi> t;
  for (int i = 0, j = 0; i < n; i++) {
    while (j < n && diff(v[j]) <= k)
      add(v[j++]);

    int l = j - i;
    if (r < l) {
      r = l;
      t = {mp(i, j)};
    } else if (r == l) {
      t.pb(mp(i, j));
    }
    remove(v[i]);
  }

  cout << r << " " << t.size() << endl;
  for (auto [x, y] : t)
    cout << x + 1 << " " << y << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
