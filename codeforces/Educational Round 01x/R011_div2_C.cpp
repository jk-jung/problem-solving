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

    int s = 0, e = n, r = 0;
    vi rr = v;
    while (s <= e) {
        int m = (s + e) / 2;
        vi t = v;
        int cnt_0 = 0;
        bool ok = false;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0)cnt_0++;
            if (i >= m) {
                if (v[i - m] == 0)cnt_0--;
            }
            if (i >= m - 1 && cnt_0 <= k) {
                for (int j = i - m + 1; j <= i; j++)t[j] = 1;
                ok = true;
                break;
            }
        }
        if (ok)s = m + 1, r = m, rr = t;
        else e = m - 1;
    }

    cout << r << endl;
    for (int x: rr)cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
