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

string s[55];
int a[55], b[55];
int n;

pi calc(string x, string y) {
  map<char, int> xx, yy;
  for (char c : x)
    xx[c]++;
  for (char c : y)
    yy[c]++;
  int same = 0;
  for (int i = 0; i < 4; i++)
    same += x[i] == y[i];

  int cnt = 0;
  for (int i = 0; i < 10; i++)
    cnt += min(xx[i + '0'], yy[i + '0']);
  return {same, cnt - same};
}
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> s[i] >> a[i] >> b[i];

  vector<string> candidates;
  for (int k = 0; k < 10000; k++) {
    string t = to_string(k);
    while (t.size() < 4)
      t = "0" + t;
    set<char> st;
    for (char c : t)
      st.insert(c);
    if (st.size() != 4)
      continue;

    int ok = 0;
    for (int i = 0; i < n; i++) {
      if (mp(a[i], b[i]) == calc(s[i], t))
        ok++;
    }
    if (ok == n)
      candidates.pb(t);
  }
  if (candidates.empty()) {
    cout << "Incorrect data" << endl;
    return;
  }
  if (candidates.size() > 1) {
    cout << "Need more data" << endl;
    return;
  }
  cout << candidates[0] << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
