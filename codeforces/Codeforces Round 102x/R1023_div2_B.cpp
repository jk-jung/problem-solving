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

  ll s = 0;
  vi v(n);
  for (int &x : v)
    cin >> x, s += x;
  sort(v.begin(), v.end());

  if (v.back() - v[0] - 1 > k || v[n - 2] - v[0] > k) {
    cout << "Jerry" << endl;
  } else {
    cout << (s % 2 == 1 ? "Tom" : "Jerry") << endl;
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
