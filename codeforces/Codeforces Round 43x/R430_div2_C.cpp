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

int a[200005];
int d[200005];
int c[200005];
vi v[200005];
vi p;

void dfs(int x, int y = -1) {
    for (int z: v[x]) {
        if (z == y)continue;
        d[z] = gcd(d[x], a[z]);
        dfs(z, x);
    }
}

void dfs2(int x, int y = -1, int dep=1) {
    for (int k: p){
        if (a[x] % k == 0) c[k]++;
        if(c[k] >= dep - 1)d[x] = max(d[x], k);
    }
    for (int z: v[x]) {
        if (z == y)continue;
        dfs2(z, x, dep + 1);
    }
    for (int k: p)if (a[x] % k == 0) c[k]--;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    d[1] = 0;
    dfs(1);

    for (int i = 1; i * i <= a[1]; i++) {
        if (a[1] % i == 0) {
            p.pb(i);
            if (i != a[1] / i)
                p.pb(a[1] / i);
        }
    }
    dfs2(1);
    for (int i = 1; i <= n; i++)cout << d[i] << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
