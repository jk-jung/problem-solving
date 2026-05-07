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
  int n, m;
  cin >> n >> m;
  int a = 0, b = 1;
  for (int i = 0; i < n; i++) {
    int c = a + b;
    a = b;
    b = c;
  }

  string r;
  while (m--) {
    vi v(3);
    for (int &x : v)
      cin >> x;
    sort(v.begin(), v.end());
    if (v[0] >= b && a + b <= v[2])
      r += "1";
    else
      r += "0";
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
