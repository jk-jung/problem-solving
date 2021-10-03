#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <numeric>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp    make_pair
#define pb    push_back
#define F     first
#define S     second
#define ab(x) (((x)<0)?-(x):(x))

string s[55];
int n, m, k;

int paint(int i, int j, int c = 100) {
    int t;
    for (t = 0; t <= c; t++) {
        for (int op = -1; op <= 1; op += 2) {
            int y = i - t;
            int x = j + op * t;
            if (c != 100)s[y][x] = '!';
            if (x < 0 || x == m || y < 0 || s[y][x] == '.') return t - 1;
        }
    }
    return 0;
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)cin >> s[i];

    bool r = true;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') continue;
            int len = paint(i, j);
            if (len >= k)paint(i, j, len);
            if(s[i][j] == '*') r = false;
        }
    }

    cout << (r ? "YES": "NO") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
