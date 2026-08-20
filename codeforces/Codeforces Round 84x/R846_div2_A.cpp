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
  vi v(n), a, b;
  for (int &x : v)
    cin >> x;

  for (int i = 0; i < n; i++) {
    if (v[i] % 2)
      a.pb(i + 1);
    else
      b.pb(i + 1);
  }
  if (a.size() > 0 && b.size() > 1) {
    cout << "YES\n";
    cout << a[0] << " " << b[0] << " " << b[1] << endl;
  } else if (a.size() > 2) {
    cout << "YES\n";
    cout << a[0] << " " << a[1] << " " << a[2] << endl;
  } else {
    cout << "NO\n";
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
