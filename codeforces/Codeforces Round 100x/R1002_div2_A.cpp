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
  set<int> a, b;
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    a.insert(x);
  }
  for (int i = 0, x; i < n; i++) {
    cin >> x;
    b.insert(x);
  }
  if (a.size() + b.size() <= 3) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
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
