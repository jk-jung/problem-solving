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

ll r[1005][1005];

void solve() {
    ll n, k, m;
    cin >> n >> k >> m;

    ll a = 1;
    for (int i = 0; i < m; i++) {
        a *= k;
        if (a > n)a = n + 1;
    }
    if (a < n) {
        cout << -1 << endl;
        return;
    }

    for (ll i = 0; i < n; i++) {
        ll t = i;
        for (int j = 0; j < m; j++) {
            r[i][j] = t % k + 1;
            t /= k;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            cout << r[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
