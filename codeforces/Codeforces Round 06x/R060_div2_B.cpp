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
  vi r;
  r.pb(1000);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;

    bool ok = false;
    for (int k = r.back(); k <= 2011; k++) {
      string a = to_string(k);
      string b = to_string(x);
      int cnt = 0;
      for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
          cnt++;
      }
      if (cnt <= 1) {
        ok = true;
        r.pb(k);
        break;
      }
    }
    if (!ok) {
      cout << "No solution" << endl;
      return;
    }
  }
  for (int i = 1; i < r.size(); i++)
    cout << r[i] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
