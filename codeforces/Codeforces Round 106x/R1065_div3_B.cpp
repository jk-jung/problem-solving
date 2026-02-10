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
  vi v(n);
  for (int &x : v)
    cin >> x;

  if (v[0] == -1 && v.back() == -1) {
    cout << 0 << endl;
    for (int x : v) {
      if (x == -1)
        cout << 0 << " ";
      else
        cout << x << " ";
    }
    cout << endl;
  } else if (v[0] == -1) {
    cout << 0 << endl;
    cout << v.back() << " ";
    for (int i = 1; i < n; i++) {
      int x = v[i];
      if (x == -1)
        cout << 0 << " ";
      else
        cout << x << " ";
    }
  } else if (v.back() == -1) {
    cout << 0 << endl;
    for (int i = 0; i < n - 1; i++) {
      int x = v[i];
      if (x == -1)
        cout << 0 << " ";
      else
        cout << x << " ";
    }
    cout << v[0] << endl;
  } else {
    cout << ab(v.back() - v[0]) << endl;
    for (int x : v) {
      if (x == -1)
        cout << 0 << " ";
      else
        cout << x << " ";
    }
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
