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
    int n;
    cin >> n;
    vi v(n);

    ll r = 0;
    for (int &x: v)cin >> x;
    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            ll a = 1ll << 60;
            ll b = -a;
            for (int j = i; j <= n; j += i) {
                ll s = 0;
                for (int k = j - i; k < j; k++)s += v[k];
                a = min(a, s);
                b = max(b, s);
            }
            r = max(r, b - a);
        }
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
