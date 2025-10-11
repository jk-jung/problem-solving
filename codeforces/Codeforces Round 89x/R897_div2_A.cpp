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

bool sf(pi &a, pi &b) { return a.S < b.S; }
void solve() {
  int n;
  cin >> n;
  vector<pi> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].F;
    v[i].S = i;
  }
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++)
    v[i].F = n - i;
  sort(v.begin(), v.end(), sf);
  for (auto &x : v)
    cout << x.F << " ";
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
