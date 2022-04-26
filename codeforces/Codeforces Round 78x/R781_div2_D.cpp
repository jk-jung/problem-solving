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

bool divisible(ll x, ll y, ll div) {
    cout << "? " << x << " " << y << endl;
    cin >> x;
    return x % div == 0;
}

void solve() {
    ll r =0;
    ll a = 1 << 30;
    ll b = a + (1 << 29);
    for (int i = 0; i < 29; i++) {
        if (divisible(a, b, 1 << (i + 1))) {
        } else {
            r |= 1 << i;
            a -= (1 << i);
            b -= (1 << i);
        }
    }
    a -= (1 << 29);
    if(divisible(a, b, 1 << 30)) {
        r |= 1 << 29;
    }

    cout << "! " << r << endl;
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
