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
  map<int, int> c;
  for (int &x : v)
    cin >> x, c[x]++;

  if (c.size() == 1) {
    cout << "Exemplary pages." << endl;
    return;
  }

  if (c.size() == 3 || (n == 2 && c.size() == 2)) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (c[v[i]] == 1 && c[v[j]] == 1) {
          int dif = abs(v[i] - v[j]);
          if (dif % 2)
            continue;

          dif /= 2;
          int k = (v[i] + v[j]) / 2;
          if (2 + c[k] != n)
            continue;
          int x = v[i] < v[j] ? i + 1 : j + 1;
          int y = v[i] < v[j] ? j + 1 : i + 1;
          cout << dif << " ml. from cup #" << x << " to cup #" << y << "."
               << endl;
          return;
        }
      }
    }
  }

  cout << "Unrecoverable configuration." << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
