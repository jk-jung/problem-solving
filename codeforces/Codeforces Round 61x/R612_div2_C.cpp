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

void solve() {
    int n;
    cin >> n;
    vi v(n), c(n + 1);
    for (int &x: v)cin >> x, c[x] = 1;
    int t[2] = {0, 0};
    for (int i = 1; i <= n; i++)if (!c[i])t[i % 2]++;

    int last = 0, r = 0, len = 0;
    vector<tuple<int, int, int>> vv;
    for (int x: v) {
        if (x) {
            if (last == 0)last = x;
            if (x % 2 == last % 2) {
                if (len)
                    vv.pb({x == last ? -1 : -2, len, x % 2});
            } else r++;

            last = x;
            len = 0;
        } else len++;
    }
    if (len) vv.pb({-1, len, last % 2});

    sort(vv.begin(), vv.end());
    for (auto [z, x, y]: vv) {
        if (t[y] >= x) {
            t[y] -= x;
        } else r -= z;
    }


    if (r == 0 && n >= 2)r = 1;
    if(n == 1) r= 0;
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
