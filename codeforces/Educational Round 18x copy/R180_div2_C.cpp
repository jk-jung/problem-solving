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

  ll r = 0;
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    for (int j = i + 1, s = n - 1, e = i + 2; j < n - 1; j++) {
      e = max(e, j + 1);
      while (s >= j + 1 && v[s] + v[i] + v[j] > v.back())
        s--;
      while (e < n && v[e] < v[i] + v[j])
        e++;
      int ss = max(s + 1, j + 1);
      if (j < ss && ss < e)
        r += e - ss;
    }
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
