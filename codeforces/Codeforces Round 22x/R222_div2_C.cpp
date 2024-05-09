#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n, m, k;
vector<string> a;

void dfs(int i, int j) {
    if (k == 0)return;
    k--;
    a[i][j] = '*';
    for (int l = 0; l < 4; l++) {
        int y = i + dy[l];
        int x = j + dx[l];
        if (x < 0 || y < 0 || x >= m || y >= n || a[y][x] != '.')continue;
        dfs(y, x);
    }
}

void solve() {
    cin >> n >> m >> k;
    a.resize(n);
    for (auto &x: a)cin >> x;
    k = -k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[i][j] == '.')k++;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] != '.')continue;
            dfs(i, j);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.')cout << 'X';
            else if (a[i][j] == '*')cout << '.';
            else cout << a[i][j];
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
