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
    vector<ll> v(n);
    for (ll &x: v)cin >> x;
    v[0] -= 1ll << 50;
    v[1] -= 1ll << 50;

    for (int i = 2; i < n; i++) {
        ll dif = v[i - 1] - v[i - 2];
        v[i - 1] -= dif;
        v[i] -= dif;
    }

    for (int i = 1; i < n; i++)
        if (v[i - 1] > v[i]) {
            cout << "NO\n";
            return;
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
