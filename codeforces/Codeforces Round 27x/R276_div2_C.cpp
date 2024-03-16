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

string to_binary(ll x) {
    string r;
    while (x) {
        r += (x % 2) + '0';
        x /= 2;
    }
    reverse(r.begin(), r.end());
    return r;
}

void solve() {
    ll a, b;
    cin >> a >> b;
    string x, y;
    x = to_binary(a);
    y = to_binary(b);
    ll t = (1ll << ((y.size()))) - 1;
    if (x.size() < y.size()) {
        if (t == b)cout << t << endl;
        else cout << (1ll << (y.size() - 1)) - 1 << endl;
    } else {
        if (b == t)cout << b << endl;
        else {
            ll r = 0;
            int c = 0;
            for (int i = 0; i < y.size(); i++) {
                if (x[i] == y[i]) {
                    r = r * 2 + x[i] - '0';
                    if (x[i] == '1')c++;
                } else {
                    r *= 2;
                    for (int j = i + 1; j < x.size(); j++) r = r * 2 + 1, c++;
                    break;
                }
            }
            if(__builtin_popcountll(a) > c) {
                c = __builtin_popcountll(a);
                r = a;
            }
            if(__builtin_popcountll(b) > c) {
                c = __builtin_popcountll(b);
                r = b;
            }
            cout << r << endl;
        }
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
