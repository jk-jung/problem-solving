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
  int x, y;
  cin >> x >> y;

  if (x != 1 && y != 1) {
    cout << "NO\n";
  } else {
    while (y > 1)
      x = x * 10 + 1, y--;
    for (int i = 2; i * i <= x; i++) {
      if (x % i == 0) {
        cout << "NO\n";
        return;
      }
    }

    cout << (x == 1 ? "NO" : "YES") << endl;
  }
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
