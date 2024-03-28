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
    int p, q, l, r;
    cin >> p >> q >> l >> r;
    vector<pi> a(p), b(q);
    for (int i = 0; i < p; i++) cin >> a[i].F >> a[i].S;
    for (int i = 0; i < q; i++) cin >> b[i].F >> b[i].S;

    int rst = 0;
    for (int i = l; i <= r; i++) {
        bool ok = false;
        for(auto x: a) {
            for(auto y: b) {
                if (x.S < y.F + i || x.F > y.S + i) continue;
                ok = true;
                break;
            }
            if (ok) break;
        }
        if (ok) rst++;
    }
    cout << rst;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
