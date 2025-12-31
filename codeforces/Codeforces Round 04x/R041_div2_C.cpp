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

void solve() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;

  // Step 1: 1 1 c d
  while (a != 1 || b != 1) {
    if (a % 2 == b % 2) {
      if (a % 2 == 1) {
        cout << "+1\n";
        a++;
        b++;
      }
      a /= 2;
      b /= 2;
      cout << "/1\n";
    } else {
      if (a % 2 == 1) {
        cout << "+4\n";
        a++;
        d++;
      } else {
        cout << "+2\n";
        b++;
        c++;
      }
      a /= 2;
      b /= 2;
      cout << "/1\n";
    }
  }
  // Step 2: 1 1 1/2 d
  while (c > 2) {
    cout << "+2\n";
    b++;
    c++;
    if (c % 2) {
      cout << "+3\n";
      c++;
      d++;
    }
    cout << "/2\n";
    b /= 2;
    c /= 2;
  }

  // Step 3: 1 1 1 1
  while (c > 1 || d > 1) {
    if (c == 2) {
      if (d % 2) {
        if (d == 1) {
          cout << "+2\n+3\n/2\n/3\n";
          b++;
          c += 2;
          d++;
          b /= 2;
          c /= 4;
          d /= 2;
          break;
        }
        cout << "+4\n/4\n";
        d = (d + 1) / 2;
        a = (a + 1) / 2;
      } else {
        cout << "/3\n";
        c /= 2;
        d /= 2;
      }
    } else {
      cout << "+3\n";
      c++;
      d++;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
