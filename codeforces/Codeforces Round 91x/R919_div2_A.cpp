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
  int s = 0, e = 1 << 30;
  set<int> t;
  while (n--) {
    int op, x;
    cin >> op >> x;
    if (op == 1)
      s = max(s, x);
    if (op == 2)
      e = min(e, x);
    if (op == 3)
      t.insert(x);
  }
  if (e < s) {
    cout << "0" << endl;
    return;
  }
  int r = e - s + 1;
  for (int x : t) {
    if (s <= x && x <= e)
      r--;
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
