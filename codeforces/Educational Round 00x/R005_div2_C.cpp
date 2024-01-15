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

char a[1005][1005];
int n, m;
int g[1005][1005], G;
int gc[1000005];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};


void dfs(int i, int j) {
    g[i][j] = G;
    gc[G]++;
    for (int k = 0; k < 4; k++) {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.' && !g[x][y]) {
            dfs(x, y);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.' && !g[i][j]) {
                G++;
                dfs(i, j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.')cout << a[i][j];
            else {
                int r = 0;
                set<int> ck;
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == '.') {
                        if (ck.count(g[x][y]))continue;
                        ck.insert(g[x][y]);
                        r += gc[g[x][y]];
                    }
                }
                cout << (r + 1) % 10;
            }
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
