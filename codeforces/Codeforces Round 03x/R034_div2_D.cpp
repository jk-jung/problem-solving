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


int n, r1, r2;
int p[50005];
vi v[50005];


void dfs(int x, int y = 0) {
    for (int z: v[x]) {
        if (z == y)continue;
        p[z] = x;
        dfs(z, x);
    }
}

void solve() {
    cin >> n >> r1 >> r2;
    for (int i = 1, x; i <= n; i++) {
        if (i == r1)continue;
        cin >> x;
        v[i].pb(x);
        v[x].pb(i);
    }

    dfs(r2);

    for (int i = 1; i <= n; i++) {
        if (i != r2)cout << p[i] << " ";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
