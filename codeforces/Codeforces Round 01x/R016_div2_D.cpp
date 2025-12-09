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

int f(char x) { return x - '0'; }
int parse(string s) {
  int h = f(s[1]) * 10 + f(s[2]);
  if (h == 12)
    h = 0;
  int m = f(s[4]) * 10 + f(s[5]);
  int tot = h * 60 + m;
  if (s[7] == 'p')
    tot += 12 * 60;

  return tot;
}

void solve() {
  int n, r = 1;
  cin >> n;
  int last = -1;
  int cnt = 0;
  string s;
  getline(cin, s);
  while (n--) {
    string s;
    getline(cin, s);
    int x = parse(s);
    if (x < last)
      r++;
    if (x == last)
      cnt++;
    else
      cnt = 1;

    if (cnt == 11) {
      r++;
      cnt = 1;
    }
    last = x;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
