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

double f(double x) { return x * x; }

void solve() {
  int n;
  cin >> n;
  vector<double> a(n), b(n), c(n);
  for (int i = 0; i < n; i++)
    cin >> a[i] >> b[i] >> c[i];

  double x = 0, y = 0, z = 0, p = 1;
  for (int _ = 0; _ < 1000000; _++) {
    double dis = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
      double d = f(a[i] - x) + f(b[i] - y) + f(c[i] - z);
      if (d > dis) {
        dis = d;
        idx = i;
      }
    }
    x += p * (a[idx] - x);
    y += p * (b[idx] - y);
    z += p * (c[idx] - z);

    p *= 0.999;
  }
  cout << setprecision(10) << x << " " << y << " " << z << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
