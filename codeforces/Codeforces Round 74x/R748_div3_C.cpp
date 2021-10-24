#include <string.h>
#include <stdio.h>
#include <math.h>
#include <cassert>
#include <set>
#include <map>
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
    int t, n;
    cin >> t >> n;
    vi v(n);
    for (int i = 0; i < n; i++)cin >> v[i];
    sort(v.begin(), v.end());
    v.pb(t);

    int s = 1, e = n, r = 0;
    while (s <= e) {
        int m = (s + e) / 2;
        bool ok = true;
        ll pos = 0;
        for (int i = n - m, c = 1; i < n; i++, c++) {
            ll need = (ll) (v[i + 1] - v[i]) * c;
            pos += need;

            if(pos >= v[i + 1]) {ok = false; break;}
        }

        if (ok) r = m, s = m + 1;
        else e = m - 1;
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
