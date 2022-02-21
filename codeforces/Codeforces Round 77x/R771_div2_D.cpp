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

int a[1005][1005];
int b[1005][1005];
int covered[1005][1005];
int used[1005][1005];

int dx[4] = {0, 1, 0, 1};
int dy[4] = {0, 0, 1, 1};

vi vc, vy, vx;


void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (covered[i][j])continue;
            int c = a[i][j], cnt = 0;
            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if (a[y][x] == c)cnt++;
            }

            if (cnt != 4)continue;

            vc.pb(c);
            vy.pb(i);
            vx.pb(j);
            used[i][j] = 1;

            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                covered[y][x] = 1;
            }
        }
    }
    int pos = 0;
    while (pos < vc.size()) {
        int i = vy[pos];
        int j = vx[pos++];

        for (int k = 0; k < 4; k++) {
            int y = i + dy[k];
            int x = j + dx[k];
            covered[y][x] = 1;
        }

        for (int p = i - 1; p <= i + 1; p++) {
            for (int q = j - 1; q <= j + 1; q++) {
                if (p < 0 || p >= n - 1 || q < 0 || q >= m - 1)continue;
                if (used[p][q])continue;

                int last = -1, ok = 1;
                for (int k = 0; k < 4; k++) {
                    int y = p + dy[k];
                    int x = q + dx[k];
                    if (covered[y][x])continue;
                    if (last != -1 && last != a[y][x])ok = 0;
                    last = a[y][x];
                }
                if (ok && last != -1) {
                    used[p][q] = 1;
                    vc.pb(last);
                    vy.pb(p);
                    vx.pb(q);
                }
            }
        }
    }

    reverse(vc.begin(), vc.end());
    reverse(vy.begin(), vy.end());
    reverse(vx.begin(), vx.end());

    for (int t = 0; t < vc.size(); t++) {
        int c = vc[t];
        int i = vy[t];
        int j = vx[t];

        for (int k = 0; k < 4; k++) {
            int y = i + dy[k];
            int x = j + dx[k];
            b[y][x] = c;
        }
    }

    bool ok = true;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (a[i][j] != b[i][j])ok = false;
    if (!ok) {
        cout << -1;
    } else {
        cout << vc.size() << endl;
        for (int i = 0; i < vc.size(); i++)
            cout << vy[i] + 1 << " " << vx[i] + 1 << " " << vc[i] << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
