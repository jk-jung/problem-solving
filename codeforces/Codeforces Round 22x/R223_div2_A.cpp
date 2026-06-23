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
  deque<int> v(n);
  for (int &x : v)
    cin >> x;

  int a = 0, b = 0;
  while (!v.empty()) {
    if (v.front() > v.back()) {
      a += v.front();
      v.pop_front();
    } else {
      a += v.back();
      v.pop_back();
    }
    if (v.empty())
      break;
    if (v.front() > v.back()) {
      b += v.front();
      v.pop_front();
    } else {
      b += v.back();
      v.pop_back();
    }
  }
  cout << a << " " << b << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
