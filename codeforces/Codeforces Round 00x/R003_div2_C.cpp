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

vector<string> v(3);
bool check(char x) {
  if (v[0][0] == x && v[0][1] == x && v[0][2] == x)
    return true;
  if (v[1][0] == x && v[1][1] == x && v[1][2] == x)
    return true;
  if (v[2][0] == x && v[2][1] == x && v[2][2] == x)
    return true;

  if (v[0][0] == x && v[1][0] == x && v[2][0] == x)
    return true;
  if (v[0][1] == x && v[1][1] == x && v[2][1] == x)
    return true;
  if (v[0][2] == x && v[1][2] == x && v[2][2] == x)
    return true;

  if (v[0][0] == x && v[1][1] == x && v[2][2] == x)
    return true;
  if (v[0][2] == x && v[1][1] == x && v[2][0] == x)
    return true;
  return false;
}
void solve() {

  for (int i = 0; i < 3; i++) {
    cin >> v[i];
  }

  int X = 0, O = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (v[i][j] == 'X')
        X++;
      if (v[i][j] == '0')
        O++;
    }
  }

  if (X != O && X != O + 1) {
    cout << "illegal" << endl;
    return;
  }

  if (check('X') && check('0')) {
    cout << "illegal" << endl;
    return;
  }

  if (check('X')) {
    if (X == O + 1) {
      cout << "the first player won" << endl;
      return;
    }
    cout << "illegal" << endl;
    return;
  }

  if (check('0')) {
    if (X == O) {
      cout << "the second player won" << endl;
      return;
    }
    cout << "illegal" << endl;
    return;
  }

  if (X + O == 9) {
    cout << "draw" << endl;
    return;
  }

  cout << (abs(X - O) == 0 ? "first" : "second") << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  solve();
}
