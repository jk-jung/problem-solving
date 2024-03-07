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

ll h, n;
ll r = 0;

void go(ll s, ll e, ll k, ll dep) {
    ll m = (s + e) / 2;

    r++;
    if (dep == h)return;
    if (k % 2 == 1) {
        // left first
        if (n < m) {
            go(s, m, k * 2, dep + 1);
        } else {
            r += (1ll << (h - dep)) - 1;
            go(m, e, k * 2 + 1, dep + 1);
        }
    } else {
        // right first
        if (n < m) {
            r += (1ll << (h - dep)) - 1;
            go(s, m, k * 2, dep + 1);
        } else {
            go(m, e, k * 2 + 1, dep + 1);
        }
    }
}

void solve() {
    cin >> h >> n;
    n--;
    go(0, 1ll << h, 1, 0);
    cout << r - 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
