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

  vi r;
  int s = 0, e = n / 2, rst = -1;
  while (s <= e) {
    int m = (s + e) / 2;
    vi t(n);

    int need = m + 1;
    int R = n - 1, L = m - 1;
    for (int i = 0, j = 0; i < need * 2 && i < n; i += 2) {
      t[i] = v[R--];
      if (i > 0)
        t[i - 1] = v[L--];
    }

    for (int i = 0; i < n; i++) {
      if (!t[i])
        t[i] = v[R--];
    }
    int cnt = 0;
    for (int i = 1; i < n - 1; i += 2) {
      if (t[i - 1] > t[i] && t[i] < t[i + 1])
        cnt++;
    }
    if (cnt >= m) {
      s = m + 1;
      rst = m;
      r = t;
    } else
      e = m - 1;
  }
  cout << rst << endl;
  for (int x : r)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
