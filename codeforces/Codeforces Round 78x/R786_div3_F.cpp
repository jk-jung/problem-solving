#include<string.h>
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

char a[1005][1005];

void solve() {
    int n, m, q, cnt = 0, ok = 0;
    cin >> n >> m >> q;
    for (int i = 0; i < n; i++)cin >> a[i];
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cnt += a[i][j] == '*';
    for (int i = 0, y = 0, x = 0; i < cnt; i++) {
        if (a[y][x] == '*') ok++;
        y++;
        if (y == n)y = 0, x++;
    }
    while (q--) {
        int y, x;
        cin >> y >> x;
        y--, x--;

        int pos = x * n + y;
        if (a[y][x] == '*') {
            if (pos < cnt)ok--;
            int t = cnt - 1;
            if (pos != t && a[t % n][t / n] == '*')ok--;
            a[y][x] = '.', cnt--;
        } else {
            a[y][x] = '*', cnt++;
            if (pos < cnt)ok++;
            int t = cnt - 1;
            if (pos != t && a[t % n][t / n] == '*')ok++;
        }

        cout << cnt - ok << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
