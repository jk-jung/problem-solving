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
  int n, m;
  cin >> n >> m;
  vi a(n), b(m);
  for (int &x : a)
    cin >> x;
  for (int &x : b)
    cin >> x;

  sort(b.begin(), b.end());

  for (int i = 0; i < n; i++) {
    while (!b.empty() && b.back() >= a[i]) {
      cout << b.back() << " ";
      b.pop_back();
    }
    cout << a[i] << " ";
  }
  while (!b.empty()) {
    cout << b.back() << " ";
    b.pop_back();
  }
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
