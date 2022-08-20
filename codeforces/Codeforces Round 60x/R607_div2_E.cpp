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
vector<pi> v[200005];
int cnt[200005];
ll r1, r2;

bool dfs(int x, int y = -1) {
    cnt[x]++;
    int c = 1;
    for (auto [z, w]: v[x]) {
        if (z != y) {
            if (dfs(z, x)) {
                r1 += w;
                c++;
            }
            cnt[x] += cnt[z];
            r2 += min(cnt[z], n - cnt[z]) * (ll) w;
        }
    }
    return c % 2;
}

void solve() {
    cin >> n;
    n = n * 2;
    for (int i = 1, x, y, z; i < n; i++) {
        cin >> x >> y >> z;
        v[x].pb({y, z});
        v[y].pb({x, z});
    }

    r1 = 0, r2 = 0;
    dfs(1);
    cout << r1 <<" " << r2 << endl;


    for (int i = 1; i <= n; i++) {
        v[i].clear();
        cnt[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
