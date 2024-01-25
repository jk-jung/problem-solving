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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    vector<pi> vv;
    vv.pb({-100, 0});

    int r = 0;
    for (int x: v) {
        if (x != vv.back().F) vv.pb({x, 0});
        r = max(r, ++vv.back().S);
    }

    for (int i = 2; i < vv.size(); i++) {
        int x = vv[i - 1].F;
        int y = vv[i].F;
        if (ab(x - y) == 1) {
            int t = vv[i-1].S;
            while(i < vv.size() && (vv[i].F == y || vv[i].F == x)) t += vv[i++].S;
            r = max(r, t);
            i--;
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
