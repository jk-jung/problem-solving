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
    ll n, s;
    cin >> n >> s;
    vi v(n);
    for (int &x: v)cin >> x;

    vector<pi> x;
    ll t = 0, i = 0;
    for (; i < n; i++) {
        if (t + v[i] > s)break;
        t += v[i];
        x.pb({v[i], i + 1});
    }
    sort(x.begin(), x.end());

    if (i == 0)cout << 1 << endl;
    else if (i == n) {
        cout << 0 << endl;
    } else if (x.back().F <= v[i]) {
        cout << i + 1 << endl;
    }
    else cout << x.back().S << endl;

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
