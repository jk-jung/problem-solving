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

  int s = 0, e = n - 1;
  set<int> A, B;

  while (true) {
    if (s == e) {
      if (A.count(s) || B.count(e))
        break;
      A.insert(s);
      break;
    }
    if (s > e)
      break;
    A.insert(s);
    B.insert(e);
    int cnt = min(v[s], v[e]);
    v[s] -= cnt;
    v[e] -= cnt;
    if (v[s] == 0)
      s++;
    if (v[e] == 0)
      e--;
  }

  cout << A.size() << " " << B.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
