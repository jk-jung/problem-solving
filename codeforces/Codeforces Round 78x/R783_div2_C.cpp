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
    vi v(n);
    for (int &x: v)cin >> x;

    ll r = 1ll << 60;
    for (int i = 0; i < n; i++) {

        ll last = 0, cnt = 0;
        for (int k = i + 1; k < n; k++) {
            ll x = (last + v[k]) / v[k];
            cnt += x;
            last = x * v[k];
        }
        last = 0;
        for (int k = i - 1; k >= 0; k--) {
            ll x = (last + v[k]) / v[k];
            cnt += x;
            last = x * v[k];
        }
        r = min(r, cnt);
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
