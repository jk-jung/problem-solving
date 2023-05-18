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
    int n, k;
    cin >> n >> k;
    vi v(n), t;

    int st = 0, y = 0;
    for (int &x: v) {
        cin >> x;
        if (x % 2)st++;
        else st--;
    }
    if (st) {
        cout << 0;
        return;
    }
    for (int x: v) {
        if (st == 0) {
            t.pb(ab(x - y));
        }
        if (x % 2)st++;
        else st--;
        y = x;
    }
    t[0] = 9999999;
    sort(t.begin(), t.end());
    int r = 0;
    for (int x: t) {
        if (x <= k)r++, k -= x;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
