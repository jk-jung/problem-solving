#include <string.h>
#include <stdio.h>
#include <math.h>
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

int n, k;

int check(vi &v, int x) {
    int s = x, e = (int) v.size() - 1, r = 1 << 30;

    while (s <= e) {
        int m = (s + e) / 2;
        int in = v[m] - v[x - 1];
        int out = n - in;

        if (in >= out + k) r = m, e = m - 1;
        else s = m + 1;
    }
    return r;
}

void solve() {
    cin >> n >> k;
    vi v(n), s(n + 1);
    for (int &x: v)cin >> x, s[x]++;
    for (int i = 1; i <= n; i++) s[i] += s[i - 1];

    int r = 1 << 30, x, y;
    for (int i = 1; i <= n; i++) {
        int t = check(s, i);
        if (r > t - i) {
            r = t - i;
            x = i;
            y = t;
        }
    }

    cout << x << " " << y << '\n';

    int start = 0;
    for (int i = 0, in = 0, out = 0; i < n; i++) {
        if (x <= v[i] && v[i] <= y) in++;
        else out++;

        if (in > out && k != 1) {
            cout << start + 1 << " " << i + 1 << '\n';
            start = i + 1;
            in = out = 0;
            k --;
        }
    }
    cout << start + 1 << " " << n << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int test_case;
    cin >> test_case;
    while (test_case--)
        solve();
}
