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
    int n, r = 0;
    cin >> n;
    vi a(n), b(n);
    for (int i = 0; i < n; i++)cin >> a[i] >> b[i];
    ll cur = 0, tar = 0, last = 0;
    for (int i = 0; i < n; i++) {
        ll diff = a[i] - last;
        if (ab(cur - tar) <= diff) {
            cur = tar;
            tar = b[i];
        } else if (cur < tar) cur += diff;
        else cur -= diff;

        ll next = i + 1 == n ? (1ll << 50) : a[i + 1];
        ll tmp = next - a[i];
        ll cur2 = cur < tar ? min(tar, cur + tmp) : max(tar, cur - tmp);
        if (min(cur, cur2) <= b[i] && b[i] <= max(cur, cur2)){
            r++;
        }
        last = a[i];
    }
    cout << r << endl;
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
