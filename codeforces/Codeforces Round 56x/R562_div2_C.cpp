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
    int n, t;
    cin >> n >> t;
    vi v(n);
    for (int &x: v)cin >> x;

    int s = 0, e = t, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        bool ok = true;
        int last = 0;

        for (int i = 0; i < n; i++) {
            if (v[i] + m >= t) {
                if (last <= (v[i] + m) % t);
                else last = max(last, v[i]);
            } else if (v[i] + m < last) {
                ok = false;
                break;
            } else last = max(last, v[i]);
        }
        if (ok) e = m - 1, r = m;
        else s = m + 1;
    }
    cout << r << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
