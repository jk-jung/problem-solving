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
int n;
double t1, t2, k;
vector<pi> v;

double f(double a, double b) {
  return max(a * t1 * (100 - k) / 100 + b * t2,
             b * t1 * (100 - k) / 100 + a * t2);
}

void solve() {
  cin >> n >> t1 >> t2 >> k;
  v.resize(n);
  vector<pair<double, int>> r;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    r.pb(mp(-max(f(a, b), f(b, a)), i));
  }
  sort(r.begin(), r.end());
  for (auto [x, y] : r)
    cout << fixed << setprecision(2) << y + 1 << " " << -x << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  solve();
}
