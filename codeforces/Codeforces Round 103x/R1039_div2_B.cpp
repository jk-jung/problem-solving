#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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
  int n;
  cin >> n;
  vector<int> v(n);
  for (int &x : v)
    cin >> x;
  string r = "L";
  vi t;
  int s = 1, e = n - 1;
  t.pb(v[0]);
  while (s <= e) {
    if (s == e)
      r += 'L';
    else {
      if (t.back() > max(v[s], v[e])) {
        if (v[s] < v[e]) {
          r += "LR";
          t.pb(v[e]);
        } else {
          r += "RL";
          t.pb(v[s]);
        }
      } else if (t.back() < min(v[s], v[e])) {
        if (v[s] < v[e]) {
          r += "RL";
          t.pb(v[s]);
        } else {
          r += "LR";
          t.pb(v[e]);
        }
      } else {
        r += "LR";
        t.pb(v[e]);
      }
    }
    s++, e--;
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
