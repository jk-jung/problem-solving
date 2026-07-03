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
  map<string, int> m;
  while (n--) {
    string s;
    int k;
    cin >> s >> k;
    m[s] = max(m[s], k);
  }
  int tot = m.size();

  cout << tot << endl;
  for (auto [s, k] : m) {
    int cnt = 0;
    for (auto [s2, k2] : m) {
      if (k2 <= k)
        cnt++;
    }
    if (cnt * 100 >= 99 * tot) {
      cout << s << " " << "pro" << endl;
    } else if (cnt * 100 >= 90 * tot) {
      cout << s << " " << "hardcore" << endl;
    } else if (cnt * 100 >= 80 * tot) {
      cout << s << " " << "average" << endl;
    } else if (cnt * 100 >= 50 * tot) {
      cout << s << " " << "random" << endl;
    } else {
      cout << s << " " << "noob" << endl;
    }
  }
  string s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
