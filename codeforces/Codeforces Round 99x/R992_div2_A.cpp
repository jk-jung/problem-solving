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
  vi a(n);
  for (int &x : a)
    cin >> x;

  for (int i = 0; i < n; i++) {

    for (int j = 0; j < n; j++)
      if (i != j && ab(a[i] - a[j]) % k == 0)
        goto E;
    cout << "YES\n" << i + 1 << "\n";
    return;
  E:;
  }
  cout << "NO\n";
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
