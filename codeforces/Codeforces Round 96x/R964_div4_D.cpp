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
  string a, b;
  cin >> a >> b;
  int j = 0;
  for (int i = 0; i < a.size(); i++) {

    if (a[i] == '?') {
      if (j == b.size())
        a[i] = 'a';
      else
        a[i] = b[j++];
    } else if (j < b.size() && a[i] == b[j])
      j++;
  }
  if (j == b.size())
    cout << "YES\n" << a << endl;
  else
    cout << "NO\n" << endl;
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
