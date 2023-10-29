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

int n;
vi v[200005];
int r[200005];
int m = 0;

void dfs(int x, int y, int c) {
    m = max(m, r[x]);
    int idx = 1;
    for (int z: v[x]) {
        if (z != y) {
            while (idx == r[x] || idx == c)idx++;
            r[z] = idx++;
            dfs(z, x, r[x]);
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }

    r[1] = 1;
    dfs(1, 0, 1);

    cout << m << endl;
    for (int i = 1; i <= n; i++)cout << r[i] << " ";

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
