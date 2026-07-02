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

vi read() {
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;
  sort(v.begin(), v.end());
  return v;
}

void solve() {
  vi a = read();
  vi b = read();
  vi c = read();
  double x, y;
  cin >> x >> y;

  double r1 = a.back();
  double p1 = b.back();
  double p2 = c.front();

  // (r1 * r1 - r2 * r2) * p1 : r2 * r2  * p2 == x : y
  // r2^2 * p2 * x = r1^2 * p1 * y - r2^2 * p1 * y
  // r2^2 * (p2 * x + p1 * y) == r1^2 * p1 * y

  double r = sqrt(r1 * r1 * p1 * y / (p2 * x + p1 * y));
  cout << fixed << setprecision(10) << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
