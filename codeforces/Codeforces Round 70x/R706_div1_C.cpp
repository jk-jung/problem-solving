#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
#include <array>
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (string &s: v)cin >> s;

    for (int i = 0; i < n; i += 3) {
        for (int j = 0; j < m; j++)v[i][j] = 'X';

        if (i + 3 >= n) {
            if (n % 3 == 0) {
                for (int j = 0; j < m; j++) {
                    if (v[i + 2][j] == 'X') {
                        v[i + 1][j] = 'X';
                    }
                }
            }
        } else {
            int x = 0;
            if (m >= 2 && v[i + 1][1] == 'X' || v[i + 2][1] == 'X') x = 1;
            v[i + 1][x] = v[i + 2][x] = 'X';
        }
    }

    for (string &s: v)cout << s << '\n';
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
