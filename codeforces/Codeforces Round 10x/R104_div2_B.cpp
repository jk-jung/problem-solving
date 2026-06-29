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

int f(int x) {
  int r = 0, b = 1;
  while (x) {
    int k = x % 10;
    if (k == 4 || k == 7) {
      r += k * b;
      b *= 10;
    }
    x /= 10;
  }
  return r;
}

void solve() {
  int a, b;
  cin >> a >> b;
  a++;
  for (;; a++) {
    if (f(a) == b) {
      cout << a << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
