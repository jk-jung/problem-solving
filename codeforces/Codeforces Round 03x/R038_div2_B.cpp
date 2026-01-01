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

pi f(string s) { return {s[0] - 'a', s[1] - '1'}; }

bool ok(pi a, pi b, pi c) {
  if (c.F == b.F || c.S == b.S || a == c)
    return false;

  for (int x = -2; x <= 2; x++) {
    for (int y = -2; y <= 2; y++) {
      if (ab(x) + ab(y) != 3)
        continue;

      pi t = mp(c.F + x, c.S + y);
      if (t == a || t == b)
        return false;
    }
  }
  return true;
}

void solve() {
  string a, b;
  cin >> a >> b;

  int r = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (ok(f(b), f(a), mp(i, j)))
        r++;
    }
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
