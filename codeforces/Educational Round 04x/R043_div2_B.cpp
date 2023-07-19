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
    ll n, m, k;
    cin >> n >> m >> k;
    if (k < n) {
        cout << k + 1 << " 1\n";
    } else {
        k -= n;
        ll x = k / (m - 1);
        ll y = k % (m - 1);
        if (x % 2 == 0) {
            cout << n - x << " " << y + 2 << endl;
        } else {
            cout << n - x << " " << m - y << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
