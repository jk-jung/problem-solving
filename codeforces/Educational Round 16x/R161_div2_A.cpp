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

bool is_ok(int t, char x) {
  if (islower(t))
    return t == x;
  else
    return tolower(t) != x;
}

void solve() {
  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  bool ok = false;
  for (int i = 0; i < n; i++) {
    bool skip = false;
    for (int t = 0; t < 255; t++) {
      if (isalpha(t) && is_ok(t, a[i]) && is_ok(t, b[i])) {
        skip = true;
        if (!is_ok(t, c[i]))
          ok = true;
      }
    }
    if (!skip) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << (ok ? "YES" : "NO") << endl;
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
