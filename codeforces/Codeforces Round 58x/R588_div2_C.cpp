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

int n, m;
vi v[10];
int vis[10];

int dfs(int x) {

}

void solve() {
    cin >> n >> m;
    for (int i = 0, x, y; i < m; i++) {
        cin >> x >> y;
        v[x].pb(y);
        v[y].pb(x);
    }
    if (n < 7) {
        cout << m << endl;
    } else {
        int r = 0;
        for (int i = 1; i <= 7; i++) {
            int t = 0;
            for (int x = 1; x <= 7; x++) {
                for (int y: v[x]) {
                    if (x != i && y != i && x < y)t++;
                }
            }
            int mm = 0;
            for (int x = 1; x <= 7; x++) {
                if (x == i)continue;
                int cc = 0;
                for (int y: v[i]) {
                    bool ok = true;
                    for (int z: v[x])if (z == y)ok = false;
                    if (ok)cc++;
                }
                mm = max(mm, cc);
            }
            r = max(r, t + mm);
        }
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
