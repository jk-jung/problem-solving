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
  vi a(n);
  for (int &x : a)
    cin >> x;
  vi b = a;
  sort(b.begin(), b.end());
  for (int i = 0; i < n; i++) {
    vi c;
    for (int j = 0; j < n; j++)
      c.pb(a[(i + j) % n]);
    if (b == c) {
      cout << "Yes\n";
      return;
    }
  }
  cout << "No\n";
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
