/*
 * Reference
 * - https://en.wikipedia.org/wiki/Pick%27s_theorem
 */

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

ll c[2][2];

void solve() {
    int n;
    cin >> n;
    vector<pi> v(n);
    for (auto &[x, y]: v) {
        cin >> x >> y;
        c[x % 4 / 2][y % 4 / 2]++;
    }

    ll r = 0;
    for (auto &i: c)
        for (long long x: i) {
            r += x * (x - 1) * (x - 2) / 6;
        }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int i1 = 0; i1 < 2; i1++) {
                for (int j1 = 0; j1 < 2; j1++) {
                    if (i1 == i && j1 == j)continue;
                    r += c[i][j] * (c[i][j] - 1) * c[i1][j1] / 2;
                }
            }
        }
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
