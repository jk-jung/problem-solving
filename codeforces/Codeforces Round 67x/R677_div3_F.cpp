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
int a[77][77];
int d[71][71][71][71];


int go(int y, int x, int c, int re) {
    if (x == m)y++, x = 0, c = 0;
    if (y == n) return re == 0 ? 0 : -2;

    int &r = d[y][x][c][re], t;
    if (r != -1)return r;

    if (c + 1 <= m / 2) {
        t = go(y, x + 1, c + 1, (re + a[y][x]) % k);
        if (t == -2)r = -2;
        else r = t + a[y][x];
    }
    t = go(y, x + 1, c, re);
    if (r == -1)r = t;
    else r = max(r, t);
    return r;
}

void solve() {
    cin >> n >> m >> k;
    memset(d, -1, sizeof(d));

    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];

    cout << go(0, 0, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
