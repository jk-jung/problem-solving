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
  int n;
  cin >> n;
  vi v(n), r;
  string s;
  bool flag = true;
  for (int &x : v) {
    cin >> x;
    if (flag) {
      if (r.empty() || r.back() <= x) {
        s += '1';
        r.pb(x);
      } else if (r.front() >= x) {
        r.pb(x);
        s += '1';
        flag = false;
      } else {
        s += '0';
      }
    } else {
      if (r.back() <= x && x <= r.front()) {
        s += '1';
        r.pb(x);
      } else {
        s += '0';
      }
    }
  }
  cout << s << endl;
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
