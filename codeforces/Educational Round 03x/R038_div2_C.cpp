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
    ll n;
    cin >> n;
    if (n == 0) {
        cout << "1 1\n";
        return;
    }

    for (ll i = 2; i * i - (i / 2) * (i / 2) <= n; i++) {
        ll m = i * i - n;
        if (m < 0)continue;
        ll t = sqrt(m);
        while (t * t < m) t++;
        while (t * t > m) t--;
        if (t > i || t <= 0)continue;
        ll r = i / t;
        if (i * i - (i / r) * (i / r) == n) {
            cout << i << " " << i / t << endl;
            return;
        }
    }
    cout << "-1\n";
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
