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

void compose(map<string, int> &r, map<string, map<string, int>> &M) {

  for (auto &[key, items] : M) {
    bool ok = true;
    for (auto [item, cnt] : items) {
      if (!r.count(item) || r[item] < cnt) {
        ok = false;
        break;
      }
    }
    if (ok) {
      vector<string> removed;
      for (auto [item, cnt] : items) {
        r[item] -= cnt;
        if (r[item] == 0) {
          removed.push_back(item);
        }
      }
      r[key]++;
      for (auto item : removed)
        r.erase(item);
    }
  }
}

void solve() {
  int k, n, m, q;
  cin >> k >> n >> m >> q;
  vector<string> N(n);
  map<string, map<string, int>> M;
  for (auto &x : N)
    cin >> x;
  for (int i = 0; i < m; i++) {
    string key, item, cnt;
    cin >> key;
    key.pop_back();
    while (cin >> item >> cnt) {
      bool end = false;
      if (cnt.back() != ',') {
        end = true;
      } else
        cnt.pop_back();
      M[key][item] += stoi(cnt);
      if (end)
        break;
    }
  }

  vector<map<string, int>> r(k);

  while (q--) {
    int who;
    string item;
    cin >> who >> item;
    r[who - 1][item]++;
    compose(r[who - 1], M);
  }

  for (int i = 0; i < k; i++) {
    cout << r[i].size() << endl;
    for (auto &x : r[i]) {
      cout << x.first << " " << x.second << endl;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
