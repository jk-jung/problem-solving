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
    int n;
    cin >> n;
    vi v(n);
    for (int &x: v)cin >> x;
    vector<pi> vv;
    for (int i = 0; i < n; i++)
        if (vv.empty() || vv.back().F != v[i])vv.pb(mp(v[i], i + 1));

    for (int i = 2; i < vv.size(); i++) {
        int a = vv[i - 2].F, b = vv[i - 1].F, c = vv[i].F;
        if ((a < b && b > c) || (a > b && b < c)) {
            cout << 3 << endl;
            cout << vv[i - 2].S << " " << vv[i - 1].S << " " << vv[i].S << endl;
            return;
        }
    }
    cout << 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
