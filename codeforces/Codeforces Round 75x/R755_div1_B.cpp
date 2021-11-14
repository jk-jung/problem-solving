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

ll q(int i, int k) {
    cout << "? " << i << " " << k << endl;
    ll r;
    cin >> r;
    return r;
}

void solve() {
    int n;
    cin >> n;
    ll tot = q(1, n);

    int s = 1, e = n, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if (q(1, m) == tot) r = m, e = m - 1;
        else s = m + 1;
    }
    ll dif = tot - q(1, r - 1);
    ll k = r;
    ll j = k - dif;
    ll rest = tot - dif * (dif + 1) / 2;

    s = 1, e = n, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        if ((ll) m * (m - 1) / 2 >= rest)r = m, e = m - 1;
        else s = m + 1;
    }
    ll i = j - r;


    cout << "! " << i << " " << j << " " << k << endl;
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
