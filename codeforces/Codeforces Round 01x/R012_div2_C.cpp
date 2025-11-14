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

int calc(map<string, int> &ck, vi &v) {
  int r = 0;
  vi t;
  for (auto &[x, y] : ck)
    t.pb(y);
  sort(t.rbegin(), t.rend());
  for (int i = 0; i < t.size(); i++)
    r += t[i] * v[i];
  return r;
}

void solve() {
  int n, m;
  cin >> n >> m;
  vi v(n);
  for (int &x : v)
    cin >> x;
  map<string, int> ck;
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    ck[s]++;
  }
  sort(v.begin(), v.end());
  cout << calc(ck, v) << " ";
  sort(v.rbegin(), v.rend());
  cout << calc(ck, v) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
