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


void process(int n, int k) {
    vector<pi> r;
    if (k == n - 1) {
        if (n == 4) {
            cout << -1 << endl;
            return;
        }
        for (int x = 4; x < n / 2; x++) {
            int y = n - x - 1;
            r.pb({x, y});
        }
        r.pb({n - 2, n - 1});
        r.pb({1, 3});
        r.pb({2, n - 3});
        r.pb({n - 4, 0});
    } else {
        for (int x = 1; x < n / 2; x++) {
            int y = n - x - 1;
            if (x == k) {
                r.pb({x, n - 1});
                r.pb({y, 0});
            } else if (y == k) {
                r.pb({y, n - 1});
                r.pb({x, 0});
            } else r.pb({x, y});
        }
        if (k == 0)r.pb({0, n - 1});
    }

    for(auto x:r)cout << x.F <<" " <<x.S <<'\n';
}

void solve() {
    int n, k;
    cin >> n >> k;
    process(n, k);
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
