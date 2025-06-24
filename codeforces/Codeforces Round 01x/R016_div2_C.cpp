#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))


void solve() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    ll g = gcd(c, d);
    c /= g;
    d /= g;

    ll r = 0, s = 1, e = 1e9;
    while (s <= e) {
        ll m = (s + e) / 2;
        if (c * m <= a && d * m <= b) {
            r = m;
            s = m + 1;
        } else {
            e = m - 1;
        }
    }
    cout << c * r << " " << d * r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
