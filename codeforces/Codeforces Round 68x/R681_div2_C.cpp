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
    int n;
    cin >> n;
    vi a(n), b(n);
    for (int &x: b)cin >> x;
    for (int &x: a)cin >> x;

    int s = 1, e = 1 << 30, r = -1;
    while (s <= e) {
        int m = (s + e) / 2;
        bool ok = true;
        int ss = 0;
        for (int i = 0; i < n; i++) {
            if (b[i] > m)ss += a[i];
            if (ss > m) {
                ok = false;
                break;
            }
        }

        if (ok)e = m - 1, r = m;
        else s = m + 1;
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
