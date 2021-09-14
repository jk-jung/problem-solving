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

char r[55][55];

void solve() {
    int n;
    string s;
    vi win;
    cin >> n >> s;
    for (int i = 0; i < n; i++)if (s[i] == '2')win.pb(i);

    if (1 <= win.size() && win.size() <= 2) {
        cout << "NO" << '\n';
        return;
    }

    memset(r, 0, sizeof(r));
    for (int i = 0; i < win.size(); i++) {
        int x = win[i];
        int y = win[(i + 1) % win.size()];
        r[x][y] = '+';
        r[y][x] = '-';
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)r[i][j] = 'X';
            else if (!r[i][j])r[i][j] = '=';
        }
    }
    cout << "YES" << '\n';
    for (int i = 0; i < n; i++)cout << r[i] << '\n';
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
