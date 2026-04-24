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

map<int, vi> cnt;
int d[100005];
void solve() {
  int n;
  cin >> n;
  vi v(n);
  for (int &x : v)
    cin >> x;
  for (int i = 0; i < n; i++)
    cnt[v[i]].pb(i);

  queue<int> q;
  q.push(0);
  q.push(n - 1);
  d[0] = d[n - 1] = 1;
  for (int x : cnt[1])
    if (!d[x])
      q.push(x), d[x] = 1;

  int N = 0, r = 0;
  while (N < n) {
    queue<int> q2;
    r++;
    while (!q.empty()) {
      int x = q.front();
      q.pop();
      N++;
      if (x > 0 && !d[x - 1])
        q2.push(x - 1), d[x - 1] = 1;
      if (x < n - 1 && !d[x + 1])
        q2.push(x + 1), d[x + 1] = 1;
      for (int y : cnt[r + 1])
        if (!d[y])
          q2.push(y), d[y] = 1;
    }
    q = q2;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
