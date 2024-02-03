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

set<int> v[4005];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].insert(y);
        v[y].insert(x);
    }
    int r = 1 << 30;

    for (int x = 1; x <= n; x++) {
        for (int y: v[x]) {
            for (int z: v[y]) {
                if (!v[x].count(z))continue;
                int t = v[x].size() + v[y].size() + v[z].size();
                r = min(r, t - 6);
            }
        }
    }

    if (r == 1 << 30)r = -1;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
