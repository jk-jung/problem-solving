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
  vector<string> a(n);
  map<string, int> m;
  for (auto &s : a) {
    cin >> s;
    set<string> used;
    for (int i = 0; i < 9; i++) {
      string t;
      for (int j = i; j < 9; j++) {
        t += s[j];
        if (used.count(t))
          continue;
        m[t]++;
        used.insert(t);
      }
    }
  }
  for (auto &s : a) {
    string r = s;
    for (int i = 0; i < 9; i++) {
      string t;
      for (int j = i; j < 9; j++) {
        t += s[j];
        if (t.size() < r.size() && m[t] == 1) {
          r = t;
        }
      }
    }
    cout << r << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
