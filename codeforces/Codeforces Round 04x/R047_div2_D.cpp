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

int n, k, p;
vector<pi> v;

double prob(int i, double m) {
  double d = sqrt(pow(v[0].F - v[i].F, 2) + pow(v[0].S - v[i].S, 2));
  if (d <= m)
    return 1;
  return exp(1 - pow(d, 2) / pow(m, 2));
}

double d[105][105];
double P[105];
int ck[105][105];
int CK;

double go(int i, int hit) {
  if (i == n + 1)
    return hit >= k ? 1 : 0;

  double &r = d[i][hit];
  if (ck[i][hit] == CK)
    return r;
  ck[i][hit] = CK;

  return r = P[i] * go(i + 1, hit + 1) + (1 - P[i]) * go(i + 1, hit);
}

bool check(double m) {
  CK++;
  for (int i = 1; i <= n; i++) {
    P[i] = prob(i, m);
  }

  return go(1, 0) >= (1000 - p) / 1000.0;
}

void solve() {
  cin >> n >> k >> p;
  v.resize(n + 1);

  for (auto &[x, y] : v)
    cin >> x >> y;

  double s = 0, e = 1e5, r = 0;
  for (int _ = 0; _ < 1000; _++) {
    double m = (s + e) / 2;
    if (check(m)) {
      r = m;
      e = m;
    } else {
      s = m;
    }
  }
  cout << fixed << setprecision(10) << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
