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
  getline(cin, s);

  set<char> x;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '{' || s[i] == ' ') {
      if (s[i + 1] != '}')
        x.insert(s[i + 1]);
    }
  }
  cout << x.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
