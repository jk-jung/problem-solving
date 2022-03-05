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

int n, m, k;
int hor[505][505];
int ver[505][505];

int d[505][505][11];
int ck[505][505][11], CK;

int go(int y, int x, int c) {
    if (c == 0)return 0;
    if (ck[y][x][c] == CK) return d[y][x][c];
    ck[y][x][c] = CK;
    int &r = d[y][x][c];

    r = 1 << 30;
    if (x < m - 1) r = min(r, go(y, x + 1, c - 1) + hor[y][x]);// ->
    if (x > 0) r = min(r, go(y, x - 1, c - 1) + hor[y][x - 1]); // <-
    if (y < n - 1) r = min(r, go(y + 1, x, c - 1) + ver[y][x]); // v
    if (y > 0) r = min(r, go(y - 1, x, c - 1) + ver[y - 1][x]); // ^

    return r;
}

void solve() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++)cin >> hor[i][j];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) cin >> ver[i][j];
    }

    if (k % 2) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)cout << -1 << " ";
            cout << '\n';
        }
        return;
    }
    k /= 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            CK++;
            int r = go(i, j, k) * 2;
            cout << r << " ";
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
