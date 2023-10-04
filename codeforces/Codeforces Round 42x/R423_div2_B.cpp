#include <cstring>
#include <cstdio>
#include <cmath>
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

char a[105][105];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];

    int sx = 10000, sy = 10000;
    int ex = -1, ey = -1, c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'B') {
                c ++;
                sx = min(sx, j);
                ex = max(ex, j);
                sy = min(sy, i);
                ey = max(ey, i);
            }
        }
    }
    int r = -1;
    if (ex == -1)r = 1;
    else {
        int w = ex - sx + 1;
        int h = ey - sy + 1;
        int x = max(w, h);
        if (x > n || x > m)r = -1;
        else r = x * x - c;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
