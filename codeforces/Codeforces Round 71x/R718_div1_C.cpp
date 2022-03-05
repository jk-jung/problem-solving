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

int r[505][505];

int dx[] = {-1, 0};
int dy[] = {0, 1};

void solve() {
    int n;
    cin >> n;

    vi v(n);

    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        int cnt = k - 1;
        r[i][i] = k;
        int y = i, x = i;
        while (cnt--) {
            for (int t = 0; t < 2; t++) {
                int ny = y + dy[t];
                int nx = x + dx[t];

                if (ny < 0 || nx < 0 || ny >= n || nx >= n || r[ny][nx])continue;
                y = ny;
                x = nx;
                r[y][x] = k;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)cout << r[i][j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

        solve();
}
