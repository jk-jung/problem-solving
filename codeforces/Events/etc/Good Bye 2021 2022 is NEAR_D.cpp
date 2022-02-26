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
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    cin >> m;
    vector<vi> d(n + 1, vi(3, -1));

    d[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < 3; k++) {
            int x = d[i][k];
            if (x == -1)continue;

            d[i + 1][0] = max(d[i + 1][0], x);
            if (k == 0)d[i + 1][1] = max(d[i + 1][1], x + 1);
            else if (k == 1) {
                if (v[i - 1] + v[i] >= m * 2) {
                    d[i + 1][2] = max(d[i + 1][2], x + 1);
                }
            } else {
                if (v[i - 2] + v[i - 1] + v[i] >= m * 3 && v[i - 1] + v[i] >= m * 2) {
                    d[i + 1][2] = max(d[i + 1][2], x + 1);
                }
            }
        }
    }
    int r = 0;
    for (int i = 0; i <= n; i++)for (int k = 0; k <= 2; k++)r = max(r, d[i][k]);
    cout << r << endl;
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
