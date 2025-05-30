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
    int n, d;
    cin >> n >> d;
    vector<pi> v(n);
    int s = 0, e = 0;
    for (auto &[x, y]: v)
        cin >> x >> y, s += x, e += y;
    if (s <= d && d <= e) {
        cout << "YES" << endl;
        for (auto [x, y]: v) {
            // i <= d - s + x
            // i >= d - e + y
            int k = max(x, d - e + y);
            cout << k <<" ";
            s -= x;
            e -= y;
            d -= k;
        }
    } else
        cout << "NO" << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
