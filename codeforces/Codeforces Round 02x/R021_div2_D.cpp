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

int n, m;
int d[22][22];
int D[1 << 15];
int deg[22];

void solve() {
    cin >> n >> m;
    ll r = 0;
    memset(d, 63, sizeof(d));
    for (int i = 0; i < n; i++)d[i][i] = 0;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        r += z;
        x--, y--;
        d[x][y] = d[y][x] = min(d[x][y], z);
        deg[x]++;
        deg[y]++;
    }
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i < n; i++) {
        if (deg[i] && d[0][i] > 1e9) {
            cout << -1;
            return;
        }
    }

    memset(D, 63, sizeof(D));
    D[0] = 0;
    for (int st = 0; st < 1 << 15; st++) {
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if ((st >> i & 1) && (st >> j & 1)) {
                    D[st] = min(D[st], D[st ^ (1 << i) ^ (1 << j)] + d[i][j]);
                }
    }
    int tar = 0;
    for (int i = 0; i < n; i++)if (deg[i] % 2)tar ^= 1 << i;
    cout << r + D[tar];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
