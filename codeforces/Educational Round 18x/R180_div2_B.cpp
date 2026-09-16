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
int n;
int check(vi &v) {
  int r = 1e9;
  for (int i = 0; i < n; i++) {
    int s = v[i], e = v[i];
    for (int j = i + 1; j < n; j++) {
      if (s - 1 <= v[j] && v[j] <= e + 1) {
        r = min(r, j - i - 1);
        break;
      }
      s = min(s, v[j]);
      e = max(e, v[j]);
    }
  }
  return r;
}

void solve() {
  cin >> n;
  vi v(n), t;
  for (int &x : v)
    cin >> x;
  t = v;
  reverse(t.begin(), t.end());
  int r = min(check(v), check(t));
  if (r == 1e9)
    r = -1;
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
