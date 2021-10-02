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

int a[505][505];
int s[505][505];

int cost(int y1, int x1, int y2, int x2, int k) {
    int v = s[y2][x2] - s[y1 - 1][x2] - s[y2][x1 - 1] + s[y1 - 1][x1 - 1];
    if (k == 0) return v;
    return (x2 - x1 + 1) * (y2 - y1 + 1) - v;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &a[i][j]);
            s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
        }
    }

    int r = n * m;
    for (int y1 = 1; y1 < n; y1++) {
        for (int y2 = y1 + 4; y2 <= n; y2++) {
            vi v = {r, r, r, r, r};
            for (int x = 1; x <= m; x++) {
                for (int i = 4; i >= 1; i--) {
                    if (i == 4) v[i] = min(v[i], v[i - 1]);
                    else v[i] = v[i - 1];
                }
                v[1] = cost(y1 + 1, x, y2 - 1, x, 1);
                r = min(r, v[1] + v[4]);
                int c = cost(y1 + 1, x, y2 - 1, x, 0) + 2 - a[y1][x] - a[y2][x];
                for (int i = 2; i <= 4; i++)v[i] += c;
            }
        }
    }

    cout << r << '\n';
}

int main() {
    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}