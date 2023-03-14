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

ll check(ll n, ll m, ll c) {
    ll b = m, cnt = 0;
    while (b <= n) {
        cnt += n / b;
        if (b > n / m) break;
        b *= m;
    }
    return cnt / c;
}

void solve() {
    ll n, m;
    cin >> n >> m;
    ll r = 1ll << 60;
    for (ll i = 2; i * i <= m; i++) {
        int c = 0;
        while (m % i == 0) {
            m /= i;
            c++;
        }
        if(c)r = min(r, check(n, i, c));
    }
    if (m != 1) r = min(r, check(n, m, 1));
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
