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
    ll n, k;
    cin >> n >> k;

    ll nn = n * 2 - 1;
    ll s = 0, e = n * 2 - 1, r = 0;

    while (s <= e) {
        ll m = (s + e) / 2;
        ll t = 0;
        if (m <= n) t += m * (m + 1) / 2;
        else t += n * (n + 1) / 2;
        if (m > n) {
            t += n * (n - 1) / 2;
            t -= (nn - m) * (nn - m + 1) / 2;
        }

        if (t < k)r = m, s = m + 1;
        else e = m - 1;
    }
    if (r != n * 2 -1) r ++;
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
