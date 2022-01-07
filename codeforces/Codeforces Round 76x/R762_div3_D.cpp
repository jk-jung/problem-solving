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
    cin >> m >> n;
    vector<vi> v(m, vi(n));
    vi mm(n);
    for (auto &t: v) for (int &x: t)cin >> x;

    for (int j = 0; j < n; j++) {
        int t = 0;
        for (int i = 0; i < m; i++) t = max(t, v[i][j]);
        mm[j] = t;
    }

    if (m < n) {
        int r = 1 << 30;
        for (int x: mm)r = min(r, x);
        cout << r << endl;
    } else {
        int r = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int t = 0;
                for (int k = 0; k < m; k++)
                    t = max(t, min(v[k][i], v[k][j]));

                int r0 = t;
                for (int k = 0; k < n; k++)
                    if (k != i && k != j) r0 = min(r0, mm[k]);
                r = max(r, r0);
            }
        }
        cout << r << endl;
    }
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
