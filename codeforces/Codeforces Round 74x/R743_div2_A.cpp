#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
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
  int n;
  cin >> n >> s;
  int r = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != '0') {
      if (i != n - 1)
        r++;
      r += s[i] - '0';
    }
  }
  cout << r << endl;
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
