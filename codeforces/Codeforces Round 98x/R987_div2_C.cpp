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
  if (n % 2 == 0) {
    for (int i = 0; i < n / 2; i++)
      cout << i + 1 << " " << i + 1 << " ";
    cout << endl;
  } else if (n < 27) {
    cout << -1 << endl;
  } else {
    int cnt = 5;
    for (int i = 0; i < n; i++) {
      if (i == 0 || i == 9 || i == 25)
        cout << "1 ";
      else if (i == 10 || i == 26)
        cout << "2 ";
      else
        cout << (++cnt) / 2 << " ";
    }
    cout << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int test_case;
  cin >> test_case;
  while (test_case--)
    solve();
}
