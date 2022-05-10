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


ll f(ll x) {
    ll r = 0;
    while (x)r += x % 10, x /= 10;
    return r;
}

void solve() {
    ll n, x;
    cin >> n >> x;
    ll m = n;
    if(f(m) <= x) {
        cout << 0 << endl;
        return;
    }
    for (ll i = 10;; i *= 10) {
        m += (i - m % i);
        if(f(m) <= x) {
            cout << m - n << endl;
            return;
        }
    }
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
