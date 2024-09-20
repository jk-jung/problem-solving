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

int n, m;
vi v[1000];
int ck[1000];
bool cc = 0;

int dfs(int x, int y) {
    if (ck[x]) {
        cc = 1;
        return 0;
    }
    ck[x] = 1;
    int r = 1;
    for (int z: v[x])
        if (z != y)r += dfs(z, x);
    return r;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    int r = n;
    for (int i = 1; i <= n; i++) {

        if (!ck[i]) {
            cc = 0;
            int cnt = dfs(i, 0);
            if (cc && cnt % 2)r--;
        }
    }
    if (r % 2) r--;
    cout << n - r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
