#include <string.h>
#include <stdio.h>
#include <math.h>
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


int go(vi &v, int s, int e, int bit) {
    int a0 = 0, a1 = 0;
    for (int i = s; i <= e; i++) {
        if (i >> bit & 1)a1++;
        else a0++;
    }

    vi b1, b0;
    for (int x: v) {
        if (x >> bit & 1) b1.pb(x);
        else b0.pb(x);
    }
    int r = 0;
    if (a1 != b1.size() && a1 == b0.size()) {
        r ^= (1 << bit);
        swap(b1, b0);
    }

    if (bit > 0) {
        if(!b1.empty()) {
            int mask = (1 << bit) - 1;
            int t = e & mask;
            r ^= go(b1, e ^ t, e, bit - 1);
        }else {
            r ^= go(b0, s, e, bit - 1);
        }
    }
    return r;
}

void solve() {
    int s, e;
    cin >> s >> e;
    vi v(e + 1);
    for (int &x: v)cin >> x;

    int r = go(v, s, e, 18);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
