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
  string s, t;
  // while (cin >> s) {
  //   t += s;
  //   cout << t << endl;
  // }
  cin >> t;
  vi r, a;
  for (int i = 0; i < t.size(); i++) {
    if (t[i] != '<')
      continue;
    if (t[i + 3] == 'b') {
      r.pb(0);
    } else if (t[i + 3] == 'a') {
      a.pb(r.back());
      r.pop_back();
    } else if (t[i + 2] == 'd')
      r.back()++;
  }
  cout << t << endl;

  sort(a.begin(), a.end());
  for (int x : a)
    cout << x << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
