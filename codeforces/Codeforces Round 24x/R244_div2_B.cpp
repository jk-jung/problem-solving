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
  int n, t, c;
  cin >> n >> t >> c;
  vi v(n);
  for (int &x : v)
    cin >> x;
  int r = 0;
  queue<int> q;
  for (int x : v) {
    if (x > t) {
      while (!q.empty())
        q.pop();
    } else {
      q.push(x);
      if (q.size() > c)
        q.pop();
      if (q.size() == c)
        r++;
    }
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
