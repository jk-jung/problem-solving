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

ll d[1005][1005];

void solve() {
    memset(d, 0, sizeof(d));
    int n, q;
    cin >> n >> q;
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        d[x][y]++;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= 1000; j++) {
            d[i][j] = d[i][j - 1] + d[i][j] * i * j;
        }
    }

    while (q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll r = 0;
        for (int i = x1 + 1; i < x2; i++) {
            r += d[i][y2 - 1] - d[i][y1];
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
