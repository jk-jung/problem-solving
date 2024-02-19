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

int n, m, b, mod;
int a[10005];

int d1[505][505];
int d2[505][505];

void solve() {
    cin >> n >> m >> b >> mod;
    for (int i = 0; i < n; i++)cin >> a[i];

    d1[0][0] = 1;
    for (int i = 0; i < n; i++) {
        memset(d2, 0, sizeof(d2));

        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= b; k++) {
                d2[j][k] = (d2[j][k] + d1[j][k]) % mod;
                int st = k + a[i];
                if (j && st <= b) {
                    d2[j][st] = (d2[j][st] + d2[j - 1][k]) % mod;
                }
            }
        }
        memcpy(d1, d2, sizeof(d2));
    }
    int r = 0;
    for (int i = 0; i <= b; i++) {
        r = (r + d1[m][i]) % mod;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
