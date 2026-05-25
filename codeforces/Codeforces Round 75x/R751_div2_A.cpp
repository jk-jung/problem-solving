#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <string.h>
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
  string s;
  cin >> s;
  for (char x = 'a'; x <= 'z'; x++) {
    if (s.find(x) != -1) {
      cout << x << " ";
      bool flag = true;
      for (char c : s) {
        if (flag && c == x) {
          flag = false;
        } else
          cout << c;
      }
      cout << endl;
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
