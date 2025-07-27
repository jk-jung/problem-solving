#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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
  int n, k;
  cin >> n >> k;
  vi v(n);
  for (int &x : v)
    cin >> x;
  int r = 0;
  int cur = 0;
  for (int x : v) {
    if (cur == k) {
      r++;
      cur = 0;
    } else {
      cur = x == 0 ? cur + 1 : 0;
    }
  }
  if (cur == k)
    r++;
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
