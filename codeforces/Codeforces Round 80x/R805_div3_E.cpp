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


vector<pi> v[200005];
int ck[200005];


int dfs(int x) {
    int r = 0;
    for (auto [z, idx]: v[x]) {
        if(ck[idx])continue;
        ck[idx] = 1;
        r += dfs(z) + 1;
    }
    return r;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)v[i].clear(), ck[i] = 0;

    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        v[x].pb({y, i});
        v[y].pb({x, i});
    }

    for (int i = 1; i <= n; i++) {
        if (v[i].size() != 2) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dfs(i) % 2) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
