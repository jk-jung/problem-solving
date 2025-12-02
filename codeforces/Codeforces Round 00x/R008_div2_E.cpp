#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<double, double> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

ll n, k;
ll d[55][2][2];

string prefix;
string target;

void add(ll &x, ll y) { x = min(x + y, 1ll << 60); }

ll go(int i, int j, int st0 = 0, int st1 = 0) {
  if (i > j)
    return 1;
  ll &r = d[i][st0][st1];
  if (r != -1)
    return r;

  r = 0;
  for (int x = 0; x < 2; x++) {
    for (int y = 0; y < 2; y++) {
      if (i < target.size() && target[i] != '0' + x)
        continue;
      if (j < target.size() && target[j] != '0' + y)
        continue;
      if (i == 0 && x == 1)
        continue;
      if (i == j && x != y)
        continue;

      if (x == 1 && y == 1) {
        // normal:  1 1
        // reverse: 1 1
        // rev-inv: 0 0
        if (st1 == 1)
          add(r, go(i + 1, j - 1, st0, 1));
      } else if (x == 0 && y == 0) {
        // normal:  0 0
        // reverse: 0 0
        // rev-inv: 1 1
        add(r, go(i + 1, j - 1, st0, 1));
      } else if (x > y) {
        // normal:  1 0
        // reverse: 0 1
        // rev-inv: 1 0
        if (st0 == 1)
          add(r, go(i + 1, j - 1, 1, st1));
      } else {
        // normal:  0 1
        // reverse: 1 0
        // rev-inv: 0 1
        add(r, go(i + 1, j - 1, 1, st1));
      }
    }
  }
  return r;
}

ll count(string x) {
  if (x.size() == n) {
    string y = x;
    reverse(y.begin(), y.end());
    if (x > y)
      return 0;
    for (char &c : y)
      c = '0' + ('1' - c);
    return x < y ? 1 : 0;
  }
  memset(d, -1, sizeof(d));
  target = x;
  return go(0, n - 1);
}
void build(int i) {
  if (i == n)
    return;
  if (i == 0) {
    prefix = "0";
    build(i + 1);
  } else {
    ll c0 = count(prefix + '0');
    if (k <= c0) {
      prefix += '0';
      build(i + 1);
    } else {
      k -= c0;
      prefix += '1';
      build(i + 1);
    }
  }
}

void solve() {
  cin >> n >> k;
  k++;
  ll tot = count("0");
  if (k > tot) {
    cout << "-1" << endl;
    return;
  }
  build(0);
  cout << prefix << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
