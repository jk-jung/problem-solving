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

int n, m, T;
int d[5005][5005];
int from[5005][5005];
vector<pi> v[5005];

int go(int pos, int cnt) {
    if (pos == 1 && cnt == 1) return 0;
    int &r = d[pos][cnt];
    if (r != -1) return r;

    r = 1e9 + 1;
    for (auto [x, y]: v[pos]) {
        int dis = go(x, cnt - 1) + y;
        if (dis < r) {
            r = dis;
            from[pos][cnt] = x;
        }
    }

    return r;
}

void dfs(int pos, int cnt) {
    if(cnt >= 2)dfs(from[pos][cnt], cnt - 1);
    cout << pos << " ";
}

void solve() {
    cin >> n >> m >> T;
    for (int i = 0, x, y, z; i < m; i++) {
        cin >> x >> y >> z;
        v[y].pb({x, z});
    }

    memset(d, -1, sizeof(d));
    for (int i = n; i >= 1; i--) {
        if (go(n, i) <= T) {
            cout << i << endl;
            dfs(n, i);
            return;
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
