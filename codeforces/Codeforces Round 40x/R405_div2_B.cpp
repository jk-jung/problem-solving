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

vector<int> v[150005];
int ck[150005];
vi tt;

void dfs(int x) {
    tt.pb(x);
    ck[x] = 1;
    for (int y: v[x]) {
        if (!ck[y]) dfs(y);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    for (int i = 1; i <= n; i++) {
        if (ck[i])continue;
        tt.clear();
        dfs(i);
        for (int x: tt)
            if (v[x].size() != tt.size() - 1) {
                cout << "NO" << endl;
                return;
            }
    }
    cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
