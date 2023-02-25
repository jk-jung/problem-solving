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
    vector<pi> v(m), c(n + 1);

    for (auto &[x, y]: v)cin >> x >> y, c[x].F++, c[y].F++;
    for (int i = 1; i <= n; i++)c[i].S = i;
    sort(c.begin(), c.end());
    reverse(c.begin(), c.end());

    for (int i = 0; i < m + 1; i++) {
        if (c[i].F < m / 2)break;

        int tot = 0, ok = 1;
        map<int, int> cnt;
        for (auto [x, y]: v) {
            if (x == c[i].S || y == c[i].S)continue;
            tot++;
            ++cnt[x];
            ++cnt[y];
            if (cnt[x] != tot && cnt[y] != tot) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
