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
    ll m;
    cin >> m;

    ll s = 8, e = m * 100, r = -1;
    while (s <= e) {
        ll x = (s + e) / 2;

        ll cnt = 0;
        ll mm = 0;
        for (ll i = 2;; i++) {
            ll t = x / (i * i * i);
            if (!t)break;
            mm = max(mm, t * i * i * i);
            cnt += t;
        }
        if (cnt >= m) {
            e = x - 1;
            if (cnt == m)r = mm;
        } else {
            s = x + 1;
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
