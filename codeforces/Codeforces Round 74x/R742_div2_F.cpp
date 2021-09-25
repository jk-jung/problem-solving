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
int r[505][505];
char a[505][505];
vector<pi> v[505][505];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int y, int x, int c) {
    r[y][x] = c;
    for (auto[ny, nx]: v[y][x]) {
        if (r[ny][nx]) continue;
        dfs(ny, nx, 5 - c);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != 'X') continue;

            vector<pi> t;
            for (int k = 0; k < 4; k++) {
                int y = i + dy[k];
                int x = j + dx[k];
                if (a[y][x] == '.')t.pb({y, x});
            }
            if (t.size() % 2) {
                cout << "NO\n" << endl;
                return;
            }
            r[i][j] = 5 * t.size() / 2;
            for (int p = 0; p < t.size(); p++) {
                int q = (p + 1) % t.size();
                v[t[p].F][t[p].S].pb(t[q]);
                v[t[q].F][t[q].S].pb(t[p]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (r[i][j] == 0 && a[i][j] == '.')dfs(i, j, 1);
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)cout << r[i][j] << " ";
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    solve();
}
