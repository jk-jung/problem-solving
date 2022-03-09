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
    ll r = 1ll << 60;

    int even, odd = 1 << 30;
    cin >> even;
    ll ss = even;
    for (int i = 1, x; i < n; i++) {
        cin >> x;

        ss += x;
        if (i % 2)odd = min(odd, x);
        else even = min(even, x);

        ll e_cnt = n - (i / 2 + 1);
        ll o_cnt = n - ((i + 1) / 2);

        r = min(r, ss + even * e_cnt + odd * o_cnt);
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
