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

struct Date {
  int y, m, d;
  Date(int _y, int _m, int _d) : y(_y), m(_m), d(_d) {}

  Date(string s) {
    y = (s[6] - '0') * 10 + (s[7] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');
    d = (s[0] - '0') * 10 + (s[1] - '0');
  }

  bool is_valid() {
    if (y < 0 || y > 99)
      return false;
    if (m < 1 || m > 12)
      return false;
    if (d < 1 || d > 31)
      return false;
    if (m == 2) {
      if (y % 4 == 0) {
        if (d > 29)
          return false;
      } else {
        if (d > 28)
          return false;
      }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
      if (d > 30)
        return false;
    }
    return true;
  }
  bool operator<=(const Date &D) const {
    if (y != D.y)
      return y <= D.y;
    if (m != D.m)
      return m <= D.m;
    return d <= D.d;
  }
};

void solve() {
  string a, b;
  // a = "dd.mm.yy"
  cin >> a >> b;
  Date A(a);
  Date B(b);

  vector<Date> v;
  v.pb(Date(B.y, B.m, B.d));
  v.pb(Date(B.y, B.d, B.m));
  v.pb(Date(B.d, B.y, B.m));
  v.pb(Date(B.d, B.m, B.y));
  v.pb(Date(B.m, B.y, B.d));
  v.pb(Date(B.m, B.d, B.y));

  for (auto &d : v) {
    if (!d.is_valid())
      continue;
    d.y += 18;
    if (d <= A) {
      cout << "YES";
      return;
    }
  }
  cout << "NO";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
