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
    ll n, x, y;
    cin >> n >> x >> y;
    ll k = y - n + 1;
    if (k <= 0) {
        cout << -1;
        return;
    }
    ll val = k * k + n - 1;
    if (val >= x) {
        cout << k << endl;
        for (int i = 1; i < n; i++)cout << 1 << endl;
    } else {
        cout << -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
