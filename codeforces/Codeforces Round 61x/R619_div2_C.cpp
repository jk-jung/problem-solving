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
    ll n, m;
    ll t = 0;
    cin >> n >> m;
    if (n != m) {
        ll a = n / (m + 1);
        ll b = a + 1;
        ll re = n % (m + 1);

        ll c1 = m + 1 - re;
        ll c2 = re;

        ll k = min(c2, m);
        c2 -= k;
        m -= k;
        c1 += k;
        c1 -= m;

        ll c3 = m;
        ll c = a - 1;
        t = (a * (a + 1) / 2) * c1 + (b * (b + 1) / 2) * c2 + (c * (c + 1) / 2) * c3;
    }
    cout << (n * (n + 1) / 2) - t << endl;
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
