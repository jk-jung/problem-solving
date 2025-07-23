#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <complex>
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

struct Data {
  int l, r, real;
};

bool cmp(Data a, Data b) {
  if (a.real == b.real) {
    return a.l < b.l;
  }
  return a.real < b.real;
}

void solve() {
  int n, k;
  cin >> n >> k;
  vector<Data> v(n);
  for (int i = 0; i < n; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v[i].l = a;
    v[i].r = b;
    v[i].real = c;
  }
  sort(v.begin(), v.end(), cmp);

  for (auto x : v) {
    if (k < x.real && x.l <= k && k <= x.r)
      k = x.real;
  }
  cout << k << endl;
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
