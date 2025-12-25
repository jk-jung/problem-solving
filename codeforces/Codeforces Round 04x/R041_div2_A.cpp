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
  int n, v;
  cin >> n >> v;
  vi a(n), b(n);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  double f = 1e10;
  for (int i = 0; i < n; i++) {
    f = min(f, b[i] / double(a[i]));
  }
  double r = 0;
  for (int i = 0; i < n; i++)
    r = min(r + f * a[i], double(v));
  cout << fixed << setprecision(10) << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
