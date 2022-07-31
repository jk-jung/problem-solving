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


ll xs, ys, t, ax, ay, bx, by;

int check(vector<ll> &xx, vector<ll> &yy) {
    int r =0 ;
    for (int k = 0; k < xx.size(); k++) {
        ll a = xs, b = ys;
        ll remain = t;
        int cnt =0;
        for(int i=k;i<xx.size();i++){
            ll d = ab(xx[i] - a) + ab(yy[i] - b);
            if (d > remain) break;
            remain -= d;
            cnt++;
            a = xx[i], b = yy[i];
        }

        r = max(r, cnt);
    }
    return r;
}

void solve() {
    ll x0, y0;

    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;

    vector<ll> xx, yy;
    for (; x0 <= xs + t && y0 <= ys + t;) {
        xx.pb(x0), yy.pb(y0);
        x0 = ax * x0 + bx;
        y0 = ay * y0 + by;
    }
    int r = check(xx, yy);
    reverse(xx.begin(), xx.end()), reverse(yy.begin(), yy.end());
    r = max(r, check(xx, yy));

    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
}
