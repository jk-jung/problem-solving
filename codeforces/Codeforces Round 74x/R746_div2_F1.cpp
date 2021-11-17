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

char a[505][505];
int d[505][505];
int n, m;

int calc() {
    int r = 0;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j] == 'B') d[i][j]++;
            if (a[i + 1][j] == 'B') d[i][j]++;
            if (a[i][j + 1] == 'B') d[i][j]++;
            if (a[i + 1][j + 1] == 'B') d[i][j]++;
            d[i][j] %= 2;
            r += d[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m - 1; j++) {
            if (d[n - 1][m - 1] == 0)continue;
            if (d[i][m - 1] == 0)continue;
            if (d[n - 1][j] == 0)continue;
            if (d[i][j] == 0)continue;
            return r - 1;
        }
    return r;
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> a[i][j];
    cout << calc() << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
