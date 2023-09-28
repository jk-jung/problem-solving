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


int a[105][105][12];

void solve() {
    int n, q, c;
    cin >> n >> q >> c;
    for (int i = 0; i < n; i++) {
        int y, x, k;
        cin >> x >> y >> k;
        a[y][x][k]++;
    }
    c ++;

    for (int i = 1; i <= 100; i++) {
        for (int j = 1; j <= 100; j++) {
            for (int k = 0; k <= 10; k++) {
                a[i][j][k] += a[i - 1][j][k] + a[i][j - 1][k] - a[i - 1][j - 1][k];
            }
        }
    }

    while (q--) {
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        x1--, y1--;
        int r = 0;
        for (int k = 0; k <= 10; k++) {
            int x = a[y2][x2][k] - a[y1][x2][k] - a[y2][x1][k] + a[y1][x1][k];
            int v = (k + t) % c;
            r += v * x;
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
