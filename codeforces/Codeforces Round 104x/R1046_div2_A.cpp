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

bool ok(int a, int b) {
  if (a < b)
    swap(a, b);

  while (true) {
    a -= 2;
    if (a <= 0)
      return true;
    b -= 1;
    if (b < 0)
      return false;
  }
}
void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << (ok(a, b) && ok(c - a, d - b) ? "YES\n" : "NO\n");
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
