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
    ll n, s = 0;
    cin >> n;
    n += 2;
    vector<ll> v(n);
    for (ll &x: v)cin >> x, s += x;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        ll last = i == n - 1 ? n - 2 : n - 1;
        ll t = s - v[i] - v[last];
        if (t == v[last]) {
            for (int j = 0; j < n; j++) {
                if (j == i || j == last)continue;
                cout << v[j] <<" ";
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
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
