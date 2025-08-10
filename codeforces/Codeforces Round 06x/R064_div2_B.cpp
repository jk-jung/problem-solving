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
  ll n;
  cin >> n;
  string s;
  cin.ignore();
  getline(cin, s);
  vi v;
  int cnt = 0;
  for (int i = 0; i < s.size(); i++) {
    if (cnt == 0 && s[i] == ' ')
      continue;
    cnt++;
    if (s[i] == '.' || s[i] == '?' || s[i] == '!') {
      v.pb(cnt);
      cnt = 0;
    }
  }
  if (cnt) {
    cout << "Impossible" << endl;
    return;
  }
  cnt = 0;
  int r = 1;
  for (int x : v) {
    if (x > n) {
      cout << "Impossible" << endl;
      return;
    }
    int nxt = cnt + x;
    if (nxt != x)
      nxt++;
    if (nxt > n) {
      r++;
      cnt = x;
    } else {
      cnt = nxt;
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
