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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vi> v(n, vi(m)), y(n, vi(m)), x(m, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k;
            cin >> k;
            v[i][j] = k;
            y[i][j] = k;
            x[j][i] = k;
        }
    }

    for (auto &z: y) {
        sort(z.begin(), z.end());
        z.erase(unique(z.begin(), z.end()), z.end());
    }
    for (auto &z: x) {
        sort(z.begin(), z.end());
        z.erase(unique(z.begin(), z.end()), z.end());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int z = v[i][j];
            int a = lower_bound(y[i].begin(), y[i].end(), z) - y[i].begin();
            int b = lower_bound(x[j].begin(), x[j].end(), z) - x[j].begin();
            cout << max(a, b) + max(y[i].size() - a, x[j].size() - b) << ' ';
        }
        cout << endl;
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
