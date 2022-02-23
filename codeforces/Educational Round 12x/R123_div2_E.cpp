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
    int n, m;
    string s;
    cin >> n >> s;
    m = s.size();

    if (s[0] == 'D') for (char &x: s)x = (x == 'D' ? 'R' : 'D');
    int R = 0, D = 0;
    for (char x: s) {
        if (x == 'R') R++;
        else D++;
    }

    vector<pi> xx, yy;
    ll r = 0;
    int pos = 0, start_x = 1, start_y = 1, x = 0, y = 0;
    while (pos < m) {
        while (pos < m && s[pos] == 'R') pos++, x++;

        int end_x = n - (R - x);
        int end_y = y == 0 ? start_y : n - (D - y);

        xx.pb({start_x, end_x});
        yy.pb({start_y, end_y});

        if(pos == m)break;
        while (pos < m && s[pos] == 'D') pos++, y++;

        start_x = x + 1;

        end_x = n - (R - x);
        end_y = n - (D - y);

        xx.pb({start_x, end_x});
        yy.pb({start_y, end_y});

        start_y = y + 1;
    }

    for (int i = 0; i < xx.size(); i++) {
        ll x = xx[i].S - xx[i].F + 1;
        ll y = yy[i].S - yy[i].F + 1;
        r += x * y;
        if (i) {
            ll mx = min(xx[i].S, xx[i - 1].S) - max(xx[i].F, xx[i - 1].F) + 1;
            ll my = min(yy[i].S, yy[i - 1].S) - max(yy[i].F, yy[i - 1].F) + 1;
            r -= mx * my;
        }

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
