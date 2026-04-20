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
  double a, b, m, vx, vy, vz;
  cin >> a >> b >> m >> vx >> vy >> vz;

  double t = -m / vy;
  double dx = vx * t + a / 2;
  double dz = vz * t;

  int xx = 0, zz = 0;
  while (dx < 0 || dx > a) {
    if (dx < 0)
      dx += a, xx++;
    else if (dx > a)
      dx -= a, xx++;
  }

  while (dz < 0 || dz > b) {
    if (dz < 0)
      dz += b, zz++;
    else if (dz > b)
      dz -= b, zz++;
  }
  if (xx % 2)
    dx = a - dx;
  if (zz % 2)
    dz = b - dz;

  cout << fixed << setprecision(10) << dx << " " << dz << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
