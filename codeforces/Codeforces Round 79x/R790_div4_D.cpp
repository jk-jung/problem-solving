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

int n, m, CK;

int dfs(int y, int x, int dy, int dx, int s, vector<vi> &a, vector<vi> &ck) {
    if(y == -1 || x == -1 || y == n || x == m)
        return s;
    else {
        ck[y][x] = CK;
        a[y][x] = dfs(y + dy, x + dx, dy, dx, s + a[y][x], a, ck);
        return a[y][x];
    }
}

void solve() {

    cin >> n >> m;
    vector<vi> v(n, vi(m)), ck(n, vi(m));
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> v[i][j];
    vector<vi> a = v, b = v;

    CK = 1;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (ck[i][j] == 0)dfs(i, j, 1, 1, 0, a, ck);
    CK = 2;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (ck[i][j] == 1)dfs(i, j, 1, -1, 0, b, ck);

    int r = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)r = max(r, a[i][j] + b[i][j] - v[i][j]);
    cout << r << endl;
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
