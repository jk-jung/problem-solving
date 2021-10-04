#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <map>
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
int vis[605];
ll v[605][605];
ll d[605];

void ckmin(ll &x, ll y) { x = min(x, y); }

void solve() {
    memset(d, 63, sizeof(d));
    memset(v, 63, sizeof(v));

    cin >> n >> m;
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        ckmin(v[a][b], c);
    }

    for (int i = 0; i < n; i++) {
        memset(d, 63, sizeof(d));
        memset(vis, 0, sizeof(vis));

        for (int k = 0; k < n; k++)d[k] = v[i][k];
        for (int t = 1; t < n; t++) {
            int x = -1;
            for (int k = 0; k < n; k++) if (!vis[k] && (x == -1 || d[k] < d[x])) x = k;
            vis[x] = 1;

            ckmin(d[(x + 1) % n], d[x] + 1);
            for (int k = 0; k < n; k++) {
                ckmin(d[(k + d[x]) % n], d[x] + v[x][k]);
            }
        }

        for (int k = 0; k < n; k++)cout << (i == k ? 0 : d[k]) << " ";
        cout << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
