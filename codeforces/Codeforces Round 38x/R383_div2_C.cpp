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

int a[1005], n;
int c[1005];

int dfs(int x, int y) {
    if (c[x] == 1) {
        if (x == y)return 0;
        else return -(1 << 30);
    }
    c[x] = 1;
    return 1 + dfs(a[x], y);
}

void solve() {
    cin >> n;

    ll r = 1;
    for (int i = 1; i <= n; i++)cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (!c[i]) {
            ll t = dfs(i, i);
            if (t < 0) {
                cout << -1 << endl;
                return;
            }
            if (t % 2 == 0)t /= 2;
            r = r / gcd(r, t) * t;
        }
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
