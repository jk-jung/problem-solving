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
#include <string>
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
  vi v(n);
  for (int &x : v)
    cin >> x;

  map<int, int> ck;
  set<int> r;

  for (int i = 0; i < n; i++) {
    if (i >= m) {
      int val = --ck[v[i - m]];
      if (val == 0)
        r.erase(v[i - m]);
      else if (val == 1)
        r.insert(v[i - m]);
    }

    int val = ++ck[v[i]];
    if (val == 1)
      r.insert(v[i]);
    else
      r.erase(v[i]);

    if (i >= m - 1) {
      cout << (r.empty() ? "Nothing" : to_string(*r.rbegin())) << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
