#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
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

string f(string s) {
  int b = 26, i = 1;
  int n = stoi(s) - 1;

  while (n > b) {
    n -= b;
    b *= 26;
    i++;
  }
  string r;
  for (int j = 0; j < i; j++) {
    r += 'A' + n % 26;
    n /= 26;
  }
  reverse(r.begin(), r.end());
  return r;
}
int f2(string s) {
  int rr = 0;
  for (int i = 0, b = 26; i < s.size() - 1; i++, b *= 26) {
    rr += b;
  }
  int r = 0;
  for (char x : s)
    r = r * 26 + (x - 'A' + 1);
  return r;
}

void solve() {
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;

    vector<string> v;
    v.pb("");
    for (char x : s) {
      if (!v.back().empty() && isalpha(v.back().back()) != isalpha(x)) {
        v.pb(string(1, x));
      } else
        v.back() += x;
    }

    if (v.size() == 4) {
      cout << f(v[3]) << v[1] << endl;
    } else {
      cout << "R" << v[1] << "C" << f2(v[0]) << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
