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
    int n;
    cin >> n;
    map<int, int> a[2];
    for (int i = 0, x, y; i < n; i++) {
        cin >> x >> y;
        a[y][x]++;
    }
    ll r = 0;
    for (auto [x, y]: a[0]) {
        if (a[1].count(x)) r += a[0].size() + a[1].size() - 2;
        if (a[1].count(x - 1) && a[1].count(x + 1)) r++;
    }
    for (auto [x, y]: a[1]) {
        if (a[0].count(x - 1) && a[0].count(x + 1)) r++;
    }
    cout << r << endl;
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
