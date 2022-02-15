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

int process(int y, int x, int n) {
    if (n == 0)return 0;
    if (n == 2) return a[y][x] ^ a[y][x + 1];

    int r = 0;
    if (n % 4 == 0) {
        for (int i = 1; i < n; i += 4) r ^= a[y][x + i] ^ a[y][x + i + 1];
        for (int i = 3; i < n - 2; i += 4) r ^= a[y + n - 1][x + i] ^ a[y + n - 1][x + i + 1];
        for (int i = 2; i < n; i += 4) {
            r ^= a[y + i][x] ^ a[y + i + 1][x];
            r ^= a[y + i][x + n - 1] ^ a[y + i + 1][x + n - 1];
        }
    }
    else {
        for (int i = 0; i < n; i += 4) r ^= a[y][x + i] ^ a[y][x + i + 1];
        for (int i = 2; i < n; i += 4) r ^= a[y + n - 1][x + i] ^ a[y + n - 1][x + i + 1];
        for (int i = 3; i < n; i += 4) {
            r ^= a[y + i][x] ^ a[y + i + 1][x];
            r ^= a[y + i][x + n - 1] ^ a[y + i + 1][x + n - 1];
        }
    }
    return r ^ process(y + 2, x + 2, n - 4);
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)cin >> a[i][j];
    }

    cout << process(0, 0, n) << endl;
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
