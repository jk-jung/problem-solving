#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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

  vector<double> rr;

  sort(v.begin(), v.end());
  double s = 0, e = 1e9, r = 0;

  for (int _ = 0; _ < 300; _++) {
    double m = (s + e) / 2;
    double anchor = v[0];
    int cnt = 1;
    vector<double> t;
    for (int i = 1; i < n; i++) {
      if (v[i] - anchor > 2 * m) {
        t.pb((v[i - 1] + double(anchor)) / 2);
        anchor = v[i];
        cnt++;
      }
    }
    while (t.size() < 3)
      t.pb(v[n - 1] - m);
    if (cnt <= 3) {
      r = m;
      e = m;
      rr = t;
    } else {
      s = m;
    }
  }
  cout << fixed << setprecision(10) << r << endl;
  for (double x : rr)
    cout << fixed << setprecision(10) << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
