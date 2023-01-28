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
    ll n, p, w, d;
    cin >> n >> p >> w >> d;

    ll g = gcd(w, d);
    ll G = w * d / g;
    ll r = p / G;
    p %= G;
    if (r){
        r --;
        p += G;
    }
    for (ll i = 0; i * w <= p; i++) {
        ll rest = p - i * w;
        if (rest % d == 0) {
            ll x = r * (G / w) + i;
            ll y = rest / d;
            ll z = n - x - y;
            if (x >= 0 && y >= 0 && z >= 0) {
                cout << x << " " << y << " " << z << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
