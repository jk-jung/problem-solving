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

ll d[5555][5555];

void solve() {
    int n, m, k;
    cin >> n >> k >> m;
    vector<ll> v(n), acc(n);
    for (ll &x: v)cin >> x;
    for (int i = k - 1; i < n; i++) {
        for (int j = 0; j < k; j++)acc[i] += v[i - j];
    }

    for (int i = k; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            d[i][j] = d[i - 1][j];
            if (j) d[i][j] = max(d[i][j], d[i - k][j - 1] + acc[i - 1]);
        }
    }
    cout << d[n][m] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
