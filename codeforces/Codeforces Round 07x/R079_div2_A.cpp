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


int a[105];
int v[105][105];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        x--, y--;
        v[x][y] = v[y][x] = 1;
    }
    int r = 1 << 30;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!v[i][j])continue;
            for (int k = j + 1; k < n; k++) {
                if (!v[i][k] || !v[j][k])continue;
                r = min(r, a[i] + a[j] + a[k]);
            }
        }
    }
    cout << (r == 1 << 30 ? -1 : r) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
