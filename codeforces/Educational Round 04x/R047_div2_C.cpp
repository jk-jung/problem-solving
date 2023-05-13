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

void solve() {
    ll n, m;
    cin >> n >> m;
    ll r = 0;
    while (m--) {
        ll x, y;
        cin >> x >> y;
        r += x * n;
        if (y < 0) {
            ll a = (n - 1) / 2;
            ll b = n / 2;
            r += a * (a + 1) / 2 * y;
            r += b * (b + 1) / 2 * y;
        } else {
            r += n * (n - 1) / 2 * y;
        }
    }
    printf("%.10lf", r / double(n));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
