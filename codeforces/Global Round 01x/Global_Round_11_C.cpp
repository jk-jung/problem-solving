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

int d[100005];

void solve() {
    int n, m, L = 0, r = 0;
    cin >> m >> n;
    vector<tuple<int, int, int>> v(n);

    for (auto &[x, y, z]: v)cin >> z >> x >> y, x--, y--;
    for (int i = 1; i <= n; i++) {
        auto [x, y, z] = v[i - 1];
        if (i >= 2 * m) L = max(L, d[i - 2 * m]);
        if (x + y <= z) d[i] = 1;
        if (L) d[i] = L + 1;
        for (int j = max(1, i - 2 * m); j < i; j++) {
            auto [a, b, c] = v[j - 1];
            if (ab(x - a) + ab(y - b) <= ab(z - c) && d[j]) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        r = max(r, d[i]);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
