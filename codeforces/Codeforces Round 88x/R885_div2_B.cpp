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
  int n, m;
  cin >> n >> m;
  vi v(n);
  for (int &x : v)
    cin >> x;

  map<int, int> ck;
  map<int, vi> rst;
  for (int i = 0; i < n; i++) {
    int x = v[i];
    int pos = i + 1;
    int diff = pos - ck[x] - 1;
    rst[x].pb(diff);
    ck[x] = pos;
  }
  for (auto [k, v] : rst) {
    int pos = n + 1;
    int diff = pos - ck[k] - 1;
    rst[k].pb(diff);
    ck[k] = pos;
  }

  int r = 1 << 30;
  for (auto [k, v] : rst) {
    sort(v.rbegin(), v.rend());
    r = min(r, v.size() == 1 ? v[0] / 2 : max(v[0] / 2, v[1]));
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
