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

    vector<pi> v(m);
    for (auto &[x, y]: v)cin >> x >> y;
    int r = max(v[0].F + v[0].S - 1, v[m - 1].S + n - v[m - 1].F);

    for (int i = 1; i < m; i++) {
        int d = v[i].F - v[i - 1].F;
        int h = ab(v[i].S - v[i-1].S);
        int t = max(v[i].S, v[i - 1].S);
        if (h > d) {
            cout << "IMPOSSIBLE";
            return;
        }
        while (t - v[i].S + t - v[i - 1].S <= d)t++;
        r = max(r, t - 1);
    }

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
