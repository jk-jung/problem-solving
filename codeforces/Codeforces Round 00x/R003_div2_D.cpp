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
  vector<pi> v(s.size());

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '?') {
      cin >> v[i].F >> v[i].S;
    }
  }

  ll r = 0;
  int st = 0;
  priority_queue<pi> pq;
  for (int i = 0; i < s.size(); i++) {
    char x = s[i];
    if (x == '(')
      st++;
    else if (x == ')')
      st--;
    else {
      pq.push(mp(v[i].S - v[i].F, i));
      s[i] = ')';
      r += v[i].S;
      st--;
    }

    if (st < 0 && !pq.empty()) {
      auto [cost, idx] = pq.top();
      pq.pop();

      r -= cost;
      s[idx] = '(';
      st += 2;
    }

    if (st < 0) {
      cout << -1 << endl;
      return;
    }
  }
  if (st != 0) {
    cout << -1 << endl;
    return;
  }
  cout << r << endl << s << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
