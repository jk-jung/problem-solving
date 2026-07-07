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
  string s, r;
  cin >> s;
  r += s[0];
  bool flag = false;
  int n = s.size();
  for (int i = 1; i < n; i++) {
    if (!flag && i + 1 < n && s[i] == 'a' && s[i + 1] == 't') {
      r += '@';
      i++;
      flag = true;
    } else if (i + 3 < n && s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't') {
      r += '.';
      i += 2;
    } else
      r += s[i];
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
