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


int d[105][10005];

void ckmin(int &x, int y) {
    if (y == -1)return;
    if (x == -1) x = y;
    x = min(x, y);
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int &x: a)cin >> x;
    for (int &x: b)cin >> x;

    memset(d, -1, sizeof(d));
    d[0][a[0]] = 0;
    d[0][b[0]] = 0;
    int s = a[0] + b[0];
    for (int i = 1; i < n; i++) {
        for (int k = 0; k < 10000; k++) {
            int x = d[i - 1][k];
            if (x == -1)continue;

            int k2 = s - k;
            ckmin(d[i][k + a[i]], x + k * a[i] + k2 * b[i]);
            ckmin(d[i][k + b[i]], x + k * b[i] + k2 * a[i]);
        }
        s += a[i] + b[i];
    }
    int r = 1 << 30;
    for (int k = 0; k <= 10000; k++)ckmin(r, d[n - 1][k]);
    r *= 2;
    for(int x:a)r += x * x * (n - 1);
    for(int x:b)r += x * x * (n - 1);
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
