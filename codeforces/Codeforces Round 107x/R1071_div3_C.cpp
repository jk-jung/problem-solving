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
  vi v(n);
  for (int &x : v)
    cin >> x;

  sort(v.begin(), v.end());

  int r = v[0];
  for (int x : v) {
    if (x == v[0])
      continue;
    if (x < v[0] * 2 + 1) {
      cout << r << endl;
      return;
    }
  }
  // v[0] <= min
  // v[0] = v[1] % x = v[2] % x2 = v[3] % x3
  // v[1] = a x + v[0]
  // v[1] - v[0] = a x (x >= k)
  cout << v[1] - v[0] << endl;
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
