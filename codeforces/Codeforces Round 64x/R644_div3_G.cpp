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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vi> r(n, vi(m));
    vi c(m);
    bool ok = true;
    for (int i = 0; i < n; i++) {
        int k = a;
        vector<pi> v(m);
        for (int j = 0; j < m; j++)v[j] = {c[j], j};
        sort(v.begin(), v.end());
        for (auto [_, j]: v) {
            if (k > 0 && c[j] < b) {
                c[j]++;
                k--;
                r[i][j] = 1;
            }
        }
        if (k > 0) {
            ok = false;
            break;
        }
    }
    for (int x: c)if (x != b)ok = false;
    if (ok) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)cout << r[i][j];
            cout << endl;
        }
    } else {
        cout << "NO\n";
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
