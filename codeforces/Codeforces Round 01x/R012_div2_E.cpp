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

int r[1005][1005];
void solve() {
  int n;
  cin >> n;

  deque<int> d;
  for (int i = 0; i < n - 1; i++)
    d.pb(i);
  int t = n - 1;
  for (int i = 1; i < n; i++) {
    r[d[0]][t] = r[t][d[0]] = i;
    for (int s = 1, e = d.size() - 1; s < e; s++, e--) {
      r[d[s]][d[e]] = r[d[e]][d[s]] = i;
    }
    d.pb(d.front());
    d.pop_front();
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << r[i][j] << " ";
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
