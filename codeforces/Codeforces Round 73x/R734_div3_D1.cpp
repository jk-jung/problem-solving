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

char r[105][105];
int n, m, k1, k2;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void fill(int y, int x, int yn, int xn) {
    vector<int> v(26);
    for (int i = 0; i < yn; i++) {
        for (int j = 0; j < xn; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = y + i + dy[k];
                int nx = x + j + dx[k];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m || !r[ny][nx])continue;
                v[r[ny][nx] - 'a']++;
            }
        }
    }
    for (int c = 0; c < 26; c++) {
        if (v[c]) continue;
        for (int i = 0; i < yn; i++) {
            for (int j = 0; j < xn; j++) {
                int ny = y + i;
                int nx = x + j;

                r[ny][nx] = 'a' + c;
            }
        }
        break;
    }
}

void solve() {
    cin >> n >> m >> k1;
    k2 = n * m / 2 - k1;

    memset(r, 0, sizeof(r));

    if (n & 1) {
        for (int i = 0; i < m; i += 2)
            r[0][i] = r[0][i + 1] = 'a' + (i / 2) % 26, k1--;
    }
    if (m & 1) {
        for (int i = 0; i < n; i += 2)
            r[i][0] = r[i + 1][0] = 'a' + (i / 2) % 26, k2--;
    }

    if (k1 < 0 || k2 < 0 || k1 & 1 || k2 & 1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = n & 1; i < n; i++) {
        for (int j = m & 1; j < m; j++) {
            if (r[i][j]) continue;
            if (k2) fill(i, j, 2, 1), k2--;
            else fill(i, j, 1, 2), k1--;
        }
    }

    cout << "YES" << endl;
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
