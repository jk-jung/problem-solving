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
  int r = 0, c = max(ab(v[0] - v[1]), ab(v[n - 1] - v[n - 2]));
  for (int i = 1; i < n; i++)
    r += ab(v[i - 1] - v[i]);
  for (int i = 1; i < n - 1; i++) {
    int v0 = ab(v[i - 1] - v[i]) + ab(v[i] - v[i + 1]);
    int v1 = ab(v[i - 1] - v[i + 1]);
    c = max(c, v0 - v1);
  }
  cout << r - c << endl;
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
