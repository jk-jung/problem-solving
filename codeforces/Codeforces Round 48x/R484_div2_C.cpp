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

int n, r = 0;
vi v[200005];
int c[200005];


int dfs(int x, int y = -1) {
    c[x]++;
    for (int z: v[x]) {
        if (z == y) continue;
        c[x] += dfs(z, x);
        if (c[z] % 2 == 0)r++;
    }
    return c[x];
}

void solve() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if (n % 2) {
        r = -1;
    } else
        dfs(1);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
