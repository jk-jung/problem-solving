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

int check(int a, int b) {
  int cnt = 2;
  while (b >= 0) {
    int c = a - b;
    if (c < 0 || c > b)
      break;
    a = b;
    b = c;
    cnt++;
  }
  return cnt;
}
void solve() {
  int n, k;
  cin >> n >> k;
  if (k >= 40) {
    cout << 0 << endl;
    return;
  }
  int r = 0;
  for (int i = 0; i <= n; i++) {
    if (check(n, i) >= k)
      r++;
  }
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
