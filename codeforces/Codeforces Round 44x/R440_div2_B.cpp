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
    vi v(n);
    for (int &x: v)cin >> x;
    if (k == 1) cout << *min_element(v.begin(), v.end()) << endl;
    else if (k == 2) {
        vi t(n);
        t.back() = v.back();
        for (int i = n - 2; i >= 0; i--)t[i] = min(t[i + 1], v[i]);
        int r = -(1 << 30);
        for (int i = 0, x = 1 << 30; i < n - 1; i++) {
            x = min(x, v[i]);
            r = max(r, max(x, t[i + 1]));
        }
        cout << r << endl;
    } else {
        cout << *max_element(v.begin(), v.end()) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}

