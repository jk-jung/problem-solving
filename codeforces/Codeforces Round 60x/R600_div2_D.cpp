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

int n, m;
vi v[200005];
int ck[200005];

int dfs(int x) {
    if (ck[x]) return ck[x];
    ck[x] = x;
    for (int y: v[x])ck[x] = max(ck[x], dfs(y));
    return ck[x];
}

void solve() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    int idx = 1, r = 0;
    while (idx < n) {
        int t = dfs(idx);
        for (int i = idx + 1; i <= t; i++) {
            if (!ck[i]) r++;
            t = max(t, dfs(i));
        }
        idx = t + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
