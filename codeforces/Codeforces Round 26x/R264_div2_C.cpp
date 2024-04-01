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

ll a[5005][5005];
ll d1[5005];
ll d2[5005];
ll r[2], x[2], y[2];

void check(ll a, ll b, ll c, ll v) {
    if (r[a] <= v) {
        r[a] = v;
        x[a] = b;
        y[a] = c;
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            d1[i + j] += a[i][j];
            d2[i + n - j - 1] += a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            check((i + j) % 2, i, j, d1[i + j] + d2[i + n - j - 1] - a[i][j]);
        }
    }

    cout << r[0] + r[1] << endl;
    cout << x[0] + 1 << ' ' << y[0] + 1 << ' ' << x[1] + 1 << ' ' << y[1] + 1 << endl;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
