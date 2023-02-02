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
    vector<vi> v(n, vi(m)), t(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> v[i][j];

    vector<pi> r;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (v[i][j] + v[i + 1][j] + v[i][j + 1] + v[i + 1][j + 1] == 4) {
                r.pb({i + 1, j + 1});
                t[i][j] = t[i + 1][j] = t[i][j + 1] = t[i + 1][j + 1] = 1;
            }
        }
    }
    if (t == v) {
        cout << r.size() << endl;
        for (auto [x, y]: r)cout << x << " " << y << endl;
    } else {
        cout << -1 << endl;
    }


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
