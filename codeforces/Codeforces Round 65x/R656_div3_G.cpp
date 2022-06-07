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


int v[2][200005];
int ck[200005];
vi cc[2];
pi pos[400005];


void dfs(int y, int x) {
    cc[y].pb(x);
    ck[x] = 1;

    auto [ny, nx] = pos[v[y ^ 1][x] ^ 1];

    if (!ck[nx])
        dfs(ny, nx);
}

void solve() {
    int n;
    cin >> n;
    vi cnt(n);

    for (int i = 0; i < 2; i++) {
        for (int j = 0, x; j < n; j++) {
            ck[j] = 0;
            cin >> x;
            x--;
            int idx = x * 2 + cnt[x];
            v[i][j] = idx;
            pos[idx] = {i, j};
            cnt[x]++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] != 2) {
            cout << "-1\n";
            return;
        }
    }

    vi r;
    for (int j = 0; j < n; j++) {
        if (!ck[j]) {
            cc[0].clear(), cc[1].clear();
            dfs(0, j);
            int k = cc[0].size() < cc[1].size() ? 0 : 1;
            for (int x: cc[k])r.pb(x);
        }
    }

    cout << r.size() << '\n';
    for (int x: r)cout << x + 1 << " ";
    cout << endl;
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
