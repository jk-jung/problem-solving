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
    int r = 0;
    for (int &x: v) {
        cin >> x;
        r += x / 10;
        if (x % 10)t.pb(10 - x % 10);
    }
    sort(t.begin(), t.end());
    for (int x: t) {
        if (k >= x) {
            k -= x;
            r++;
        }
    }
    r = min(n * 10, r + k / 10);
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
