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

ll n, m;
vi a, b;
ll d[1005][20][2][20][2];

ll go(ll st, ll a0, ll a1, ll b0, ll b1) {
    if(a0 == a.size() && b0 == b.size())return 1;

    ll &r = d[st][a0][a1][b0][b1];
    if (r != -1)return r;

    r = 0;

    if (a0 < a.size()) {
        for (int i = 0; i <= (a1 == 0 ? a[a0] : 6); i++) {
            if(st >> i & 1)continue;
            r += go(st | (1 << i), a0 + 1, a1 || (a1 == 0 && i < a[a0]), b0, b1);
        }
    } else {
        for (int i = 0; i <= (b1 == 0 ? b[b0] : 6); i++) {
            if(st >> i & 1)continue;
            r += go(st | (1 << i), a0, a1, b0 + 1, b1 || (b1 == 0 && i < b[b0]));
        }
    }

    return r;
}

void solve() {
    cin >> n >> m;
    memset(d, -1, sizeof(d));
    n--;m--;
    while (n) {
        a.pb(n % 7);
        n /= 7;
    }
    while (m) {
        b.pb(m % 7);
        m /= 7;
    }
    if(a.empty())a.pb(0);
    if(b.empty())b.pb(0);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    cout << go(0, 0, 0, 0, 0) << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
