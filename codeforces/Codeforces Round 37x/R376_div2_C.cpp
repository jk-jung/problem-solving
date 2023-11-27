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

int n, m, k;
int c[200005];
vi v[200005];
int a[200005];
map<int, int> ck;


void dfs(int x) {
    if (a[x]) return;
    a[x] = 1;
    ck[c[x]]++;
    for (int y: v[x])dfs(y);
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)cin >> c[i];
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    int r = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            ck.clear();
            dfs(i);
            int tot = 0, mm = 0;
            for (auto [x, y]: ck) {
                tot += y;
                mm = max(mm, y);
            }
            r += tot - mm;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
