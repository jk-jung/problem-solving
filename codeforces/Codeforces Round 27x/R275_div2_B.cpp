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
    ll c1, c2, p1, p2;
    cin >> c1 >> c2 >> p1 >> p2;
    ll s = 1, e = 1ll << 40, r = -1;

    while (s <= e) {
        ll m = (s + e) / 2;
        ll d1 = max(0ll, c1 - m / p2 + m / (p1 * p2));
        ll d2 = max(0ll, c2 - m / p1 + m / (p1 * p2));
        ll rest = m - m / p1 - m / p2 + m / (p1 * p2);
        if (rest >= d1 + d2) {
            r = m;
            e = m - 1;
        } else {
            s = m + 1;
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
