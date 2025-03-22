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


map<char, vector<pi>> ck;
int cost[255];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> v(n);
    for (auto &x: v) cin >> x;
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ck[v[i][j]].pb({i, j});
            if (v[i][j] != 'S')cost[v[i][j]] = 0;
        }
    }

    for (int i = 'A'; i <= 'Z'; i++) {
        vector<pi> &a = ck[i - 'A' + 'a'];
        vector<pi> &b = ck['S'];
        for (auto [x, y]: a) {
            for (auto [xx, yy]: b) {
                int t = (x - xx) * (x - xx) + (y - yy) * (y - yy);
                if (t <= k * k)cost[i] = 0;
                else if (cost[i] == -1)cost[i] = 1;
            }
        }
    }
    int q, r = 0;
    string s;
    cin >> q >> s;
    for (char x: s) {
        if (cost[x] == -1) {
            cout << -1;
            return;
        }
        r += cost[x];
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
