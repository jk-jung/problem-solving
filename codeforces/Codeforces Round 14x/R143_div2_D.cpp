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
  int x, y, z, bx, by, bz;
  cin >> x >> y >> z >> bx >> by >> bz;
  int xz0, xz1, xy0, xy1, yz0, yz1;
  cin >> xz0 >> xz1 >> xy0 >> xy1 >> yz0 >> yz1;
  int r = 0;
  if (y < 0)
    r += xz0;
  if (y > by)
    r += xz1;

  if (z < 0)
    r += xy0;
  if (z > bz)
    r += xy1;

  if (x < 0)
    r += yz0;
  if (x > bx)
    r += yz1;
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
