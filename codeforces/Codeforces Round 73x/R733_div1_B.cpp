#include <string.h>
#include <stdio.h>
#include <math.h>
#include <map>
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
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int a[22][22];
int C;
bool print;

void go(int y, int x, int cnt) {
    C = max(C, cnt);
    if (cnt == C && print) {
        print = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << a[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
    if (x == m) {
        x = 0;
        y++;
    }
    if (y == n && x == 0) return;

    if (0 < y && y < n - 1 && 0 < x && x < m - 1)
        return go(y, x + 1, cnt);

    bool ok = true;
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
        if (a[ny][nx] == 1)ok = false;
    }

    if (ok) {
        a[y][x] = 1;
        go(y, x + 1, cnt + 1);
        a[y][x] = 0;
    }
    else {
        go(y, x + 1, cnt);
    }
}

void solve() {
    cin >> n >> m;
    C = 0;
    print = false;
    go(0, 0, 0);
    go(0, 1, 0);
    print = true;
    if(print)go(0, 0, 0);
    if(print)go(0, 1, 0);
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
