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
  string s;
  cin >> s;
  try {
    ll x = stoll(s);
    if (-128 <= x && x <= 127)
      cout << "byte" << endl;
    else if (-32768 <= x && x <= 32767)
      cout << "short" << endl;
    else if (-2147483648 <= x && x <= 2147483647)
      cout << "int" << endl;
    else
      cout << "long" << endl;
  } catch (...) {
    cout << "BigInteger" << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
