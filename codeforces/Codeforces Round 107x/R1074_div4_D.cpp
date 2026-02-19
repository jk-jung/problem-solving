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
  int n, m, h;
  cin >> n >> m >> h;

  int CK = 0;
  vi ck(n);

  vector<ll> a(n), aa(n), b(m), c(m);
  for (ll &x : a)
    cin >> x;
  aa = a;
  for (int i = 0; i < m; i++)
    cin >> b[i] >> c[i];

  for (int i = 0; i < m; i++) {
    ll idx = b[i] - 1;
    ll val = c[i];
    if (ck[idx] != CK) {
      a[idx] = aa[idx];
    }

    a[idx] += val;
    if (a[idx] > h) {
      CK++;
      a[idx] = aa[idx];
    }

    ck[idx] = CK;
  }

  for (int i = 0; i < n; i++) {
    if (ck[i] != CK)
      cout << aa[i] << " ";
    else
      cout << a[i] << " ";
  }
  cout << endl;
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
