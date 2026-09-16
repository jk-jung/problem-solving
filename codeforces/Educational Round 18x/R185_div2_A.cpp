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
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
  } else if (n == 2) {
    cout << 9 << endl;
  } else {
    int t = n * n;
    int r1 = t * 4 - 4 - n;
    int r2 = t - 1 + t - n + t - n - 1 + t - n - 2 + t - n - n - 1;
    cout << max(r1, r2) << endl;
  }
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
