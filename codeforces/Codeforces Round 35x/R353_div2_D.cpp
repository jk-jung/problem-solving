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
  vi v(n), r(n);
  for (int &x : v)
    cin >> x;

  map<int, int> pos;
  pos[v[0]] = 0;
  for (int i = 1; i < n; i++) {
    auto it = pos.lower_bound(v[i]);
    if (it == pos.end()) {
      it--;
    } else if (it == pos.begin()) {
    } else {
      auto it2 = it;
      it2--;
      if (it2->second > it->second) {
        it = it2;
      }
    }

    r[i] = it->first;
    pos[v[i]] = it->second + 1;
  }
  for (int i = 1; i < n; i++)
    cout << r[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
