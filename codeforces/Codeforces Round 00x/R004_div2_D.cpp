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

struct Data {
  int w, h, i;
  bool operator<(const Data &o) const { return w < o.w; }
};
void solve() {
  int n, w, h;
  cin >> n >> w >> h;
  vector<Data> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].w >> v[i].h;
    v[i].i = i + 1;
  }
  sort(v.begin(), v.end());

  vi d(n, 0);
  vi fr(n, -1);
  for (int i = 0; i < n; i++) {
    if (v[i].w > w && v[i].h > h) {
      int r = 1;
      for (int j = 0; j < i; j++) {
        if (v[j].w < v[i].w && v[j].h < v[i].h) {
          if (d[j] + 1 > r) {
            r = d[j] + 1;
            fr[i] = j;
          }
        }
      }
      d[i] = r;
    }
  }
  int r = 0;
  int idx = -1;
  for (int i = 0; i < n; i++) {
    if (d[i] > r) {
      r = d[i];
      idx = i;
    }
  }
  cout << r << endl;
  vi t;
  while (idx != -1) {
    t.pb(v[idx].i);
    idx = fr[idx];
  }
  reverse(t.begin(), t.end());
  for (int x : t)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
