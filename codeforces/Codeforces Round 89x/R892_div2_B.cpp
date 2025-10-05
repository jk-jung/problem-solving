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
  vector<vi> v(n);
  vi a(n), b(n);
  for (int i = 0, m; i < n; i++) {
    cin >> m;
    v[i].resize(m);
    for (int &x : v[i])
      cin >> x;
    sort(v[i].begin(), v[i].end());
    a[i] = v[i][0];
    b[i] = v[i][1];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  ll r = 0;
  ll rst = 0;
  for (int x : b)
    r += x;

  for (int i = 0; i < n; i++) {
    rst = max(rst, r - b[i] + min(b[i], a[0]));
  }

  cout << rst << endl;
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
