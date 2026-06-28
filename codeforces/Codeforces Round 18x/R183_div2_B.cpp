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

vi read() {
  string s;
  cin >> s;
  int y = stoi(s.substr(0, 4));
  int m = stoi(s.substr(5, 2));
  int d = stoi(s.substr(8, 2));
  return {y, m, d};
}

int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int is_leap(int y) { return y % 4 == 0 && (y % 100 != 0 || y % 400 == 0); }
void solve() {
  vi a = read(), b = read();
  if (a > b)
    swap(a, b);

  int r = 0;
  while (a != b) {
    a[2]++;
    int m_days = month_days[a[1] - 1];
    if (is_leap(a[0]) && a[1] == 2)
      m_days++;
    if (a[2] > m_days) {
      a[2] = 1;
      a[1]++;
      if (a[1] > 12) {
        a[1] = 1;
        a[0]++;
      }
    }
    r++;
  }
  cout << r << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
