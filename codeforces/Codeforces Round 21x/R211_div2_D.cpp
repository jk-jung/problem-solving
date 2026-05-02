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
  int n, m, a;
  cin >> n >> m >> a;
  vi b(n), p(m);
  for (int &x : b)
    cin >> x;
  for (int &x : p)
    cin >> x;
  sort(b.begin(), b.end());
  sort(p.begin(), p.end());

  int r = 0, t = 0, i = 0;
  int s = 0, e = min(n, m);
  while (s <= e) {
    int mid = (s + e) / 2;
    ll need = 0, spent = 0;
    for (int i = n - mid, j = 0; i < n; i++, j++) {
      need += max(0, p[j] - b[i]);
      spent += min(p[j], b[i]);
    }
    if (need <= a) {
      r = mid;
      s = mid + 1;

      t = max(0ll, spent - (ll)a + need);
    } else {
      e = mid - 1;
    }
  }
  cout << r << " " << t << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
