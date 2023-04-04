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
    int n, x, y, d;
    cin >> n >> x >> y >> d;

    x--, y--;
    if (ab(x - y) % d == 0)cout << ab(x - y) / d << endl;
    else {
        int r = 1 << 30;
        if (y % d == 0)r = min(r, y / d + (x + d - 1) / d);
        x = n - x - 1;
        y = n - y - 1;
        if (y % d == 0)r = min(r, y / d + (x + d - 1) / d);
        if (r == (1 << 30))r = -1;
        cout << r << endl;
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
