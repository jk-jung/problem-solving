#include <cstring>
#include <cstdio>
#include <cmath>
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
    ll a, b, c;
    cin >> a >> b >> c;
    if(c <= 2) {
        cout << 0 << endl;return;
    }
    ll d = (c - 1) / 2;
    ll n = (b * c + d - 1) / d;
    if (a >= n) {
        cout << b * c << endl;
    } else {
        ll r = (a - 1) * d;
        ll t = (b * c - r) % c;
        if(t >= (c + 1) / 2) r -= (c - t);
        else r += t;
        cout << r << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
