#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <stdio.h>
#include <string.h>
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
  vi a(n), b(n), cost(n * 3, -1);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  for (int i = 0; i < n; i++) {
    cost[a[i]] = i;
  }
  for (int i = 3; i <= n * 2; i += 2) {
    cost[i] = min(cost[i], cost[i - 2]);
  }

  int r = 1 << 30;
  for (int i = 0; i < n; i++) {
    r = min(r, cost[b[i] - 1] + i);
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
