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

vi tt[1500];
void solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;

  int r = -1;
  vi t(1001);
  for (int i = 0; i < n; i++) {
    int x = v[i];
    t[x] = i + 1;
    for (int j : tt[x])
      if (t[j])
        r = max(r, t[j] + i + 1);
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  for (int i = 1; i <= 1000; i++) {
    for (int j = 1; j <= 1000; j++)
      if (gcd(i, j) == 1)
        tt[i].pb(j);
  }

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
