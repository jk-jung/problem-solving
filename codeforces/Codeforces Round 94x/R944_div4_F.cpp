#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back
#define F first
#define S second
#define ab(x) (((x) < 0) ? -(x) : (x))

ll n;

vi dis(ll x, ll y) {
    ll d1 = (n + 1) * (n + 1);
    ll d2 = n * n;
    vi r;
    while (x * x + y * y >= d1)x--;
    while (x >= 0 && x * x + y * y >= d2) {
        r.pb((int) x--);
    }
    return r;
}

void solve() {
    cin >> n;
    ll r = 0;
    ll x = n;
    for (int y = 1; y <= n; y++) {
        vi t = dis(x, y);
        r += t.size();
        x = t.back();
    }
    cout << r * 4 << endl;
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
