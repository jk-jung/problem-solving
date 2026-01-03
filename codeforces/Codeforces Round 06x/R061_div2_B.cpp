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

  int r = 0;
  for (int i = 0; i < n; i++) {
    int t = 1;
    for (int j = i + 1; j < n; j++) {
      if (v[j - 1] >= v[j])
        t++;
      else
        break;
    }
    for (int j = i - 1; j >= 0; j--) {
      if (v[j + 1] >= v[j])
        t++;
      else
        break;
    }
    r = max(r, t);
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
