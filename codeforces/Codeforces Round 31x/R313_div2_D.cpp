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

string f(string x) {
  int n = x.size();
  if (n % 2)
    return x;
  string a = f(x.substr(0, n / 2));
  string b = f(x.substr(n / 2));
  return (a < b ? a + b : b + a);
}

void solve() {
  string a, b;
  cin >> a >> b;
  cout << (f(a) == f(b) ? "YES" : "NO");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
