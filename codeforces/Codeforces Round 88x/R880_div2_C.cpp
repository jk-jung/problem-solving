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

int v[] = {
        0,
        1,
        10,
        100,
        1000,
        10000,
        100000,
        1000000,
        10000000,
};

void solve() {
    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    for (int x = v[a]; x < v[a + 1]; x++) {
        int y1 = max(v[b], v[c] - x);
        int y2 = min(v[b + 1], v[c + 1] - x);
        if (k <= y2 - y1) {
            int y = y1 + k - 1;
            cout << x << " + " << y << " = " << x + y << endl;
            return;
        } else {
            k -= max(0, y2 - y1);
        }
    }
    cout << -1 << endl;
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
