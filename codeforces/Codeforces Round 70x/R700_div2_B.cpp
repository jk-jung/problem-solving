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
    ll A, B, n;
    cin >> A >> B >> n;
    ll t = 0;
    vector<pi> v(n);
    for (auto &[x, y]: v)cin >> x;
    for (auto &[x, y]: v)cin >> y;

    sort(v.begin(), v.end());
    for (ll i = 0, a, b; i < n; i++) {
        a = v[i].F;
        b = v[i].S;
        t += (b + A - 1) / A * a;
        if (t >= B) {
            if (i == n - 1) {
                if (t - a >= B) {
                    cout << "NO\n";
                    return;
                }
            } else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
