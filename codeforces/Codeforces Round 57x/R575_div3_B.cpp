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
    ll n, k;
    ll s = 0, c = 0;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll &x: v)cin >> x, s += x, c += x % 2;
    if (s % 2 != k % 2 || c < k) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

    for (ll i = 0, ss = 0; i < n; i++) {
        ss += v[i];
        if (ss % 2) {
            if (k == 1)break;
            cout << i + 1 << " ";
            k--;
            ss = 0;
        }
    }
    cout << n << endl;
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
