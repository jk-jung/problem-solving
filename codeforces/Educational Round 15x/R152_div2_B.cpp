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
  int n, k;
  cin >> n >> k;
  vector<pi> v(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v[i] = {x % k == 0 ? k : x % k, -i};
  }
  sort(v.rbegin(), v.rend());
  for (int i = 0; i < n; i++)
    cout << -v[i].S + 1 << " ";
  cout << endl;
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
