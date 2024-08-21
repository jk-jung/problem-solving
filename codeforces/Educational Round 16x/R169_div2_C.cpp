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

void solve() {
    ll n, k;
    cin >> n >> k;
    vi v(n);
    for (int &x: v)cin >> x;
    sort(v.rbegin(), v.rend());

    ll dif = 0;
    for (int i = 0; i + 1 < n; i += 2) {
        dif += v[i] - v[i + 1];
    }
    dif -= min(dif, k);

    if (n % 2)dif += v.back();
    cout << dif << endl;
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
