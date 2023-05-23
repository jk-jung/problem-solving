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

ll a, b, c, d;

ll f(ll x) {
    if (x % c)return 0;
    ll y = d / x * c;
    if (gcd(x, y) != c)return 0;
    return a <= x && x <= b && a <= y && y <= b;
}

void solve() {
    cin >> a >> b >> c >> d;
    ll r = 0;
    for (ll i = 1; i * i <= d; i++) {
        if (d % i)continue;
        r += f(i);
        if (d / i != i)r += f(d / i);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
