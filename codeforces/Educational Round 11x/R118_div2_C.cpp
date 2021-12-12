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
    ll n, h;
    cin >> n >> h;
    vi v(n);
    for (int &x: v)cin >> x;

    ll s = 1, e = h, r = 1;
    while (s <= e) {
        ll m = (s + e) / 2;
        ll t = 0, last = 0;
        for (int x: v) {
            if (last >= x)
                t -= (last - x + 1);
            t += m;
            last = m + x - 1;
        }

        if (t >= h)r = m, e = m - 1;
        else s = m + 1;
    }
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
